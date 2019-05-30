import java.util.*; 
import java.text.*; 
import java.io.*; // The class extends from the abstract class Employee and implements Serializable to allow the reading and writing of files
	public class HourlyEmployee extends Employee implements Serializable {  
	// The constructor is created with name and wage and calls the base class constructor where the variables were initailly instantied to store these values
	public HourlyEmployee(String name,double wage) {
		super(name,wage); 
}  // The computePay is now implemented with the amount of pay 
	public double computePay (int hours) { 
		double pay ; 
   // if the employee works over 40 hours, Take their wage and multiply it by 40 hours, add that to the difference their hours minus 40 
   // and multiply the wage by 1.5 to give the employee timeand half 
	if(hours>40) 
	{ 
		pay = (40*super.getWage())+(hours-40)*(super.getWage()* 1.5); 
}
	else { 
 // or Else just multipy the amount of hours times the wage
		 pay = hours * super.getWage(); 

}
   return pay;  
} 
// returns what should be outputted to the screen as a string
	public String toString() { 
 // str1 is inialized to the wage the employee earns 
 String str1 = "" + super.getWage();
    try
    { // str1 is initialized with the substring of stril, it starts at 0 and goes to index where a period is located stops, and then starts where that period was found and goes 3 places passed the decimal place so that it can round of to the 2 zeros after the decimal 
      str1 = str1.substring(0, str1.indexOf('.')) + str1.substring(str1.indexOf('.'), str1.indexOf('.') + 3);
    }
    // if there is a string out of bounds error 
    catch (StringIndexOutOfBoundsException localStringIndexOutOfBoundsException)
    {// starts from the 0 index and go to the decimal point and then start at that decimal place and go until 2 decimal places after the decimal 
      str1 = str1.substring(0, str1.indexOf('.')) + str1.substring(str1.indexOf('.'), str1.indexOf('.') + 2) + 0;
    }
    // Limits the amount of characters allowed to 40 
    int i = 40 - super.getName().length() - str1.length() - "$/hour".length();
    // str2 is inialized with the name the user provides
    String str2 = super.getName();
    // loops the amount of characters that are on the screen 
    for (int j = 0; j <= i; j++) {
    // adds the name 
      str2 = str2 + " ";
    }
    //returns the name with the amount 
    return str2 + "$" + str1 +  "/hour" ;
  }



} 








 
