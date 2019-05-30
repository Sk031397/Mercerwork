import java.util.*;
import java.lang.*;  
import java.io.*; 
// Utility and Input.Output are imported 
// in order for one to use Scanner and input files. 
public class Library {
    // A array list of that holds a size of 50 books is created 
    private static ArrayList<LibraryBook> books = new ArrayList<LibraryBook>(50);
    //an integer that holds the num of books  
    private static int numBooks; 

    public static void main (String[] args) {


        // The method open, reyns the whole program
        open(); 


    }
    public static void open() {
        System.out.println("THE BOOKS SEARCH PROGRAM ");   
        System.out.println("---------------------");
        File curDirc = new File("."); 
        String[] filenames = curDirc.list(); 
        ArrayList<String> data = new ArrayList<String>(); 
        for(String s: filenames) {
            if(s.endsWith(".dat")) {
                data.add(s); 

            } 
        }   
        System.out.println(); 
        Scanner input = new Scanner(System.in); 
        clearScreen(); 
        System.out.println("What file are the books stored in"); 
        System.out.println("Here are the files you can use: "  +  data);
        String fname = input.next(); 
        System.out.print("Filename:" + fname);  
        numBooks = inputBooks(fname);
        System.out.println(); 
        System.out.println("A total of "+ numBooks+ " books have been sorted by title :") ;
        System.out.println("  Enter Return to Contine"); 
        input.nextLine(); 
        input.nextLine();  
        clearScreen();  

        menu();    		

    }
    public static int inputBooks(String inputFile){
        int numBooks = 0;
        /* Use a try-catch block to look through the file  
         * 	*/ 
        try{ 
            // A Scanner is needed in order to input the files that will be needed 
            Scanner input = new Scanner(new File(inputFile)); 
            // The while loop will conduct as long as their is something in front of it 
            while(input.hasNext()) 
            {
                // A second scanner is created that takes the file and uses a semi-colon to differntiate its fields 
                Scanner lsc = new Scanner(input.nextLine()).useDelimiter(";"); 
                String title = lsc.next(); 
                String name = lsc.next(); 
                int copyright = lsc.nextInt(); 
                double price = lsc.nextDouble(); 
                String genre = lsc.next(); 
                books.add(new LibraryBook(title,name,copyright,price,genre));


                numBooks++;  	



            }
            selectionSort(); 
        }	// The catch block states that there might be a IOException and if there is display that there is  
        catch(IOException e) {
            System.out.println(e.getMessage()); 
        }


        return numBooks++; 

    }
    // The method prints out the records 
    public static void printRecord(int location) {
        System.out.println("Record #     " +"\t"+ (location +1) + "\n"); 
        System.out.println("\t"+ "****************"); 
        System.out.println("Title:      " +"\t"+books.get(location).getTitle());
        System.out.println("\t"+  "****************"); 
        System.out.println("Author's Name     " + " \t"+ books.get(location).getAuthor());
        System.out.println("\t"+  "****************");  
        System.out.println("Copyright     " + "\t"+ books.get(location).getCopyright()); 
        System.out.println("\t"+  "****************");  
        System.out.println("Price        " + "\t"+books.get(location).getPrice()); 
        System.out.println("\t"+  "****************"); 
        System.out.println("Genre       " + "\t"+books.get(location).getGenre()+"\n" );
        System.out.println("\t"+     "****************"); 
    } 
    // The method sorts the list of books 
    public static void selectionSort()
    {
        int begin, location, next;
        LibraryBook temp;
        for(begin=0; begin<books.size()-1; begin++)
        {
            location = begin;
            for(next = begin+1; next < books.size(); next++)
                if(books.get(next).compareTo(books.get(location))<0)
                    location = next;
            if(begin != location)
            {
                temp = books.get(location);
                books.set(location,books.get(begin));
                books.set(begin,temp);
            }
        }



    } 

