#include <stdio.h>

main(int argc, char *argv[])
{
FILE *fopen(), *fp;
int  fav = 460;
int  favNumber = 0;
int  i = 0;


/*****  Open File to write a value  *****/

if((fp = fopen("myLittleFile","w")) == NULL)
    {
    printf(":( could not open myLittleFile to write.\n");
    return(0);
    }

/*****  Write message into myLittleFile *****/

fprintf(fp,"%d",fav);
fclose(fp);

/*****  Mess around a while doing other stuff.... *****/

for (i=0;i<10;i++)
	printf(".");

/*****  Open File to read a value  *****/

if((fp = fopen("myLittleFile","r")) == NULL)
    {
    printf(":( could not open myLittleFile to read.\n");
    return(0);
    }

/*****  Read favorite number and close file  *****/

    fscanf(fp,"%d",&favNumber);
    fclose(fp);

/****   Display the favorite number and die.  ******/

    printf("Your favorite number is: %d\n\n",favNumber);
    return(0);

}
