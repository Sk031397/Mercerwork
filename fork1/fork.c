//Sahid Kebe
//CSC 460
//1/16/19
//Fork I- C Program 


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	int x,i,N; // variables pre-defined in C 
	int Gen = 0; // number of generations originally set to 0   
	// if there is only one argument print out, put a range between 0-5. then exit 
	if (argc == 1){
	   printf("Please enter in a range from 0 to 5\n");
	   return 0;
	} 
	N = atoi(argv[1]);
	// if the range is not between 0 and 5, exit program 
  	if((N < 0) || (N > 5))
	{
	  printf("Please enter in a range from 0 to 5\n"); 
          exit(0); 
	}	
	printf("N: %d\n\n",N);	
	// print the header, currently here there is only 1 process running 
	printf("Gen\tPID\tPPID\n\n");
	// loop through depending on what the user set 
	// since there is already 1 main processes start the loop at 1 
	for(i = 1; i <=N; i++)
	{
		// fork a process for each N., creating a branch of nodes of processes  
		x = fork(); 
		// if the child process is 0, increment the generation, rest the loop and decrement the amount of times it loops 
		if(x == 0)
		{
			Gen++; 
			i = 0; 
			N--; 
		}
	}
	// print the amount of generation, process id along with parent process id 
	printf("%d\t%d\t%d\n",Gen,getpid(),getppid());
	// let the system sit for a second before get the next process and parent process id's 
	sleep(1);
	return 0; 
}
