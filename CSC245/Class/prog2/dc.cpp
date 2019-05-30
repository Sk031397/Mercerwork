
#include <iostream>
#include<string>
#include <math.h>
#include <cctype>
#include <cstdlib>
#include <stdlib.h>
#include "stack.h"
#include "dsexceptions.h"
using namespace std; 
	bool isOperator(const string& letter); 
	void performOp(const string&letter, Stack<int> &calcStack); 
	bool isCharacter(const string &letter); 
	void doOptions(const string &letter, Stack<int> &calcStack); 
	void compute(Stack<int>&calcStack,string input); 
	bool stringIsDigit(string input); 
	

	int main() 
	{
	
	Stack<int> calcStack;
	string letter;  
	while(getline(cin,letter)) 
	{
	 compute(calcStack,letter); 
	}
		return 0; 
	}
		/*
 		* @ return true if the char entered is in the area and false if it is not  
 		* @ param a character is passed in that refererences the original character that was inputted 		
 		*/
       void compute(Stack<int> &calcStack, string input)  {
        try
        {     
	     string temp = ""; 
       	     int calc = 0; 
	     
            	 bool isDig = stringIsDigit(input); 
                // Checks if the instruction line only contains a single digit integer.  If so, push it after converting.
                if(isDig)
                {
                        calcStack.push(atoi(input.c_str()));
                }
               // If the instruction line is not only an integer, the instructions must be parsed.
            else
                {
                        for(int i = 0; i < input.length(); i++)
                        {
                                // If the character is an integer, pull all integer characters until a non integer is reached.
                                if(isdigit(input[i]))
                                {
                                        int temp = input[i] - '0';
                                        int count = 1;
                                        while(isdigit(input[i + count]))
                                        {
                                                temp = temp * 10 + input[i + count] - '0';
                                                count++;
                                        }
                                        i = i + count - 1;

                                        calcStack.push(temp);
                                }
			 if(input[i] == '_')
			{
        			if(!isdigit(input[i+1]))
       				 {
          			throw DataError();
       				 }
				temp ="";
				temp+= '-';
						} 

					else if(isOperator(input)) 
				{
				
					 
					    
					performOp(input,calcStack);
					    
				
				}
				else if(isCharacter(input)) 
				{	
					doOptions(input,calcStack); 
				}   
			  
				
				         	 }
		                }
			}
   			catch(Underflow exc) {
			  cout << "stack is empty"<< endl; 
							} 
			catch(Overflow exc) 
			{
				cout << "The Stack is Full"<< endl;  
			}
			 
						}		 
		// @ param a reference to the original character and a reference to the original stack 
	void performOp(const string&letter,Stack<int>&calcStack) 
		{
			int lVal, rVal, result; 
			lVal = calcStack.top();  
			calcStack.pop(); 
			rVal = calcStack.top();	  
			calcStack.pop(); 
				if(letter== "+"){
				result = lVal + rVal; 
				}
				else if(letter=="_"){		 
		 		 	result = lVal - rVal;
					}
				else if(letter== "/"){
				try{
				if(rVal == 0){
					throw DivisionByZero(); 
				}
 				else{
				result = lVal / rVal; 
					} 
				 } 
				catch(DivisionByZero exc){ 
					cout << "Divison By Zero cannot occur" << endl; 
					} 
				} 
				else if(letter== "*"){
					result = lVal * rVal;
					}
				else if(letter== "%"){
					try{
				if(rVal == 0){
					throw DivisionByZero(); 
				}
 				else{
				result = lVal % rVal; 
					} 
				 } 
				catch(DivisionByZero exc){ 
					cout << "Divison By Zero cannot occur" << endl; 
					}  
             }
				calcStack.push(result); 
			  		}
		// @ param a reference to the original letter
		// @ return true is returned if the letter is on of these, otherwise false 
		bool isCharacter(const string&letter) 
		{
			string c[] = {"p","n","f","c","d","r"}; 
			for( int i  = 0; i < 6; i++) 
			{
				if(letter == c[i]) 
				{
				
					return true; 
				}
			 }
			  
			
				return false; 
			}
		bool isOperator(const string&letter) 
		{
			string op[] = {"_","+","*","/","&"}; 
			for(int i = 0; i <5; i++ ) {
				if(letter==op[i]) {
				  return true; 
				}
					} 		
			return false; 	
		} 
		// @ param a reference to the original character and the stack 
		void doOptions(const string&letter, Stack<int> &calcStack) 
		{
			Stack<int> copy = calcStack; 
			// prints out the top of the stack 
			   if(letter== "p"){
				cout << calcStack.top() << endl; 
				}	 
				else if(letter== "n"){
				cout << calcStack.top()<<endl;  
				}
			// prints out entire stack  
			else if(letter== "f"){
				while(!copy.isEmpty()) 
				{
					cout << copy.topAndPop() << endl; 
					  	}
					}
				// clears the stack of any numbers in it  
			else if(letter== "c"){
				while(!calcStack.isEmpty()) 
				{
					calcStack.makeEmpty(); 
				}
					}
			// duplicates the stack with its top value 
			else if(letter=="d"){
				calcStack.push(copy.top()); 
					}	
			// swaps the top two values 
			else if(letter=="r"){ 
				int top1 = calcStack.topAndPop(); 
				int top2 = calcStack.topAndPop(); 
				calcStack.push(top1); 
				calcStack.push(top2); 
					}
				calcStack = copy; 	
		} 
 bool stringIsDigit(string input)
     {
      if(isdigit(atoi(input.c_str()))){
		return true;  
       }
		return false; 
	}
