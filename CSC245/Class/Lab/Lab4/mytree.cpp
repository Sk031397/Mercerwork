#include <iostream>
#include "bst.h"
using namespace std; 

	int main() {
	
	BinarySearchTree<int> t(0); 
	t.insert(6); 
	t.insert(8);
	t.insert(2); 
	t.insert(4);
	t.insert(3); 
	t.insert(1);
	t.insert(9); 
	cout << " Inorder Traversal: " << endl; 
	t.printTree(); 
	cout << " PostOrder Traversal: "<<endl; 
	t.postOrder() ;
	cout <<"The height of the tree is : " << t.height() << endl; 
	cout << "The Tree has : " <<t.numLeaves() << "  leaves" << endl; 
	if(t.isBalanced() ) {
		cout << "It's Balanced" << endl; 
	}
	else {
		cout << "It's Not Balanced" << endl; 
} 
	return 0;
 
			}
