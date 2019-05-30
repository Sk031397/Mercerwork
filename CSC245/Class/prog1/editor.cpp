#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
#include<cstdlib>
#include "linelist.h"
using namespace std; 

void OpenFile(ifstream&infile, int argc, char*argv[]); 
void makeList(ifstream& infile, LineList& aline); 
void SaveList(ofstream& outfile ,char *argv[], LineList& L); 
// @param arg for file and arg of chars to hold string 
// .. @ retrun prints out the file or ) if the condition  is false 
int main(int argc, char*argv[]) 
{
        LineList L;
        ifstream infile;
        OpenFile(infile,argc,argv); 
        makeList(infile,L); 
	L.printList(); 

        string name;
        char point;

        do 
        {
cout<<L.getCurrLineNum()-1<<"> ";
cin >> point; 
cin.ignore();
      switch(point) 
               {
        case 'I': //This insert a new line to the current line
cout<<L.getCurrLineNum()<<"> ";
                getline(cin, name);
                L.insertLine(name);
                        break;
        case 'D': //This deletes the current line
                L.deleteLine();
                        break;
        case 'L': //This prints the list
                L.printList();
                        break;
        case 'P': //This goes to the previous line
                L.movePrevLine();
                        break;
        case 'N': //This goes to the next line
                L.moveNextLine();
                        break;
                }
        } while (point != 'E'); //The do -while runs until the character 'E' is pressed 

ofstream outfile;
SaveList(outfile, argv, L);
        return 0;
}

// @ param file, argc and character of letters
void OpenFile(ifstream&infile,int argc,char *argv[]) 
{
if(argc==1)
{
cout<<"Error!! No File Entered."<<endl;
exit(1);
}
string filename = argv[1];
infile.open(filename.c_str());
}
// @ param file adn and the List 
void makeList(ifstream& infile, LineList& L) 
{
string line;
while(getline(infile,line))
{
L.insertLine(line);
}
infile.close();
}
// @ param file, array of characters and the List 
void SaveList(ofstream& outfile, char *argv[], LineList& L) 
{
string filename = argv[1];
outfile.open(filename.c_str());
L.goToTop();
for(int i=0; i<L.getLength();i++)
{
outfile<<L.getCurrLine()<<endl;
L.moveNextLine();
}
outfile.close();
}
