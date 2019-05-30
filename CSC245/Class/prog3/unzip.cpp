#include <iostream>
#include <vector>
#include <map> 
#include "huffman.h"
#include <stdio.h>      
#include <string>
#include <stdlib.h>  
#include <fstream> 
using namespace std;  

// This file deals with the unzipping of the file
 int main(int argc, char*argv[])  { 
  ifstream infile;  
       if(argc ==1)
   {
    cout << "Error! No File Entered"<< endl;
    exit(1);
   }
   // opens the file if it has zip 
   string filename = argv[1];
   infile.open(filename.c_str());
   string unzip = filename.substr(filename.find(".zip"),3);
   if(filename.compare("zip") ==0)
   {
     cout << "cannot zip file.file not zipped"<<endl;
     exit(1);
   }
   map<string,char>m; 
   int header;
   string input;   
   infile >> header;
   char ch; int ascii; string s; 
   // adds to the map 
   for (int i =1; i <=header; i++)
   { 
    infile >> ascii >> s; 
    m[s] = (char) ascii; 
   }
   infile >> input;  
   infile.close(); 
   ofstream out; 

   filename.substr(0,filename.find(".")); 
   infile.open(filename.c_str()); 
    string check; 
    int pos = 0; 
    int j = 1; 
    // checks to see if the string is in the code 
    for ( int i =0; i < input.length(); i++) 
    { 
     check = input.substr(pos,j); 
     if(!(m.find(check)==m.end()))
   {
      out << m.at(check); 
      pos = i+1; 
      j =1; 
   } 
   else { 
     j++; 
}
  out.close();  
 } 
        
   cout << "File Successfully Inflated Back to Original" << endl; 
   return 0; 
   
}
      
 
