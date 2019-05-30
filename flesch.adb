with Ada.IO_Exceptions;   
with Ada.Float_Text_IO;
with Ada.Command_Line, Ada.Text_IO;
use  Ada.Command_Line, Ada.Text_IO; 
use Ada.IO_Exceptions; 
use Ada.Float_Text_IO; 
procedure flesch is 
In_File : Ada.Text_IO.File_Type; 
value: Character; 
pos: Integer; 
string_array: array(1..5000000) of Character;
nwords:Float;   
nsentences:Float; 
nsyllables:Float;
gradeIndex: Float; 
Word:Boolean:=False; 
fleschIndex:Float;
Last:Natural;    
Ice: String(1..500);   
begin 
 --Read In the file in from the command line or user input. 
    if Argument_Count > 0 then 
    Ada.Text_IO.Open(File=>In_File, Mode=>Ada.Text_IO.In_File,Name=>Ada.Command_Line.Argument(1));  
    else 
    Put_Line("Please enter a filename");
    Ada.Text_IO.Get_Line(Ice,Last);
    Ada.Text_IO.Open(File=>In_File,Mode=>Ada.Text_IO.In_File,Name=>Ice(1..Last));   
    end if;  
 pos:=0;
-- Read in the file and store it into a string.  
 while not End_Of_File(In_File) loop 
 Get(In_File,value) ; 
 pos:=pos+1;
 string_array(pos):=value; 
 end loop;
 exception  
 when Ada.IO_Exceptions.END_ERROR => Close(File=>In_File); 
 -- Count Words 
 -- the words are calculated based on the what is found 
 nwords:=0.0; 
 for i in 1..pos
 loop
 if (string_array(i) = ' ' and Word = True)
 then
 Word:=False; 
 elsif (string_array(i) /= ' ' and Word = False)
 then
 Word := True;
 nwords := nwords + 1.0;
 else
 null;
 end if;
 end loop;

 -- Count Sentences  
 -- the sentences are calculated depending on what is found 
 nsentences:=0.0;
 for i in 1..pos
 loop
  if (string_array(i) = '?' and Word = True)
 or (string_array(i) = '!' and Word = True)
 or (string_array(i) = ';' and Word = True)
 or (string_array(i) = ':' and Word = True)
 or (string_array(i) = '.' and Word = True)
 then
 Word := False;
 elsif (string_array(i) /= '?' and Word = False)
 or (string_array(i) /= '!' and Word = False)
 or (string_array(i) /= ';' and Word = False)
 or (string_array(i) /= ':' and Word = False)
 or (string_array(i) /= '.' and Word = False)
 then
 Word := True;
 nsentences := nsentences + 1.0;
 else
 null;
 end if;
 end loop;

-- -- Count Syllables 
--  the syllables are calculated 
 nsyllables:=0.0; 
 for i in 1..pos loop 
 if(string_array(i)='a'and Word=True) or ( string_array(i) = 'e'and Word=True) or (string_array(i)= 'i'and Word=True) or ( string_array(i)= 'o'and Word=True) or ( string_array(i)='u'and Word=True) or ( string_array(i)= 'y'and Word=True) then             
 Word:=False; 
 elsif((string_array(i) = 'e' and ((string_array(i+1)=' ') or (string_array(i+1)='?')or(string_array(i+1)='!')or(string_array(i+1)=';')or(string_array(i+1)=':')or(string_array(i+1)='.')))) then
 Word:=True;
 null;
 elsif(string_array(i)/='a'and Word=False) or (string_array(i)/='e'and Word=False) or (string_array(i)/='i' and Word=False) or (string_array(i)/='o' and Word=False) or (string_array(i) /='u' and Word=False)or(string_array(i)/='y'and Word=False) then
 Word:=True;
 nsyllables:=nsyllables + 1.0; 
 end if;  
 end loop;  
 -- compute grade index    
 gradeindex := float((nsyllables / nwords) * 11.8 + (nwords / nsentences) * 0.39 - 15.59);   
 -- compute flesch readabiilty index
 -- the flesch index is calculated and rounded to one decimal place  
 fleschIndex:= 206.835-(1.015* float(( nwords / nsentences))) - (84.6 * float(( nsyllables / nwords ) )) ;     
 Put("The Flesch Readability is "); 
 Ada.Float_Text_IO.PUt(fleschIndex,0,0,0); 
 Ada.Text_IO.New_Line;     
-- compute the grade index and 
-- -- the flesch grade index is calculated and rounded to one decimal place 
 Put("The Flesch Grade is ");  
 Ada.Float_Text_IO.Put( gradeIndex,0,1,0 );   
 end flesch; 