    // The method gives the user the option to choice what they do next 
    public static int menu() {
        System.out.println("THE GREAT BOOKS SEARCH PROGRAM");
        System.out.println("-------------"); 
        System.out.println("1) Display all book records"); 
        System.out.println("2} Search for a book by Title");
        System.out.println("4} Search for a book by Author");
        System.out.println("4} Search for a book by Genre");
        System.out.println("5) Exit Search Program"); 
        System.out.println("------------"); 
        Scanner in =  new Scanner(System.in); 
        System.out.println("Please Enter Your Choice > ");  
        int selection= in.nextInt(); 
        switch(selection){
            case 1: 
                displayRecords(); 			
                break; 
            case 2: 
                search(); 
                break; 
            case 3: 
                searchAuthor(); 
                break; 
            case 4: 
                searchGenre(); 
                break; 
            case 5: 
                clearScreen(); 
                System.out.println("You have now left the database"); 			
                break;  
            default: 
                System.out.println("Invalid: Enter a number between 1-3 ");
                clearScreen(); 
                menu(); 
                break;
        }  			

        return selection; 
    }
    public static void search() {
        Scanner input = new Scanner(System.in);
        System.out.println("Search Title >");
        String s = input.nextLine();
        int first = 0, last = books.size()-1, middle, location=0;
        boolean found = false;
        do{
            middle = (first + last) / 2;
            if(s.equals(books.get(middle).getTitle()))
                found = true;
            else if(s.compareTo(books.get(middle).getTitle())<0)
                last=middle-1;
            else 
                first = middle + 1;
        }while((!found) && (first <= last));
        if(found)
        {
            location = middle;
            printRecord(location);
            System.out.println(" Please press B to continue"); 
            String enter = input.next(); 
            while(enter.toLowerCase().equals("b")&& enter.toUpperCase().equals("b")){
                clearScreen(); 
                menu(); 
            }
        } 
        else
        {
            System.out.println("Sorry, book not found");
            System.out.println(" Please press B to continue"); 
            String enter_two = input.next();
            while(enter_two.toLowerCase().equals("b")&& enter_two.toLowerCase().equals("b")){
                clearScreen(); 
                menu(); 

            }
        }
    }
    public static void searchAuthor() {
        Scanner input = new Scanner(System.in);
        System.out.println("Search Author >");
        String s = input.nextLine();
        int first = 0, last = books.size()-1, middle, location=0;
        boolean found = false;
        int i =0; 
        while(i<books.size()) {
            if(books.get(i).getGenre().toLowerCase().contains(s)) {
                printRecord(i); 
                found =true; 
            } 
            i++; 
        }
        if(found)
        {

            System.out.println(" Please press B to continue"); 
            String enter = input.next(); 
            while(enter.toLowerCase().equals("b")&& enter.toUpperCase().equals("b")){
                clearScreen(); 
                menu(); 
            }
        } 
        else
        {
            System.out.println("Sorry, Author not found");
            System.out.println(" Please press B to continue"); 
            String enter_two = input.next();
            while(enter_two.toLowerCase().equals("b")&& enter_two.toLowerCase().equals("b")){
                clearScreen(); 
                menu(); 

            }
        }
    } 				
    public static void searchGenre() {
        Scanner input = new Scanner(System.in);
        System.out.println("Search Genre >");
        String s = input.nextLine();
        boolean found =false; 
        int i =0; 
        while(i<books.size()) {
            if(books.get(i).getGenre().toLowerCase().contains(s)) {
                printRecord(i); 
                found =true; 
            } 
            i++; 
        }
        if(found)
        {

            System.out.println(" Please press B to continue"); 
            String enter = input.next(); 
            while(enter.toLowerCase().equals("b")&& enter.toUpperCase().equals("b")){
                clearScreen(); 
                menu(); 
            }
        } 
        else
        {
            System.out.println("Sorry, Genre not found");
            System.out.println(" Please press B to continue"); 
            String enter_two = input.next();
            while(enter_two.toLowerCase().equals("b")&& enter_two.toLowerCase().equals("b")){
                clearScreen(); 
                menu(); 

            }
        }
    } 																																											
    // the method displays the records 
    public static void displayRecords() {
        String place; 
        int location =0; 
        clearScreen(); 
        do {
            Scanner input = new Scanner(System.in); 
            printRecord(location); 
            System.out.println("Please hit Return to continue or M fo Menu "); 
            place = input.nextLine(); 
            clearScreen(); 
            location++; 
        }while((!place.toLowerCase().equals("m"))&&(!place.toUpperCase().equals("m")) && location<books.size()); 
        clearScreen(); 
        menu(); 
    }
    public static void clearScreen(){
        System.out.println("\u001b[H\u001b[2J");


    }

} 	

