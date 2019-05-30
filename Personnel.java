import java.util.*; 
import java.io.*; 
import java.lang.*; 
import java.text.*; 
  public class Personnel{
  // A array of Employees in created and it will always have at lease one employee
  private static Employee[] employee = new Employee[1]; 
  private static int numE; 

  private static Scanner sc = new Scanner(System.in); 
    public static void main(String args[]) {
      menu(); 
      }
      // method menu 
      public static void menu(){
        clear(); 
        // loops through 40 times and adds dashes 
        for(int i =0; i<40; i++) {
           System.out.print("-");
           
           }
             System.out.println("\nCommands:\t\t\t|\n");  
           System.out.println("\n|Wage Calculator\t\t|\n");  
             for(int i = 0;i<40; i++){
             // loops through 40 times and adds dashes
                 System.out.print("-"); } 
              System.out.println("\n|Options\t\t\t|\n");  
                for(int i = 0;i<40; i++){
                // loops through 40 times and adds dashes
                 System.out.print("-"); } 
              System.out.println("\nn-To add new Employee\t\t|\n");
              System.out.println("c -To compute PayChecks\t\t|\n");
               System.out.println("r- to Raise the Wages\t\t|\n");
               System.out.println("p-To Print the records\t\t|\n");
               System.out.println("d- To download the data\t\t|\n");
                System.out.println("u-To upload the data\t\t|\n");
               System.out.println("q-To Quit Job\t\t\t|\n");
            System.out.println("e-To exit the Database\t\t|\n");    
               for(int i =0; i<40;i++){
               // loops through 40 times and adds dashes
                 System.out.print("-"); 
                   
                 }
                 System.out.print("\nEnter Option : ");
                 // the users input is inputted as a string. so in order to make it a character we must make it lowercase and included what is at the first index 
                 // which is were most strings are located at 
                 char option = sc.nextLine().toLowerCase().charAt(0);
                 /*menu option*/ 
                 // switch statement goes through and checks to see if one the conditions is meet with the user inputs a character
                 switch(option) {
                 case 'n': newEmployee(); menu(); break; 
                 case 'c': payChecks();   System.out.println("Please place Enter to Continue"); 
                 sc.nextLine(); 
                   menu(); break; 
                 case 'r': raiseWage(); 
                   System.out.println("Please place Enter to Continue"); 
                 sc.nextLine(); 
                   menu();break; 
                 case 'p': printRecord(); 
                 System.out.println("Please place Enter to Continue"); 
                 sc.nextLine(); 
                   menu(); break; 
                 case 'd': download(); 
                   System.out.println("Please place Enter to Continue"); 
                   sc.nextLine(); 
                   menu();
                    break; 
                 case 'u': upload();  
                   System.out.println("Please place Enter to Continue"); 
                 sc.nextLine(); 
                   menu();
                   break; 
                 case 'q': quitJob();
		sc.nextLine(); 
		menu(); 
	 break; 
	case 'e': 
		clear(); 
		System.exit(-1);  break; 
                 default: 
                   System.out.println("Command not recognized. Please try Again");
                    System.out.println("Please place Enter to Continue"); 
                     //sc.nextLine();   
                     menu(); 
                   break ;   
                   }
} 
 public static void quitJob()
  {
    System.out.println("Enter Employee name: "); 
    String deleteName = sc.next();
    CharSequence d = (CharSequence) deleteName.toLowerCase();   
    for(int i = 0; i<employee.length;i++) {
     if(employee[i].getName().toLowerCase().contains(d)) {
       System.out.println(employee[i].getName()+ " has been removed"); 
       employee[i]= null; 
	 break; 
		} 
	  
	}
		} 
 
		
          public static void clear() {// clears the screen 
            System.out.println("\u100b[H\u001b[2J");
              }
            public static void newEmployee(){
                System.out.println("Enter name of the new employee");
                String eName = sc.nextLine();  
                System.out.println("Hourly (h) or salaried (s): "); 
                char option = sc.nextLine().toLowerCase().charAt(0);
                switch(option) {// switch statement goes through the user input and goes to that certain method 
                  case 'h': newHourly(eName); break;
                  case 's': newSalary(eName); break;
                  default: System.out.println("Input is incorrect, Please Enter either h or s please"); 
                     System.out.println("Please place Enter to Continue"); 
                     sc.nextLine();
			  
                  menu(); 
                  break; 
                  }
            }
            public static void newHourly(String name) {
                System.out.println("Enter hourly wage:");
                try{
                // the users input is coming in a string but the input required is a double, so the string must be parsed as a double to meet the criteria 
                    double p = Double.parseDouble(sc.nextLine().trim()); 
                    // employee holds the number of employyes and morphs in the hourlyemployee class gets the name and to calculate the persons hourly wage 
                    employee[numE] = new HourlyEmployee(name,p); 
                    numE+=1;
                    check(); 
                    }catch(NumberFormatException local){
                      System.out.println("The employees wage much be a number");
                         System.out.println("Please place Enter to Continue"); 
                     sc.nextLine();   
                     menu(); 
                      }
                
                     } 
                    public static void newSalary(String name) {
                System.out.println("Enter annual salary:");
                try{ // the users input is coming in a string but the input required is a double, so the string must be parsed as a double to meet the criteria 
                    double p =  Double.parseDouble(sc.nextLine().trim());  
                    // employee holds the number of employyes and morphs in the hourlyemployee class gets the name and to calculate the persons annual salary 
                    employee[numE] = new SalariedEmployee(name,p); 
                    numE+=1;
                    check(); 
                    }catch(NumberFormatException local){
                      System.out.println("The employees salary much be a number");
                        System.out.println("Please place Enter to Continue"); 
                     sc.nextLine();   
                     menu();
                      }
                     }   
                    public static void payChecks(){
	
                      try{
                      // loops through the amount of employees and calculating their pay based on the amount of hours they work 
                          for(int i =0; i<numE; i++) {
                              System.out.println("Enter number of hours worked by " + employee[i].getName() + " : "); 
                              // the amount of hours is inputted as a string and must be converted to an integer 
                              int hours = Integer.parseInt(sc.nextLine().trim()); 
                              // format is used to print the pay with only 2 numbers behing the  decimal places behing it 
                              System.out.printf("Pay : $%.2f\n",employee[i].computePay(hours) );
                                }
                              }catch(NumberFormatException local) {
                                  System.out.println(" \nHours must be entered as a number; please try again.\n ");
                                    System.out.println("Please place Enter to Continue"); 
                     sc.nextLine();   
                     menu();
        }
      }
          public static void raiseWage(){
              System.out.println(" Enter percent increase: ");
              try{
              // percent must be converted from string to double
              double percent = Double.parseDouble(sc.nextLine().trim());
              for(int i =0; i<numE; i++) {  
              // loops through the amount of employees and raises their wage according to amount that they specified 
                  employee[i].raise(percent); 
                  }
                  System.out.println(" \nNew Wages\n-------- ");
                  printRecord(); // prints at the new wage that was calculated
                      }catch(NumberFormatException local) {
                                System.out.println(" \nError in percent increase; Please try again.\n ");
                                  System.out.println("Please place Enter to Continue"); 
                     sc.nextLine();   
                     menu();
                                }
                      } 
                      
              public static void printRecord() {
              // loops through the amount of employees print out eact 
                  for(int i =0; i<numE; i++) {
                      System.out.println(employee[i]); 
                      }
                      }
                      public static void download(){
                      try{ 
                        System.out.println(" Now dowloading files... ");
                        //printRecord();
                        // sends the output to a file called 'Employees.dat'
                        ObjectOutputStream local = new ObjectOutputStream(new FileOutputStream("Employee.dat")); 
                        local.writeObject(employee);// write the array of employees to the file 
                        local.close(); // close the file 
                        }catch(IOException e){ 
                            System.err.println("\nError writing to Employees.dat\n");
                            
                            }
                       }
                       public static void upload() {
                           try{
                               ObjectInputStream local = new ObjectInputStream(new FileInputStream("Employee.dat")); // sends the output to a file 'Employee.dat'
                               Employee[] arrayOfEmployee = (Employee[])local.readObject();// sets a new array of employees containing all the record read into the file 
                               local.close(); 
                               }catch(IOException e) {
                                 System.out.println(e.getMessage()); 
                                 }catch(ClassNotFoundException e) {
                                     System.out.println("\nError reading from Employees.dat\n"+e.getMessage()); 
                                     } 
                                     for(int i =0; i < employee.length; i++) {
                                         System.out.println(employee[i]);
                                        }
                                        
                                        }
                                        public static void check(){// checks to see if the maximum capacity of the array is meet 
                                 if(numE == employee.length) {
                                 // if it is meet than the size must be multipied by 2 
                                     Employee[] employeeA =  new Employee[employee.length*2];
                                       for(int i =0; i<employee.length;i++) {//loops through original array and sets the values in the new array equal to the original 
                                           employeeA[i]= employee[i]; 
                                           }
                                           employee = employeeA; 
                                           }
                                           }
                                           
                                      } 
