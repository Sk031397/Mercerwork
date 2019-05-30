// Sahid Kebe
// CSC 460
// 1/23/19 
// Fork 2- Bad Synch Program 
#include <stdio.h> 

int main(int argc, char **argv)
{
	FILE *fopen(),*fp;
	// check to see if the file is writeable or not  
	if((fp = fopen("syncfile","w")) == NULL)
	{
		printf("could not open syncfile to open\n");
		return(0); 
	}
	// write the character A to the file 
	fprintf(fp,"%c",'A');
	fclose(fp); 
	int N ;
	// if an argument is included use it as N 
	if(argc > 1)	
		N = atoi(argv[1]); 
	// if not print it must be in the range in order to work 
	else
		printf("wrong\n"); 
	if( ( 26 < N) || (1 > N))
	{
		printf("Must be a number between 0 and 26\n"); 
	}
	// if the user enters in a number 
	else
	{
		printf("You entered the number %d\n",N); 
		char id = 'A';
		char found = 'a'; 
		int count = 1; 
		char otherId = 'B'; 
		// if the number is 1 make the otherId an A 
		if ( N == 1)
		{
			otherId = 'A'; 
		}
		int i,x;
		// loop through the the specified amount of number  
		for(i = 0; i < N-1;i++)
		{
			// make a child of each parent node 
			x = fork(); 
			// if a parent is  found break 
			if(x>0) break;
			// move to next character in the alphabet 
			id = otherId;
			// allows the otherId to increment to the next character ihe alphabet 
			otherId++; 
			// increment the counter variable keeping track of the amount of N 
			count++;
			// if the number of iterations has been reached, set the otherId to A  
			if(count==N)
			{
				otherId ='A'; 
			}
		}
		// loop through 5 times 
		for(i = 0; i < 5; i++)
		{
			found = 'a'; 
			// if an a is not found 
			while(found != id)
			{
				// check to see if the file can be read or not 
				if((fp = fopen("syncfile","r")) == NULL)
				{
					printf("could not open syncfile to read\n"); 
					return(0); 	
				}
				// read through the file 
				fscanf(fp,"%c",&found); 
				fclose(fp); 
			}
			// print out the process id 
			printf("%c: %d\n",id,getpid());
			// check to see if the file is writable 
			if((fp = fopen("syncfile","w")) == NULL)
			{
				printf("could not open syncfile to write to\n");
				return(0); 
			}
			// print out all the otherIds and close the file 
			fprintf(fp,"%c",otherId);
			fclose(fp);	
}
// have the program sleep for a second and then exit the program 
sleep(1);
return(0);
}
}
