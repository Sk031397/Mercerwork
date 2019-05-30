#include "graph.h"
#include <queue>
#include <string> 
#include <iostream>
#include <climits>   
#include <cstdio>
using namespace std; 

struct VertexType
{
	string name;
	bool marked;
	int distance;
	string previous;	
};
string setStart(string start, int numVertices, VertexType myVertices[]);
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[]);
int IndexIs(string s, VertexType myVertices[],int numVertices); 
int findMin(VertexType myVertices[], int numVertices);
bool allMarked(int numVertices, VertexType myVertices[]);
 int main()
 {
 	Graph<string> dGraph; 
	int numVertices;
	int numEdges;
	VertexType myVertices [50];
	string cities [50];
 
    dijkstra(dGraph,numVertices,myVertices); 
    return 0; 
 } 
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[])
{  
   string start; 
   //start = setStart(start,numVertices,myVertices);  
    Queue<string>pq;
    bool cycle = false; 
    //string acycle[numVertices]; 
    int count = 0; 
    cout << "------------------------------"<< endl; 
    cout << "\tVertex\t\tDistance\tPrevious"<< endl; 
    cout << endl; 
    
    int index = IndexIs(start,myVertices,numVertices); 
    myVertices[index].marked = true;

   myVertices[index].distance = 0;   
   myVertices[index].previous = "N/A";
   //printRow(index,myVertices); 
   cout << "\t" << myVertices[index].name << "\t\t" << myVertices[index].distance << "\t\t" << myVertices[index].previous << endl; 
    
    //cout << "Before loop"<<endl;  
   //while(!allMarked(numVertices,myVertices) )
   //{
   //cout << "while loop"<<endl;  
   //dGraph.GetToVertices(myVertices[index].name,pq); 
   //cout << "Before loop2"<<endl;  
   //while(!pq.isEmpty())
   //{
     //cout << "while loop2"<<endl;  
     //string place = pq.dequeue(); 
     //int op = IndexIs(place,myVertices,numVertices); 
     //cout << "name"<<endl; 
    // int weight = myVertices[index].distance + dGraph.WeightIs(myVertices[index].name,place); 
    
 //} 
 /* else if (weight < myVertices[op].distance)
 {
 myVertices[op].distance = weight;
 myVertices[op].previous = myVertices[index].name;

 } */ 
  //}
  //index = findMin(myVertices,numVertices);
  myVertices[index].marked = true;  
    //cout << "Fire3"<<endl;
    }
   
   
int IndexIs(string s,VertexType myVertices[],int numVertices)
{
  for(int p = 0; p < numVertices;p++)
  
  if(s == myVertices[p].name)
  
    return p;  
  }

int findMin(VertexType myVertices[], int numVertices)
{
 		int minWeight = INT_MAX - 1;
                int minThing = -1;
		for (int i = 0; i < numVertices; i++)
                {
                        if (myVertices[i].distance < minWeight && !myVertices[i].marked)
                        {
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }
			 if (myVertices[i].distance == minWeight && !myVertices[i].marked)
        		{
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }

		}        
		return minThing;
}
string setStart(string start, int numVertices, VertexType myVertices[])
{
	cout << " Please input your starting vertex: ";
	string response;
	getline(cin,response);
	bool isThere = false;
	for (int i = 0;	i < numVertices; i++)
	{
		if (myVertices[i].name.compare(response) == 0)
		{
			start = response;
			return start;
		}
	}
	while (!isThere)
	{
		cout << " Starting location does not exist..." << endl;
		cout << " Please input your new vertex: ";
        	string response;
        	cin >> response;
		for (int i = 0; i < numVertices; i++)
        	{
                	if (myVertices[i].name.compare(response) == 0)
			{
                        	start = response;
                        	return start;
                	}
        	}
	}
}
bool allMarked(int numVertices, VertexType myVertices[])
{
     
   for ( int i = 0; i < numVertices;i++)
   
     if(!myVertices[i].marked)
      {
      return false;
      }  
   return true; 
   
}