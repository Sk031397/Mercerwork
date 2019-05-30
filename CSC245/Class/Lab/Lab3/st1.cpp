#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std; 
	void Initialize(vector<int> &v);
	void Print(vector<int> &v); 
	void Reverse(vector<int>&v); 
	int main() {
	stack<string> s1, s2; 
	s1.push("Hi there"); 
	s2.push("How are you?"); 
	if(s1==s2) {
		cout <<"string 1 equals s2"<<endl; 
	} 
	else if(s1<s2) {
		cout << "string 1 is less than string 2"<< endl; 
	} 
	else {
		cout << "string 2 is greater than string 1"<<endl; 
	} 
	vector<int> v;
	cout<<"Please enter a 5 integers: "<<endl; 
	Initialize(v); 
	cout<<"After they are first put in the vector"<<endl; 
	Print(v);  
	Reverse(v);
	cout <<"After they are reversed"<<endl;  
	Print(v); 
	sort(v.begin(),v.end()); 
	cout<<"After they are sorted"<<endl; 
	Print(v); 
	return 0;
	}
	void Initialize(vector<int> &v) {
	    int input;  
	    for(int i =0; i<5;i++) {
		cin >> input; 
		v.push_back(input); 
		} 

		}
	void Print(vector<int> &v) {
		for(int i =0; i < v.size(); i++) {
			cout << v[i]<< " ";  
			cout<<endl; 
	}
		}
	void Reverse(vector<int>&v) 
	{
	vector<int>v2; 
	for(int i =0; i<v.size();i++) {
		v2.push_back(v[i]);

		} 
	for(int i =0; i<v2.size();i++) {
		v[i]=v2[v2.size()-i-1]; 
} 
	} 
 
	
 
