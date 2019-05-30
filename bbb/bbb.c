// Sahid Kebe
// csc460 
// 4/3/2019
//simulate OS with processes 

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <time.h>

#define DEAD 9
//Struct given to each individual process
struct process
{
	int pid;
	int clock;
	int request;
	int remaining;
};

int main(int argc, char *argv[])
{
	//Assigns default to struct values
	struct process disp;
	disp.pid = getpid();
	disp.clock = 0;
	disp.request = 0;
	disp.remaining = 0;

	FILE *fopen(), *fp;
	int timeslice;
	int x = 0;
	int ptime, shmem;
	int *t, *user, *c;
	srand(time(NULL));
	int full, empty, mutex;
	int i, temp;
	int pid = getpid();
	// checks to see if argument is included 
	if(argc > 1)
		timeslice = atoi(argv[1]);
	else
		timeslice = 1;
	if((fp = fopen("Dispatcher","w")) == NULL)
    	{
    		printf("start:  could not open file.\n");
    		return(0);
    	}

	/*****  Give everyone permission to read file.  *****/
	system("chmod 755 Dispatcher");
	/*****  Get Shared Memory and ID *****/
	shmem  =  shmget(IPC_PRIVATE, 5*sizeof(struct process), 0777);
	ptime = shmget(IPC_PRIVATE, sizeof(int), 0777);
	/****   Attach to the shared memory  ******/
	user = (int *) shmat(shmem, NULL, SHM_RND);
	t = (int *) shmat(ptime, NULL, SHM_RND);
	//Asks for semaphores- ones used in bounded buffer 
	full = semget(IPC_PRIVATE, sizeof(int), 0777);
	mutex = semget(IPC_PRIVATE, sizeof(int), 0777);
	empty = semget(IPC_PRIVATE, sizeof(int), 0777);
	//  See if you got the request.
	if (full == -1)
   	{
    		printf("%s","full Failed.\n");
    		return (-1);
   	}
	if (mutex == -1)
   	{
    		printf("%s","mutex Failed.\n");
    		return (-1);
   	}
	if (empty == -1)
   	{
    		printf("%s","empty Failed.\n");
    		return (-1);
   	}
	//Initialize the semaphores- used in shared bounded buffer
	semctl(full, 0, SETVAL, 0);
	semctl(empty, 0, SETVAL, 5);
	semctl(mutex, 0, SETVAL, 1);
	t[0] = 0;
	for(x=0;x<4;x++)
	{
		if(fork()==0) break;
	}
	//stores everything to file
	fprintf(fp,"%d\n",shmem);
	fprintf(fp,"%d\n",user);
	fprintf(fp,"%d\n",ptime);
	fprintf(fp,"%d\n",t);
	fprintf(fp,"%d\n",full);
	fprintf(fp,"%d\n",empty);
	fprintf(fp,"%d\n",mutex);

	printf("Lets Begin Simulation!!!\n");
	while(x == 0)
	{
		fflush(stdout);
		printf("%d ",t[0]);
		p(x,empty);
		p(x,mutex);
		printf("\t\tCPU receives request for %d from %d",disp.request,disp.pid);
		if(timeslice > disp.request)
			sleep(disp.request);
		else
			sleep(timeslice);
		printf("\t\tCPU Finished request for %d from %d\n",disp.request,disp.pid); 
		v(x,mutex);
		v(x,full);
		printf("\n");
		sleep(1);
		t[0]++;
		
	}

	return 0;
}

p(int s,int sem_id)
{
struct sembuf sops;

sops.sem_num = s;
sops.sem_op = -1;
sops.sem_flg = 0;
if((semop(sem_id, &sops, 1)) == -1) printf("%s", "'P' error\n");
}

v(int s, int sem_id)
{
struct sembuf sops;

sops.sem_num = s;
sops.sem_op = 1;
sops.sem_flg = 0;
if((semop(sem_id, &sops, 1)) == -1) printf("%s","'V' error\n");
}

