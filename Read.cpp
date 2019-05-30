#include <iostream>
#include <string>
#include <string.h>  
#include <fstream> 
#include <cstdlib>
#include <cctype>  
#include <cstdio> 
using namespace std; 

string allInput = "";
// Protyping  
bool isVowel(char temp);  
int countWords();   
int countSyllables(); 
double computeIndex(); 
double gradeIndex(); 
int countSentences();
/* @ param allows the user to type in a file name 
  * runs through the file and reads all the data storing it into a string variable and outputting the functions based on the file 
   * */  
int main(int argc, char * argv[])
{
    ifstream infile;
    string file;
    string temp="";  
    // If the user forgets to put in a file, prompt them to enter oen  
    if(argc==1){
        cout << "Please enter a file" << endl;
        getline(cin,file); 
        infile.open(file.c_str());
        while(!infile.eof())
        {
            getline(infile,temp); 
            allInput+=temp; 
        } 
     }
    // If an argument is included, read it.. 
    if(argc>1){
    allInput = "";      
    string filename = argv[1]; 
    infile.open(filename.c_str()); 
    }
    while (!infile.eof())
    {
        getline(infile,temp);
        allInput+=temp;  
    } 
    printf("The Flesch Score is %.1f\n",computeIndex());         
    printf("The flesch Kincaid Grade Index is %.1f\n",gradeIndex());   
    return 0; 
}
/* counts the amount of sentences in a file 
 * */
int countSentences()
{
    char temp; 
    int counter = 0; 
    for ( int i = 0; i < allInput.size(); i++)
    {
        temp = allInput.at(i); 
        if( temp == '?' || temp == '.' || temp == '!'|| temp == ';' || temp ==':')
        {
            counter+=1;                                                                                                                                                         }
    }
    return counter;   
} 
/* counts the words in a file 
 * */
int countWords()                                                                                                                                                                 {
    int counter = 0; 
    char temp; 
    for ( int i = 0; i < allInput.size(); i++)
    {
        temp = allInput.at(i); 
        if( temp == ' ')
        {
            counter+=1; 
        }
        if(isdigit(i)&& isdigit(i+1)) { continue; } 
        else if ( isdigit(i) && isalnum(i+1) ) { counter++; } 
    }
    return counter; 
}
/* counts the syllables in the file 
 * */
int countSyllables()                                                                                                                                                                                                                                                    {
    int counter = 0; 
    char temp; 
    char next; 
    for (  int i = 0; i < allInput.size(); i++)
    {
        temp = allInput.at(i); 
        islower(i); 
        if ( i < allInput.length() -1) 
        {
            next = allInput.at(i+1);       
        }
        else { next =0;}
        if ( temp == 'e' && i == allInput.size() )
        {
            continue; 
        }
        else if (isVowel(temp) && !isVowel(next))
        {
            counter+=1; 
        }
        if( counter == 0)
        {
            counter =1; 
        }

    }  
    return counter;
}
/*@param( a character that was used to keep track on each vowel ) 
 * returns a true/false depending on the whether a vowel is there or not. 
 */
bool isVowel(char temp)
{
    if (  temp== 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u' || temp == 'y')
    {
        return true; 
    }
    return false; 

}
/* @ param a temp characters to check and see if one is located in the file  * */
/* calculate the flesch readability index                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    * */
double computeIndex(){
    int sentences = countSentences();
    int words = countWords();
    int syllables = countSyllables();
    double index;
    index = 206.835 - 84.6 * ((double)syllables / (double)words) - 1.015 * ((double)words / (double)sentences);
    return index;
}
/*  calculates the flesch kincaid grade index 
 * */
double gradeIndex()
{
    int sentences = countSentences();
    int words = countWords();
    int syllables = countSyllables();
    double index;
    index = 11.8 * ((double) syllables / (double) words) + 0.39 * ((double) words / (double) sentences) - 15.59;
    return index;
}

