// lists.c   example using structs

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct myList
{
int	amt;
struct myList *next;
};  /////// NOTE THE semicolon!

void printList(struct myList *ptr);
void addNode(struct myList **ptr, int amt);

int main(int argc, char *argv[])
{
// make a pointer the the struct 
struct myList *front = NULL;
printf("Here's the list\n");
printList(front);
// add five nodes to the list 
addNode(&front,460);
addNode(&front,461);
addNode(&front,462);
addNode(&front,463);
addNode(&front,464);
printf("Here's the list\n");
printList(front);

}
/* while the pointer the struct is not the front position, print out the values and go to next value 
 */
void printList(struct myList *ptr)
{
  while(ptr != NULL)
  {
    printf("%d\n", ptr->amt);
    ptr = ptr->next;
  }

}
/* add a node to the list 
 */
void addNode(struct myList **ptr, int amt)
{
   // allocate memory that is equal to the size of myList 
   struct myList *tmptr = *ptr; 
   struct myList *newguy = (struct myList *) malloc(sizeof(struct myList));
   newguy->amt = amt;
   newguy->next = NULL;
   if(*ptr == NULL)
   {
	*ptr = newguy;
   }
   else
{
	while(tmptr->next != NULL)
	
		tmptr = tmptr->next; 
	
}


}




