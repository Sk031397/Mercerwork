#include "queue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <cstdlib>
#include <sstream>
#include <vector>
#include <climits>
#include <iomanip>
#include <stack>
#include <set>
#include <utility>
#include <algorithm> 
#include <queue> 
#include <cstring>
#include <algorithm> 
#include <cctype>
using namespace std;

#include "SeparateChaining.h"


struct VertexType
{
	string name;
	bool marked;
	int distance;
	string previous;	
};

void insertionSort(string cities[], int numVertices);
void checkInFile(int argc);
void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[]);
void printCities(Graph<string> dGraph, int numVertices, VertexType myVertices[], string cities[]);
string setStart(string start, int numVertices, VertexType myVertices[]);
void printRow(int location, VertexType myVertices[]);
int findMin(VertexType myVertices[], int numVertices);
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[]);
bool allMarked(int numVertices, VertexType myVertices[]);
int IndexIs(string s, VertexType myVertices[],int numVertices); 
void See(Graph<string> &dGraph,VertexType myVertices[],int &numVertices,string Vertex, string city[]); 


int main(int argc,char *argv[])
{
	checkInFile(argc);	// Checks to see if Filename is given

	// Creation of Input File:
	string filename = argv[1];

	Graph<string> dGraph; 
	int numVertices; 
	int numEdges; 
	VertexType myVertices [50];
	string cities [50]; 
	buildDGraph(dGraph, filename, cities, numVertices, numEdges, myVertices);	// Builds the Graph using the data from the external file.
  printCities(dGraph, numVertices, myVertices, cities);	// Prints Cities found in file
	dijkstra(dGraph, numVertices, myVertices);	// Computes Dijkstra's Algorithm:

}

// Checks to see if Filename is given:
void checkInFile(int argc)
{
  ifstream infile; 
   if(argc == 1) 
   {
     cout << "File does not exist" << endl; 
     exit(1); 
   }      
}
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[]){
  
  
string start; 
   start = setStart(start,numVertices,myVertices);  
    Queue<string>pq;
    bool cycle = false; 
    string acycle[numVertices]; 
    int count = 0; 
    cout << "------------------------------"<< endl; 
    cout << "\tVertex\t\tDistance\tPrevious"<< endl; 
    cout << endl; 
    
    int index = IndexIs(start,myVertices,numVertices); 
    myVertices[index].marked = true;

   myVertices[index].distance = 0;   
   myVertices[index].previous = "N/A";
   printRow(index,myVertices); 
   while(!allMarked(numVertices,myVertices) )
   {
   dGraph.GetToVertices(myVertices[index].name,pq);  
   while(!pq.isEmpty())
   { 
     string place = pq.dequeue(); 
     int op = IndexIs(place,myVertices,numVertices); 
     int weight = myVertices[index].distance + dGraph.WeightIs(myVertices[index].name,place); 
    
   if (weight < myVertices[op].distance)
 {
 myVertices[op].distance = weight;
 myVertices[op].previous = myVertices[index].name;

 }  
  }
  index = findMin(myVertices,numVertices);
  myVertices[index].marked = true;  

  printRow(index,myVertices);  
   } 
   //printRow(index,myVertices);  
    // index = findMin(myVertices,numVertices);
  /*   myVertices[index].marked = true; 
  if(findMin(myVertices,numVertices==-1))
  {
    if(!myVertices[index].marked) 
    { 
     cout << myVertices[index].name << "NOT A PATH" << "N/A"<< endl; 
    } 
  }*/ 
  //myVertices[index].marked = true;       
}
int IndexIs(string s,VertexType myVertices[],int numVertices)
{
  for(int p = 0; p < numVertices;p++)
  
  if(s == myVertices[p].name)
  
    return p;  
  }
