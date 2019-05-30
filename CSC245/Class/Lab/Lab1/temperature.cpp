#include <iostream>
using namespace std; 
	double convert(double value);
	int main() {
		int convertValue; 
		cout << "Please enter a Celsius value: " <<  endl;
		cin >> convertValue; 
		cout << convertValue << " degress Celsius is " << convert(convertValue) << " degrees Fahrenheit" << endl; 
		return 0; 
} 
	double convert(double tmp) {
		return 1.8 * tmp + 32; 

} 
