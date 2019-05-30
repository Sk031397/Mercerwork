//Sahid Kebe
//2/5/19
//csc460
//using shared memory to print out popo and nana 
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
main(int argc, char * argv[])
{

	FILE *fopen(),*fp;
	int N = 0,i;
	if(argc == 1)
	{
		printf("No arguments entered. Enter in a value between 1-100\n");
		scanf("%d",&N);
	}
	else
	{
	 N = atoi(argv[1]);
	}
	if(N < 1 || N > 100)
	{
		printf("\n\n\nThe range is 1-100\n\n\nTryagain\n\n");
		exit(1);
	}
	/*if((fp = fopen("syncfile","w"))==NULL)
	{
		printf("could not open file");
		return(0);
	} 
	 write into file 
	fprintf(fp,"%d",1);
	fclose(fp);
	*/
	/**** Create child process and give **/
	int x,iter,here=1,next=1,icepa=1,proc,shmem,change;
	char * ram;
	shmem = shmget(IPC_PRIVATE,sizeof(char),0777);
	
	if(shmem == -1)
	{
		printf("could not retrieve the shared memory...\n");
		exit(1);
	}
	ram = (char *) shmat(shmem,NULL,SHM_RND);
	for(iter = 0; iter < (10*N-1); iter++)
	{
	    x = fork(); // fork process
	    if(x!=0)
               break;
	   // keep track of the changing process
	    change = proc;
	    // asiggn 1-N process
	    icepa = 1-icepa;
	    here = next;
	    // if icepa ids 0, go to next process
	    if(icepa == 0)
	        next++;
	    if(N < next)
		next = 1;
	}
	    proc = N;
	/*    while(here != proc)
	    {
		if((fp = fopen("syncfile","r")) == NULL)
		{
			printf("could not open file\n");
			return(0);
		}
		fscanf(fp,"%d",&proc);
		fclose(fp);
            }*/
	// icepa is 1 print parent 
	if(icepa == 1)
	{
	   printf("Popo%d\n",here);
	}
	// icepa is 0 print child 
	else
	   printf("Nana%d\n",here);
	/*if((fp = fopen("syncfile","w")) == NULL)
	{
	   printf("could not open file\n");
	   return(0);
	}*/
}
