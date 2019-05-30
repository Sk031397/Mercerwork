#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

main(int argc, char *argv[])
{
// holds shar memory id
int  shmid;
// points to character 
char *ram;

/*****  Get Shared Memory and ID *****/

shmid  =  shmget(IPC_PRIVATE, 81*sizeof(char), 0777);
/*if give permissions fail */
if (shmid == -1)
    {
    printf("Could not get shared memory.\n");
    return(0);
    }
ram = (char *) shmat(shmid,NULL, SHM_RND);

strcpy(ram,"CSC 460 RAM location!!");

printf("The SHMID is: %d\nalldone\n", shmid);
}

