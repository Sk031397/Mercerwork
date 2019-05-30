// struct1.c   example using structs

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct myVals
{
int	pid;
int	amt;
char	name[25];
};  /////// NOTE THE semicolon!

int main(int argc, char *argv[])
{
struct myVals rec1;
struct myVals rec2;
struct myVals *rec3; // NOTE: Its a pointer to a struct.
// set the pid field from the rec1 struct == processid 
rec1.pid = getpid();
// sets the amt for rec1 = 123
rec1.amt = 123;
// copy the name Jesse into rec1 name, the char copied it must be at most 25
strcpy(rec1.name,"Jesse");
// rec2.pid = parent process id 
rec2.pid = getppid();
rec2.amt = 246;
strcpy(rec2.name,"Mercer");
// rec3 = address of rec1, meaning it points to info in rec1
rec3 = &rec1;

printf("FIRST VIEW:\n");
printf("R1: %d\t%d\t%s\n",rec1.pid,rec1.amt,rec1.name);
printf("R2: %d\t%d\t%s\n",rec2.pid,rec2.amt,rec2.name);
printf("R3: %d\t%d\t%s\n",rec3->pid,rec3->amt,rec3->name);
// the amt of rec3 is the addition of rec1 amt and rec2 amt 
rec3->amt = rec1.amt + rec2.amt;

printf("\nSECOND VIEW:\n");
printf("R1: %d\t%d\t%s\n",rec1.pid,rec1.amt,rec1.name); 
printf("R2: %d\t%d\t%s\n",rec2.pid,rec2.amt,rec2.name);
printf("R3: %d\t%d\t%s\n",rec3->pid,rec3->amt,rec3->name);
// allocates memory for the struct  
rec3 = (struct myVals *) malloc(sizeof(struct myVals));
rec3->pid = 99999;
rec3->amt = 1000;
strcpy(rec3->name,"The Bear");

printf("\nTHIRD VIEW:\n");
printf("R1: %d\t%d\t%s\n",rec1.pid,rec1.amt,rec1.name);
printf("R2: %d\t%d\t%s\n",rec2.pid,rec2.amt,rec2.name);
printf("R3: %d\t%d\t%s\n",rec3->pid,rec3->amt,rec3->name);

}






