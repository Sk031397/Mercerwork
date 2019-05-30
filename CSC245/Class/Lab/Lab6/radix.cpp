#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
 
 int maxElemLength(const vector<int>&L); 
 int GetDigit(int number, int k); 
  vector<queue <int> > ItemsToQueues(const vector<int>&v,int k); 
   vector<int> QueuesToArray(vector<queue<int> >&QA, int numVals);
   void RadixSort(vector<int> &v,int numDigits); 
   vector<string> padString(const vector<string> &v,int max);
   void PrintVector(const vector <int>&v); 
   vector<string> padString(const vector<string> &v,int max); 
 int main() 
 {
  vector<int> v(7);
  v[0] = 380;
  v[1] = 95; 
  v[2] = 345; 
  v[3] = 382; 
  v[4] = 260; 
  v[5] = 100; 
  v[6] = 492;  
  vector<queue<int> > QA(10);  
   cout << "The maximum integer contains " << maxElemLength(v) << " digits" << endl;  
   PrintVector(v);  
   RadixSort(v,maxElemLength(v));
   cout << "Afer sorting the vector "<< endl; 
   PrintVector(v);       
    return 0; 
  }
  // searches for the largest integer in the vector and states how many digits it has 
  int maxElemLength(const vector<int>&v) 
  {
    int len = 0; 
    for (int i = 0; i < v.size(); i++) 
    {
      int tmplength = 0; 
      int tmpNum = v[i]; 
      while(tmpNum > 0) 
      {
        tmpNum/=10; 
        tmplength++; 
     }
     if(tmplength > len) 
     {
       len = tmplength; 
     } 
         
  } 
    return len; 
   }
  // Gets the number of digits from a number 
  int GetDigit(int number, int k )
  {
     while(k>0) {
        number/=10; 
        k--;  
  }	 
	return number%10; 
}
 // converts the items into a queue 
  vector <queue<int> > ItemsToQueues(const vector<int>&v,int k)
  {
   vector <queue<int> > result(10); 
   for(int j = 0; j < v.size(); j++)
   {
    result[GetDigit(v[j],k)].push(v[j]);  
   } 
   return result;  
  } 
  // convert to queue to an array after the sorting is done 
  vector <int> QueueToArray(vector <queue<int> > &QA,int numVals) 
 {
  vector<int> list;     
   int index = 0;  
   while(list.size() < numVals) {
     while(QA[index].size() > 0 ) 
     {
      list.push_back(QA[index].front());   
      QA[index].pop();   
      } 
     index++; 
    } 
    return list; 
 } 
 // sorts through the vector of queues put them in their correct buckets 
  void RadixSort(vector<int>&v,int numDigits) 
  {
   for (int k = 0; k < numDigits; k++) {
      vector<queue<int> > result = ItemsToQueues(v,k); 
      v = QueueToArray(result,v.size()); 
        } 
} 
 // prints out the contents ot he vector 
  void PrintVector(const vector<int> &v) 
  {
   for(int i = 0; i < v.size();i++ ) 
     cout << v[i] << endl;  
   	}  
