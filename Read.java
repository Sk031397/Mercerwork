import java.io.*; 
import java.util.*;
import java.text.*;  
/* 
 * This class is used to read through a file and calculate the Flesch Readability Index and Grade Scale 
 */
public class Read {
	private static String allInput = "";
	/*
 * 	The main method allows the reading of the file 
 * 	*/ 
	public static void main(String args[]) throws IOException 
	{  
	  allInput = ""; 
	  try
       { 
		Scanner input = new Scanner(new File(args[0])); 
		while(input.hasNextLine())
		{
			String temp = input.nextLine();
			allInput+=temp;  
		}
	    }
	   catch(FileNotFoundException e)
	   { 
        e.printStackTrace(); 	
	   }
       catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Please enter a filename"); 
            Scanner name = new Scanner(System.in); 
            String file = name.nextLine(); 
            Scanner p = new Scanner(new File(file)); 
            while(p.hasNextLine())
            {
                String temp = p.nextLine(); 
                allInput+=temp; 
            }
             
        }
        DecimalFormat f = new DecimalFormat("##.0"); 
        System.out.println("The Flesch Score is " + (f.format(computeIndex() ))); 
        System.out.println("The Flesch Grade Index is " + (f.format((gradeIndex())) ));  
	}
	/*
 * 	@return a variable that keeps that keeps track of each sentence
 * 	The mehod checks to see if one of the ending sentence markers are seen (?,!,;, : or .) and keeps track fo essentially even time one occurs, 
 * 	marking the end of a sentence 
 * 	*/
	public static int countSentences(){
	  char temp; 
	  int counter = 0; 
	  for(int i = 0; i < allInput.length();i++)
	{
		temp = allInput.charAt(i); 
		if(temp == '.'||temp == '?' || temp =='!' || temp ==';' || temp == ':')
		{
			counter+=1; 
		}		 
	}
		return counter; 
}
	/*
 * @ return a variable that keeps track of each word in the file
 * If a space is seen that means a word has just ended. 
 * 	*/
	public static int countWords(){
	   int counter = 0; 
	   char temp; 
	   for ( int i = 0; i < allInput.length();i++) 
           {
	    temp = allInput.charAt(i); 
	    if ( temp == ' ') 
	    {
		counter+=1; 
	    }	
	   }

	return counter; 
}
	/*
 * @param a temp character variable that holds vowels. @return true is returned if a vowel is found and false otherwise. 
 * */ 
	public static boolean isVowel(char temp) 
	{
		if ( temp == 'a' || temp =='e' || temp == 'i' || temp == 'o' || temp == 'u' || temp == 'y')
		{
		  return true; 
		} 
	return false; 
	}
	/*
 * @return a variable that count each syllable in a word
 * @param a string that represents each individual word 
 * 	*/
	public static int countSyllablesinWord(String w)
	{
		int count = 0; 
		char temp; 
		char next; 
		for ( int i = 0 ; i < w.length(); i++)
		{
			temp = w.charAt(i); 
			if( i < w.length()-1)
			{
				next =  w.charAt(i+1);	
			}
			else {next = 0; } 
			if(temp=='e' && i == w.length()-1)
			{
			  continue; 
			}	
			else if(isVowel(temp)&& !isVowel(next))
			{
			   count+=1; 
			}
		}
		if ( count == 0) {count = 1;}
		return count; 
	}
	/*
 * 		@return a variable that keeps track of each syllable in the file. 
 * 		
 * 		*/
	private static int countSyllables()
	{
		int counter =0; 
		String token; 
		StringTokenizer mToken = new StringTokenizer(allInput," ");
		while(mToken.hasMoreTokens() ) 
		{
			token = mToken.nextToken(); 
			counter += countSyllablesinWord(token.toLowerCase()); 
		} 
		return counter;  
	}
	/*
 * @return a decimal value that calculates the Flesch Readability Index
 * 	*/
	public static double computeIndex(){
	int sentences = countSentences(); 			
	int words = countWords();
	int syllables = countSyllables(); 
	double index; 
	index = 206.835 - 84.6 * ((double)syllables / (double)words) - 1.015 * ((double)words / (double)sentences); 
	return index; 
}
	/*@return a decimal value that calculates the Flesch Grade Index
 * */
	public static double gradeIndex()
	{
	int sentences = countSentences(); 
	int words = countWords(); 
	int syllables = countSyllables(); 
	double index; 
	index = 11.8 * ((double) syllables / (double) words) + 0.39 * ((double) words / (double) sentences) - 15.59; 
	return index; 
	}
	}
