#include <iostream>
using namespace std; 

	bool Point(double *ptr,double *ptr2); 
	bool Address(double *ptr,double *ptr2); 
	int main() {
	double num1 = 2.0;   
	double *ptr = &num1; 
	double *ptr2 = &num1; 
	cout<<Point(ptr,ptr2)<<endl;
	cout<<Address(ptr,ptr2)<<endl; 
	return 0; 
	
	}
	bool Point(double *ptr,double *ptr2) {
		return (*ptr==*ptr2);  	

}
	bool Address(double *ptr, double *ptr2) {
		return ptr==ptr2; 

	} 
	

