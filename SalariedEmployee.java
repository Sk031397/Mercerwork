import java.util.*; 
import java.io.*; 
import java.text.*; 
// the class extends from the base class employee and allows the reading and writing of files due to implements Serializable
	public class SalariedEmployee extends Employee implements Serializable { 
	private double salary; 
 // The constructor has params of name and salary and constructor contains the name that was made in the base class and the (wage) or salary in this case is divided by the amount of weeks and a year(52) times the amount of standard hours (40) and multipiled to get 2080  
		public SalariedEmployee(String name,double salary ) { 
     super(name,(salary/(2080))); 

	} 
 // the wage times 2080(52 amount of weeks worked) * (standard hours worked = 40) 
	public double getWage() {
		return Math.round(super.getWage()*2080); } 
//the wage dividend by 2080(52 amount of weeks worked) * (standard hours worked = 40) 
	public void setWage(double nSalary) {
      super.setWage( nSalary/(2080));  
} //@param hours 
  //@return the wage by the amount of weeks throughout a year 
	public double computePay (int hrs) { 
  return getWage()/52; 
} 

	public String toString() { 
  String s = " " + getWage(); 
  try{// s is initialized with the substring of s, it starts at 0 and goes to index where a period is located stops, and then starts where that period was found and goes 3 places passed the decimal place so that it can round of to the 2 zeros after the decimal 
      s = s.substring(0,s.indexOf('.'))+ s.substring(s.indexOf('.'),s.indexOf('.')+3); 
    //if string out of bounds error 
 }catch(StringIndexOutOfBoundsException e ){
   // starts from the 0 index and go to the decimal point and then start at that decimal place and go until 2 decimal places after the decimal 
         s = s.substring(0,s.indexOf('.'))+ s.substring(s.indexOf('.'),s.indexOf('.')+2)+0; 
         
}
// limts the amount of characters that can be added to 40 
  int i =40-super.getName().length()- s.length()- "$/year".length(); 
  String s2 = super.getName(); 
    for(int j= 0; j<=i; j++){
    // loops through all the characters and displays the entire Name
        s2 = s2 + " "; 
        }
        // returns the name + the persons annual salary 
        return s2 + "$" + s + "/year";  
		}

 }
