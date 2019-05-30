#include <stdio.h>
int main()
{
int a;

printf("Hello!!!\n");
// process id, along with parent process id 
printf("A\tPID\tPPID\n\n");
// two copies of processes
a = fork();
// two lines of output 
printf("%d\t%d\t%d\n",a,getpid(),getppid());

sleep(1);

printf("Bye!!!\n");

sleep(1);
return 0;
}

