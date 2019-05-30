#include<iostream>
#include "linelist.h"

LineList::LineList() //This includes some variables for the basic LineList object
{
LineNode *line = new LineNode;
LineNode *line2 = new LineNode;

line -> info = topMessage; //The top buffer
currLine = line;
currLineNum = 1;
length = 0;
line2 -> info = bottomMessage; //The bottom buffer
currLine -> back = NULL;
currLine -> next = line2;
line2 -> back = line;
line2 -> next = NULL;
}

void LineList::goToTop() //This takes the user to the top of the code without entering the buffer
{
// Post : Advances currLine to line 1
while(currLine->back->info!=topMessage)
{
currLineNum--;
currLine=currLine->back;
}
currLine=currLine->next;
currLineNum++;
}

void LineList::goToBottom() //This takes the user to the bottom of the code
{
// Post : Advances currLine to last line
while (currLine->next->info !=bottomMessage)
{
currLine=currLine->next;
currLineNum++;
}
currLine=currLine->back;
currLineNum--;
}

void LineList::insertLine(string newLine) {
// post : newLine has been inserted after the current line
LineNode *temp = new LineNode;
temp->info=newLine;
temp->next=currLine->next;
temp->back=currLine;
currLine->next=temp;
temp->next->back=temp;
currLine=temp;
length++;
currLineNum++;
}

void LineList::deleteLine() {
// post : deletes the current line leaving currentLine
//
// pointing to line following

if(length!=0)
{
LineNode *temp=new LineNode;
temp = currLine->next;
currLine->back->next=currLine->next;
currLine->next->back=currLine->back;
delete currLine;
currLine=temp;
length--;
if(currLine->info==bottomMessage)
{
currLine=currLine->back;
currLineNum--;
}
}
}

void LineList::printList() //This goes to the top of the code and prints it, if there is nothing to print it will say that the list is empty
{
LineNode *temp = currLine;
int LineNum = 1;
if(length!=0)
{
while(temp->back->back != NULL)
temp= temp->back;

while(temp->next!=NULL)
{
cout<<LineNum<<"> "<<temp->info<<endl;
temp= temp->next;
LineNum++;
}
LineNum=currLineNum;
}

}

string LineList::getCurrLine() const //This gets the information from the currentline pointer
{
return currLine->info;
}

void LineList::moveNextLine() {
// Post : Advances currLine (unless already at last line)
if(currLine->next->info!=bottomMessage)
{
currLine= currLine->next;
currLineNum++;
}
}

void LineList::movePrevLine() {
// Post : Advances currLine (unless already at last line
  if(currLine->back->info!=topMessage)
{
currLine=currLine->back;
currLineNum--;
}

int LineList::getCurrLineNum() const //This gets the current line number as compared to the numbers around it
{
return currLineNum;
}

int LineList::getLength() const //This gets the total length of the list
{
return length;
}
