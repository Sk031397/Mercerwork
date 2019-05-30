//Sahid Kebe
//2-13-2019
//csc460
//takes the user fav Num and puts in shared memroy 
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

struct bbStruct
{
        int id;
        char name[20];
        int favNum;
        char favFood[30];
};

main(int argc, char *argv[])
{
int shmid,i;
struct bbStruct *shmem;
FILE *fopen(), *fp;
int num = atoi(argv[1]);

/*****  Open File to hold Shared Memory ID  *****/

if((fp = fopen("/tmp/allen/csc460/bb/BBID.txt","r")) == NULL)
    {
    printf("watch:  could not open file.\n");
    return(0);
    }
if(argc < 2)
{
	printf("die\n");
	return(0);
}

/*****  Get Shared Memory ID and close file  *****/

    fscanf(fp,"%d",&shmid);
    fclose(fp);

/****   Attach to the shared memory  ******/

shmem = (struct bbStruct *) shmat(shmid, NULL, SHM_RND);

printf("\n\nHERE IS OUR SHARED MEMORY:\n\n");
for (i=0;i<21;i++)							//Goes through entire shmem to check for my name then changes num value and prints
    {
	if(strcmp(shmem->name, "Kebe, Sahid") == 0)			//Checks for my name and if found goes to the favNum
		shmem -> favNum = num;
	
       printf("%2d: %20s| %8d| %30s|\n",shmem->id,shmem->name,shmem->favNum,shmem->favFood);
       shmem++;
    }
printf("\n\n");
}
