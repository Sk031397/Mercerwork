#include <stdio.h>

main()
{
int x = 3;
char c = 'A';
int num[10];
int *vals;
int i;
// loop through 10 times filling the array 
for (i=0;i<10;i++)
   num[i] = i*10;
// put the values of num into val
vals = num;
// print out x, c, num[3], *vals prints out the 1st value
printf("%d\t%c\t%d\t%d\n",x,c,num[3],*vals);
// points to next integer in array 
vals++;
printf("%d\t%c\t%d\t%d\n",x,c,num[3],*vals);
// increment to the next char
c++;
vals++;
printf("%d\t%c\t%d\t%d\n",x,c,num[3],*vals);

for (vals = num; vals < &(num[5]) ; vals++)
    printf("%d\n",*vals);

}








