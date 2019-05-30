#include "huffman.h"
#include <iostream>
#include <climits> 
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, 0, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}

bool HuffmanTree:: inTree(char ch) {
 for ( int i = 0; i < numChars; i++) 
{ 
  if (ch ==nodes[i].ch) {
   return true;
   }
   return false; 
}
	} 
int HuffmanTree:: GetFrequency(char ch) {
   return GetFrequency(lookUp(ch)); 
}

int HuffmanTree:: GetFrequency(int i) {
   return nodes[i].weight; 
}

int HuffmanTree:: lookUp(char ch) {
   for ( int i = 0; i < numChars; i++) 
   { 
     if ( ch == nodes[i].ch) 
   { 
    return i;     
   }
    return -1;  
}
	} 
string HuffmanTree:: GetCode(char ch) {
  return GetCode(lookUp(ch)); 
}


string HuffmanTree:: GetCode(int i) {
if (nodes[i].parent == 0)
          return "";
        else
          return (GetCode(nodes[i].parent) + (char)(nodes[i].childType+'0')); 
}

void HuffmanTree:: PrintTable () const
{
     int count = 0;

     cout << "\n\t## ENCODING TABLE FOR ZIP FILE ##\n\n";
     cout << "\tIndex\tChar\tWeight\tParent\tChildType\n\n";

     for (int i = 0;  i < numChars; i++) {
      cout << "\t" << i;
      if ( (nodes[i].ch != '\n') && (nodes[i].ch != '\t') &&
           (nodes[i].ch != ' ') && (nodes[i].ch != '\0') )
       cout << "\t" << nodes[i].ch;
      else if ( (nodes[i].ch == '\n') )
       cout << "\tnl";
      else if ( (nodes[i].ch == '\t') )
       cout << "\ttab";
      else if ( (nodes[i].ch == ' ') )
       cout << "\tsp";
      else if ( (nodes[i].ch == '\0') )
       cout << "\tT" << ++count;

      cout << "\t" << nodes[i].weight;
      cout << "\t" << nodes[i].parent;

      if (nodes[i].parent != 0)
        cout << "\t" << nodes[i].childType << endl;
      else
        cout << "\tN/A" << endl;  }

      cout << endl;
}

int HuffmanTree:: numNodes() {
  return numChars; 
}

void HuffmanTree:: build() {
	int cap = (numChars*2) - 1;
	while(cap > numChars)
	{
		int smallest;
		int min1;
		smallest = INT_MAX;
		for(int i = 0; i < numChars; i++)
		{
			if(nodes[i].parent == 0 && nodes[i].weight < smallest)
			{
				min1 = i;
				smallest = nodes[i].weight;
			}
		}
		int min2;
		smallest = INT_MAX;
		for(int j = 0; j < numChars; j++)
		{
			if((nodes[j].parent == 0) && (nodes[j].weight < smallest) && (j != min1))
			{
				min2 = j;
				smallest = nodes[j].weight;
			}
		}
		HNode temp = {'\0',(nodes[min1].weight + nodes[min2].weight),0,-1};
		nodes.push_back(temp);
		nodes[min1].parent = nodes.size() - 1;
		nodes[min1].childType = 0;
		nodes[min2].parent = nodes.size() - 1;
		nodes[min2].childType = 1;
		numChars++;
	}
	nodes[nodes.size() - 1].parent = 0;
	built = true;
}
  
