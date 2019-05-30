//Sahid Kebe 
//csc460	
//3/13/19- done on my birthday
//allowing each philospher to pick up and use a chopstick 

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <time.h>
//variables that are defined that will be used later in the program 
#define N         5
#define THINKING  0
#define HUNGRY    1
#define EATING    2
#define DEAD      9
#define LEFT      ((i+1)%N)
#define RIGHT     ((i-1)%N)
 
int main()
{
	int *state, *t;
	int arrayID, ptime;
	int phnum = 0;
	srand(time(NULL));
	int chops;
	int x = 0, i;
	int pid = getpid();
	
	/*****  Get Shared Memory and ID *****/
	arrayID  =  shmget(IPC_PRIVATE, N*sizeof(int), 0777);
	ptime = shmget(IPC_PRIVATE, 100*sizeof(int), 0777);
	/****   Attach to the shared memory  ******/
	state = (int *) shmat(arrayID, NULL, SHM_RND);
	t = (int *) shmat(ptime, NULL, SHM_RND);

	for(i = 0; i < N; i++)
		state[i] = THINKING;
	for(i = 0; i < 100; i++)
		t[i] = i++;

	//Asks for semaphores 
	chops = semget(IPC_PRIVATE, 6, 0777);
	//  See if you got the request.
	if (chops == -1)
   	{
    		printf("%s","Chopsticks Failed.\n");
    		return (-1);
   	}
	//  Initialize your sems.
	//semctl(chops, 0, SETVAL, 0);
	//semctl(chops, 1, SETVAL, 0);
	//semctl(chops, 2, SETVAL, 0);
	//semctl(chops, 3, SETVAL, 0);
	//semctl(chops, 4, SETVAL, 0);
	for(i=0;i<N-1;i++)
	{
		semctl(chops,i,SETVAL,0);
	}
	semctl(chops, 5, SETVAL, 1);
	//Forks to make 5 philosophers and one mutex
	for(i = 0; i<N; i++)
	{
		if(fork() == 0)
		{
			break;
		}
		phnum++;
	}
	//Checks if Child process
	if(getpid() != pid)
	{
		//Loops until 100 seconds is reached then each process dies
		while(*t < 99)
		{
				think(i, state);
				state[i] = HUNGRY;
				takeForks(i,chops, state);	
				eat();
				putForks(i, chops, state);
		}
	}
	//Checks if parent process
	else if(pid == getpid())
	{/* as long as the states are not DEAD */
		while(state[0] != DEAD || state[1] != DEAD || state[2] != DEAD || state[3] != DEAD || state[4] != DEAD)
		{
			printf("%d. \t",*t);
			// loop through N times 
			for(i = 0; i<N; i++)
			{
				if(*t > 100)
					die(i, state);
				else if(state[i] == THINKING)
                        	{
                                	printf("%-15s","THINKING");
                        	}
                        	else if(state[i] == HUNGRY)
                        	{
                                	printf("%-15s","HUNGRY");
                        	}
                       		else if(state[i] == EATING)
                        	{
                                	printf("%-15s","EATING");
                        	}
			}
			*t+=1;
			sleep(1);
			printf("\n");
		}
		printf("Cleaning up sems and shared mem...\n");
		sleep(4);
		//Cleans up shared memory
		if ((shmctl(ptime, IPC_RMID, NULL)) == -1)
    			printf("ERROR removing shmem.\n");
		if ((shmctl(arrayID, IPC_RMID, NULL)) == -1)
    			printf("ERROR removing shmem.\n");
		// Parent needs to clean up semaphores.
    		if ((semctl(chops, 0, IPC_RMID, 0)) == -1)
       			printf("%s", "Parent: ERROR in removing sem\n");
		printf("All Done\n");
	}
	return 0;
}
//Method to pick up chopsticks
takeForks(int i, int chopsticks, int *state)
{
	p(5, chopsticks);
	test(i, chopsticks, state);
	v(5, chopsticks);
	p(i, chopsticks);
}
//Method to put chopsticks down
putForks(int i,int chopsticks,int *state)
{
	p(5, chopsticks);
	state[i] = THINKING;
	test(LEFT, chopsticks, state);
	test(RIGHT, chopsticks, state);
	v(5, chopsticks);
}
//Makes sure it can have both chopsticks
test(int i, int chopsticks, int *state)
{
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
	{
		state[i] = EATING;
		v(i, chopsticks);
	}
}
//Method to kill philosophers
die(int i, int *state)
{
	if(state[i] == THINKING)
	{
		state[i] = DEAD;
		printf("%-15s","DEAD");
	}
	else if(state[i] == HUNGRY)
	{
		printf("%-15s","DEAD");
	}
	else if(state[i] == EATING)
	{
		printf("%-15s","EATING");
	}
	else
		printf("%-15s","DEAD");
}
//Method to waste CPU
think(int i, int *state)
{
	int j = (rand()%(15-5)) + 5;
	sleep(j);
	state[i] = HUNGRY;
}
//Method to waste CPU
eat()
{
	int j = (rand()%(3-1)) + 1;
	sleep(j);
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
