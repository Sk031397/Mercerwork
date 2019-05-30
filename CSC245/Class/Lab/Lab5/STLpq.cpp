#include<iostream>
#include<queue> 
#include<string> 
using namespace std;
	void insert(priority_queue<string>&pq); 
	  void print(priority_queue<string>pq);

 
	int main(){
	  priority_queue<string> pq; 
     insert(pq); 
     print(pq); 
	   return 0; 
		} 	
	void insert(priority_queue<string>&pq) 
	{ 
		pq.push("Sahid"); 
		pq.push("Kebe"); 
		pq.push("Jake");
		pq.push("Foster"); 
		pq.push("Spencer"); 
		pq.push("Ras"); 
		pq.push("Arjit");   
		pq.push("Sarian");
		pq.push("John"); 
		pq.push("Lauren");
	} 
	void print(priority_queue<string>pq)
	{
	while(!pq.empty())
	{
		cout << pq.top() << endl; 
		pq.pop(); 
	} 
		}   
