#include <stdio.h>
#include <stdlib.h>

main()
{
  int *first, *second, *combined;
  int size1, size2;
  int i;
  
/////////////////   Build a First Array //////////////////////////
  printf("How many integers in the first array? ");
  scanf("%d",&size1);
  // allocates memory for the amound of ints 
  first = (int*) malloc(size1*sizeof(int));
  // loop the amount of times the user entered 
  for (i=0; i<size1; i++)
	// assigns the locations in memory multiples of 2
	first[i] = i*2;
	// print array 
  printf("First Array\n");
  for (i=0; i<size1; i++)
	printf("%d ",first[i]);
  printf("\n\n");

//////////////////   Build a Second Array  ////////////////////

  printf("How many integers in the second array? ");
  scanf("%d",&size2);
  // allocates memory for the amount of ints that a variable can hold 
  second = (int*) malloc(size2*sizeof(int));
  // put sequential numbers starting at 100 in each memory address of second
  for (i=0; i<size2; i++)
	second[i] = 100 + i;

  printf("Second Array\n");
  for (i=0; i<size2; i++)
	printf("%d ",second[i]);
  printf("\n\n");


/////////////////  Build a Combined Array  ////////////////////
// allocates memory to hold space for size1 and size 2
  combined = (int*) malloc((size1+size2)*sizeof(int));
  // add the multipes of two into the array 
  for (i=0; i<size1; i++)
	combined[i] = first[i];
  // add the remaining numbers into the combined array 
  for (i=0; i<size2; i++)
	combined[size1 + i] = second[i];

  printf("Combined Array\n");
  for (i=0; i<(size1+size2); i++)
	printf("%d ",combined[i]);
  printf("\n\n");
}








