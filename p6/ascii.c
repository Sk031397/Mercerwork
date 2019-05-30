#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *file;
	FILE *output; 	
	int row = 1;
	int col = 1;  
	int ch; 
	file = fopen("ASCIIart.txt","r");
	if(file == NULL)
	{
	   printf("Error!Could not find File");
	   exit(1);
	}
	while( (ch = fgetc(file))  != EOF)
	{
	  if(ch != '\n')
	  {
		printf("db 1bh, \"[%02d;%02dH%c\"\n",row,col,ch);  
		col++;   
	  }
	  else { 
	  row++;
	  col = 0;
		} 
	}
	fclose(file);

	return 0; 
}	
