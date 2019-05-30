#include <iostream>
#include "BinaryHeap.h"
using namespace std; 

	int main() {
		BinaryHeap<char> PQ(50); 
		for(char i = 'A'; i <= 'J'; i++ ) 
		{
			PQ.insert(i); 
		} 
		PQ.deleteMin(); 
		cout << "Printing Left Subtree"<< endl; 
		PQ.printLtSubtree(); 
		cout << endl;
		  
		cout << "The Height of the Heap is " <<  PQ.Height()<< endl; 
		 
		cout << "The Maximum Value of the Heap is " << PQ.findMax() << endl; 
			
		
		return 0; 
		} 
