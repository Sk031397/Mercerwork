//Sahid Kebe
//2-25-19
//csc460
//all the kirbys at the table eat,think or are hungry 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int chopstixs;
	int num = 0, x = 0, i,j;
	int N = 5;
	int HowManySems = 5; 
	//Asks for semaphores 
	chopstixs = semget(IPC_PRIVATE, HowManySems, 0777);
	//  See if you got the request.
	if (chopstixs == -1)
   	{
    		printf("%s","Chopsticks Failed.\n");
    		return (-1);
   	}
	//  Initialize your sems.
	for(i = 0; i < N; i++)
	{
		semctl(chopstixs,i,SETVAL,1);
	}
	//semctl(chopsticks, 0, SETVAL, 1);
	//semctl(chopsticks, 1, SETVAL, 1);
	//semctl(chopsticks, 2, SETVAL, 1);
	//semctl(chopsticks, 3, SETVAL, 1);
	//semctl(chopsticks, 4, SETVAL, 1);
	//Forks to make 5 philosophers
	for(i = 1; i<N; i++)
	{
		if(fork() != 0)
			break;
		// increments to the next philospher 
		num++;
		// if the number of philosphers equals 4, reset to the 1st philsopher 
	/*	if(num > 4)
			num = 0; */
	}
	
	//Infinite loop
	while(x == 0)
	{
		think(num);
		for(i = 0; i<=99999; i++) {
		for(j = 0; j<=99999;j++) {}
		}		//Loop to waste time
		hungry(num);	// are you hungry or nah?????
		p((num+1)%5, chopstixs); //Picks up left chopstick
		p(num, chopstixs);				//Picks up right chopstick				
		eat(num); // you better eat the food kirb kirb 
		for(i = 0; i<=99999; i++) 
		{
			for(j=0; j <=99999;j++){}
		}		
		//Loop to waste time
		v((num+1)%5, chopstixs);			//ayy fam stop eating put down the chopstix
		v(num, chopstixs);				//okay so you put down one chopstix so put the other one fat boi 
	}

	return 0;
}
//Method used to print Thinking with phnum # of tabs
think(int phnum)
{
	if(phnum == 0)
		printf("%d Thinking\n",phnum);
	else if(phnum == 1)
		printf("\t%d Thinking\n",phnum);
	else if(phnum == 2)
		printf("\t\t%d Thinking\n",phnum);
	else if(phnum == 3)
		printf("\t\t\t%d Thinking\n",phnum);
	else
		printf("\t\t\t\t%d Thinking\n",phnum);
}
//Method to print Hungry phnum # of tabs
hungry(int phnum)
{
        if(phnum == 0)
                printf("%d Hungry\n",phnum);
        else if(phnum == 1)
                printf("\t%d Hungry\n",phnum);
        else if(phnum == 2)
                printf("\t\t%d Hungry\n",phnum);
        else if(phnum == 3)
                printf("\t\t\t%d Hungry\n",phnum);
        else
                printf("\t\t\t\t%d Hungry\n",phnum);
}
//Method to print Eat phnum # of tabs
eat(int phnum)
{
        if(phnum == 0)
                printf("%d Eating\n",phnum);
        else if(phnum == 1)
                printf("\t%d Eating\n",phnum);
        else if(phnum == 2)
                printf("\t\t%d Eating\n",phnum);
        else if(phnum == 3)
                printf("\t\t\t%d Eating\n",phnum);
        else
                printf("\t\t\t\t%d Eating\n",phnum);
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
