#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <string> 
using namespace std;
  void unPadString(vector<string>& v, int max); 
 int maxElemLength(const vector<string>&L); 
 char GetDigit(string number, int k); 
  vector<queue <string> > ItemsToQueues(const vector<string>&v,string k); 
   vector<string> QueuesToArray(vector<queue<string> >&QA, int numVals);
   void RadixSort(vector<string> &v,int numDigits); 
    void PadString(vector<string>&v,int max); 
   void PrintVector(const vector <string>&v);
    
 int main() 
 {
  vector<string> v;
   v.push_back("zebra"); 
   v.push_back("apple");
   v.push_back("orange");
   v.push_back("can");
   v.push_back("candy"); 
   v.push_back("a");
   v.push_back("top");
   v.push_back("pumpkin");
   v.push_back("today");
   v.push_back("parade");   
   vector<queue<string> > QA(128);  
   PrintVector(v);  
   PadString(v,maxElemLength(v));   
   RadixSort(v,maxElemLength(v)); 
   unPadString(v,maxElemLength(v));  
   cout << "After Sorting"<< endl;  
   PrintVector(v);       
    return 0; 
  }
  void PadString(vector<string>&v,int max)
  {
   
   for(int i = 0; i < v.size();i++)
   {
   if(v[i].length() < max)
   { 
      for(int j = v[i].length(); j<max;j++)
      {
        v[i]+= " ";
      }  
   } 
  }
  }
 void unPadString(vector<string>& v, int max)
{
for (int i = 0;  i < v.size();  i++)
{
while (v[i].at(v[i].length()-1) == ' ')
{

v[i] = v[i].substr(0, v[i].length()-1);

                }
        }
}
  // searches for the largest string in the vector and states how many characters it has 
  int maxElemLength(const vector<string>&v) 
  { 
  int len = 0; 
      for(int i = 0; i < v.size();i++)
      {
      string temp = v[i]; 
      if(temp.length() > len)
      
      len = temp.length(); 
      }
      return len;
      } 
  // Gets the number of digits from a number 
  char GetLetter(string number, int k )
  {
        return (number[number.length()-1-k]); 
       	 
	 } 

 // converts the items stringo a queue 
  vector <queue<string> > ItemsToQueues(const vector<string>&v,int k)
  {
   vector <queue<string> > result(256); 
   for(int j = 0; j < v.size(); j++)
   {
    result[GetLetter(v[j],k)].push(v[j]);  
   } 
   return result;  
  } 
  // convert to queue to an array after the sorting is done 
  vector <string> QueueToArray(vector <queue<string> > &QA,int numVals) 
 {
  vector<string> list;     
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
  void RadixSort(vector<string>&v,int numString) 
  {
    for (int k = 0; k < numString; k++) {
      vector<queue<string> > result = ItemsToQueues(v,k); 
      v = QueueToArray(result,v.size()); 
        } 
        } 
 // print strings out the contents ot he vector 
  void PrintVector(const vector<string> &v) 
  {
   for(int i = 0; i < v.size();i++ ) 
     cout << v[i] << " " << endl;   
   	}  
