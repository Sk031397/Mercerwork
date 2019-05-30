 #include"huffman.h"
 #include <iostream>
 #include <string>
 #include <cstring>
 #include <cctype>
 #include <fstream>
 #include <cstdlib>
 using namespace std;
 bool fileIsThere(int argc, char *argv[]);
 void save(ifstream& infile, int argc, char *argv[], HuffmanTree& h, int Letters[],int &source);
 void OpenFile (ifstream& infile,int argc, char *argv[]);
 void count (ifstream& infile, int Letters[],int &source);
 void insert (const int Letters[], HuffmanTree& h);
 void PrintLetters (const int Letters[]); 
 /*
    main takes in a file and runs the program 
   */ 
 int main(int argc, char *argv[]){
   HuffmanTree h;
   string name = argv[1];
   int letters[256];
   ifstream infile;
   int source = 0;  
   int bits = 0; 
   if(argc==1)
   {
   cout << "zip: Invalid format"<< endl;
   exit(1);
   }
   else if(name.compare("--help")==0)
     {
       infile.open("help"); 
       
         while(!infile.eof()){
           infile >> name; 
           cout << name << endl;  
         } 
         infile.close(); 
         exit(1); 
       } 
     
   else if(name.compare("--t")==0 && fileIsThere(argc, argv)){ 
     OpenFile(infile, argc, argv);
    count(infile, letters,source);
   insert(letters, h);
    h.build();
   h.PrintTable();
   cout << "File Successfully Compressed "<< endl;
   save(infile, argc, argv, h, letters,source);
   }
   else if(name.compare("--t")==0 && !fileIsThere(argc, argv)){
     cout<< "zip: file "<< argv[argc-1] << " does not exist."<< endl;
     exit(1);
   }
    else if(!fileIsThere(argc, argv)){
    cout<< "zip: file "<< argv[argc-1] << " does not exist."<< endl;
     exit(1);
    }
    else if(argc==2 && fileIsThere(argc, argv)){
    OpenFile(infile, argc, argv);
   count(infile, letters,source);
   insert(letters,h );
    h.build();
    cout << "File Successfully Compressed "  << endl; 
   }
   return 0;
   }
   /*
    function takes in a file and returns a file 
   */
  bool fileIsThere(int argc, char *argv[])  
  {
    ifstream infile;   
    string filename = argv[argc-1];
    return infile; 
  }
  /* 
  Opens the file 
  */ 
 void OpenFile (ifstream& infile, int argc, char *argv[]) 
 {
         if (argc == 1)
         {
                 cout << "Error!! No File Entered." << endl;
                 exit(1);
         }
 
         string filename = argv[argc-1];
         infile.open(filename.c_str());
 }
 /* saves the file */ 
  void save(ifstream& infile, int argc, char *argv[], HuffmanTree& h,int letters[],int &source) 
 { 
   OpenFile(infile, argc, argv);
 ofstream out;
 string file = (argv[argc-1]);
    file+=".zip";
   out.open(file.c_str());
   out << h.numNodes() << endl;
   for (char ch = char(0);  ch <= char(126);  ch++)
  if ( (letters[ch] != 0) && (ch != '\n') && (ch != ' ') ){
    out << int(ch) << ' ' <<h.GetCode(ch)<< endl;
    source++;  }
  else if ( (letters[ch] != 0) && (ch == '\n') ){
    out << int(ch) << ' ' <<h.GetCode(ch)<< endl;
    source++;}
  else if ( (letters[ch] != 0) && (ch == ' ') ){
    out << int(ch) << ' ' <<h.GetCode(ch)<< endl;
         source++;
}
      char name;
   infile.get(name);
    while(infile){
    out<<h.GetCode(name);
    infile.get(name);
    } 
 out.close();
  infile.close();
 }
 // count the letters in the file 
 void count (ifstream& infile, int letters[],int &source)
 {
 
 char ch;
 string b; 
 for (char ch = char(0);  ch <= char(126);  ch++)
 letters[ch] = 0;
 infile.get(ch);
 while (infile)
 {
 letters[ch] += 1;
 b+=ch; 
 infile.get(ch);
 source++; 
 }
  infile.close();
 }
 // inserts into the tree 
 void insert (const int letters[], HuffmanTree& h)
 {
 for (char ch = char(0);  ch <= char(126);  ch++)
  if ( (letters[ch] != 0) && (ch != '\n') && (ch != ' ') )
    h.insert(ch, letters[ch]);
  else if ( (letters[ch] != 0) && (ch == '\n') )
    h.insert('\n', letters[ch]);
  else if ( (letters[ch] != 0) && (ch == ' ') )
    h.insert(' ', letters[ch]);
 }
 // prints the letters 
 void PrintLetters (const int letters[])
 {
 for (char ch = char(0);  ch <= char(126);  ch++)
  if ( (letters[ch] != 0) && (ch != '\n') && (ch != ' ') )
    cout << "Char " << ch << " appearances  : " << letters[ch] << endl;
  else if ( (letters[ch] != 0) && (ch == '\n') )
    cout << "Char nl appearances : " << letters[ch] << endl;
  else if ( (letters[ch] != 0) && (ch == ' ') )
    cout << "Char sp appearances : " << letters[ch] << endl;
 }