// Checks to see if all Vertices have been marked:
bool allMarked(int numVertices, VertexType myVertices[])
{  
   for(int i = 0; i < 7; i++) 
     if(!myVertices[i].marked)
       return false; 
          return true; 
} 
// Builds the Graph using the data from the External File:
void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[])
{
             numVertices = 0; 
                 numEdges = 0; 
                  ifstream infile; 
                 string input;     
                  infile.open(filename.c_str());
                 if(!infile.is_open())
		{ cout << "Cannot Continue because file is incorrect"<< endl;
		  exit(1);  	
		} 
                 while(!infile.eof())
                 { 
                    getline(infile,input);  
                     //substrings the string in order to get rid of the first semicolon 
                     string b  = input.substr(0,input.find(";"));
                     // substring the string in order to get the rest of the string after the semicolon 
                     input = input.substr(input.find(";")+1,input.length());

                       //substrings the string in order to get rid of the second semicolon  
                     string e = input.substr(0,input.find(";"));
                     // substring the string in order to get the rest of the string after the semicolon 
                     input = input.substr(input.find(";")+1,input.length());
                     // convert what is after the second semicolon (which is an integer) to an integer 
                     int p = atoi(input.c_str());
                     // Trim the space
                      
                     b.erase(remove_if(b.begin(),b.end(),:: isspace),b.end()); 
                     e.erase(remove_if(e.begin(),e.end(),:: isspace),e.end());
                     
                     
                     See(dGraph,myVertices,numVertices,b,cities); 
                     See(dGraph,myVertices,numVertices,e,cities);
                     dGraph.AddEdge(b,e,p);
                    //infile.close(); 
                                                      
}


 }
/*
 @ param array of vertices of vertextype, number of vertices, and array of cities 
*/
void See(Graph<string> &dGraph, VertexType myVertices[],int &numVertices,string Vertex, string city[]){
bool check;  
 
for(int i = 0; i < numVertices;i++)

   if(city[i] == Vertex)
   {
      check = true; 
   } 
  // checking for duplicates 
    if(!check)
   {
   city[numVertices] = Vertex;
   myVertices[numVertices].name = Vertex; 
   myVertices[numVertices].marked = false; 
   myVertices[numVertices].distance = INT_MAX;
   myVertices[numVertices].previous = ""; 
   numVertices++; 
   dGraph.AddVertex(Vertex);  
} 

}

 //@ param array of vertices of vertextype, number of vertices, prints the vertices 

// Prints Cities found in External File:
void printCities(Graph<string> dGraph, int numVertices, VertexType myVertices[], string cities[])
{
insertionSort(cities,numVertices); 

   printf("^^^^^^^^^^^^^^^^ DIJKSTRA'S ALGORITHM ^^^^^^^^^^^^^^^^\n\n") ;  
   printf("A Weighted Graph Has Been Built For These %d Cities:\n\n",numVertices-1);
   for(int i = 0; i < numVertices; i++)
   {
     cout << "\t" << cities[i] << "\t";  
     if ( (i + 1) % 3 == 0 )
       cout << endl; 
       
   }
   cout << endl;   
}

// Sorts the Cities Alphabetically:
void insertionSort(string cities[], int numVertices)
{ 
   for( int p = 0; p < numVertices; p++ )
            {
/* 2*/          string tmp = cities[ p ];

                int j;
/* 3*/          for( j = p; j > 0 && tmp < cities[ j - 1 ]; j-- )
/* 4*/              cities[ j ] = cities[ j - 1 ];
/* 5*/          cities[ j ] = tmp;
            }
   } 

//Sets the Starting Value in Dijsktra's Algorithm:
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

// Finds the minimum non-marked values in VertexType Array:
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

// Prints a given row in a Summary Table:
void printRow(int location, VertexType myVertices[])
{
	if (myVertices[location].distance != -1)
	cout << setw(14) << myVertices[location].name << setw(18) << myVertices[location].distance << setw(16) << myVertices[location].previous << endl;
	else
	 cout << setw(14) << myVertices[location].name << setw(18) << "Not On Path" << setw(16) << myVertices[location].previous << endl;
}

