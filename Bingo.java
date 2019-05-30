 import java.util.*; 
 import java.math.*; 
 import java.io.*; 
 import java.lang.*;  
 	public class Bingo extends Thread{  
 	 
    	private static ArrayList<Integer> win = new ArrayList<Integer>(75);
 	private static final int HORIZONTAL=1;
  	private static final int VERTICAL=2;
  	private static final int DIAGONAL=3;
  	private static int [][]card = new int[5][5]; 
  	private static BitSet random = new BitSet(76);
  	private static int count =0; 
 		public static void main(String[] args ) throws IOException,InterruptedException {   
    
 	  
      		 fillCard(card);  
 	     	 printCard(card); 	
 	         playGame(card); 
 		 printCard(card);  
 		 int win = checkForWin(card); 	
		 System.out.print(win); 
 		  if(win==1) {
			System.out.print(" You win HORIZONTALLY\n"); 
				}		 
		else if(win==2){
		System.out.print(" You win VERTICALLY\n"); 
		} 
		else if(win==3) {
		System.out.print(" You win DIAGNOLLAY\n"); 
	}
	else{
		System.out.print("You Lose\n"); 
	} 
  
 }
  	
 	/* @param array named card that references the array in main 
 */
 	public static void fillCard(int[][]card) throws IOException {		
 	Scanner input = new Scanner(new File("bingo.in")); 
 	int i;
 	for(int row = 0; row < card.length; row++ ) {
 		for(int col = 0; col< card[row].length; col++) {
                 i = input.nextInt();
 		card[row][col]= i; 
    
  	   
 }
  
 }
 	
 }
 /* @param array named card that references the array in the main method */ 
 
  public static void printCard(int[][]card) throws InterruptedException
    
   {
 	String title[] = {"B","I","N","G","O"}; 
 	for(int i = 0; i < title.length; i++) 
 {
 	System.out.print(title[i] + "\t"); 
 
 }
 	System.out.println(); 
        for (int r = 0; r < card.length; r++)
       {
          System.out.println("|-----|-----|-----|-----|-----|-----|-----|");
 	for (int c = 0; c < card[r].length; c++){
      	if(card[r][c]==0){
	Thread.sleep((int)(Math.random()*2000)); 
  	  System.out.printf("|%3s\t",'X'); }
      else{
 	  System.out.printf("|%3s\t",card[r][c]);
 }
       }
       	System.out.println();
   }
 
 
 }	/*  @param card references main array and random represents the random bitset in main  

*/  
          public static void drawNumber(BitSet random,int[][] card) throws InterruptedException
 {
 
              int  n = ((int)(Math.random()*75 + 1));
                       
                 while(random.get(n)==true)
                 {
                        n = ((int)(Math.random()*75 + 1));
                        break; 
                  }
                 if(random.get(n)==false){
                     random.set(n);
	 
                     }
                   
                 for(int i=0; i<card.length; i++)
                             {
        		 for(int j=0; j<card.length; j++){
                           if(card[i][j] == n){  
                             card[i][j] = 0;
}
                                                        }
                                   }
      	          win.add(n); 
	System.out.println(n); 
}
			
/* plays Bingo, marks off the card and how many numbers were generayed until a bingo was found and the way that you won bingo  
*/
  	public static void playGame(int[][] card)throws InterruptedException  { 

  System.out.print("Bingo card picked at random from bin:\n");

                // Initialize the new integer winType with the value 0.
                int winType = 0;

                // For the maximum possible amount of picked card (75), pick a random number and determine if a win has occurred.
                
		for (int i=0; i<75; i++)
                {
                        // Pick a random number that has not been picked before.
                        drawNumber(random, card);

                        // Determine if a win has occurred and set the winType integer to the corresponding win type.
                               
                        if(winType == 1)
                        { 
                               System.out.println("\n\nYou win  after " + (i+1) + " picks!");
                                break;
                        }

                        if(winType == 2)
                        {
                                System.out.println("\n\nYou win after " + (i+1) + " picks!");
                                break;
                        }

                        if(winType == 3)
                        {
                                System.out.println("\n\nYou win with after " + (i+1) + " picks!");
                                break;
                        }
			winType = checkForWin(card); 	 
			
                }
		  	
			
        }

// returns and integer that holds the type of win that you have. Returns 1 if horizontal, 2 if vertical and 3 if diagnol 
//
public static int checkForWin(int[][] card)
        {
                // Declare the new integers rowSum, colSum, and diagSum.
                int rowSum, colSum, diagSum;

                // Initialize the new integers HORIZONTAL, VERTICAL, and DIAGONAL with constant values 1, 2, and 3, respectively.
                final int HORIZONTAL = 1;
                final int VERTICAL = 2;
                final int DIAGONAL = 3;

                // Initialize the new integer winType with the value 0.
                int winType = 0;

                // Calculate the sum of each row and exit the method if a bingo has occurred.
                for(int i=0; i<card.length; i++)
                {
                        rowSum = 0;

                        for(int j=0; j<card[i].length; j++)
                                rowSum += card[i][j];
  
                        if(rowSum == 0)
                        {
                                winType = HORIZONTAL;
                               return winType;
                        }

        			}         
	
                // Calculate the sum of each column and exit the method if a bingo has occurred.
                for(int j=0; j<card[0].length; j++)
                {
                        colSum = 0;

                        for(int i=0; i<card.length; i++) 
                                colSum += card[i][j];
 
	
                        if(colSum == 0)
                        {
                                winType = VERTICAL;
                                return winType;
                        }
                

		}  
                // Set the integer diagSum to the value 0.
                diagSum = 0;

                // Calculate the sum of the main diagonal.
                for(int i=0; i<card.length; i++)  { 
                        diagSum += card[i][i];   } 

                // Exit the method if a bingo has occurred.
                if(diagSum == 0)
                {
                        winType = DIAGONAL;
                        return winType;
                }

                // Set the integer diagSum to the value 0.
                diagSum = 0;

                // Calculate the sum of the secondary diagonal.
                for(int i=0; i<card.length; i++)  { 
                        diagSum += card[i][card.length-i-1];
}
                // Exit the method if a bingo has occurred.
                if(diagSum == 0)
                {
                       winType = DIAGONAL;
                       return winType;
                }

                // Return winType as 0 if no bingo has occurred.
                return winType;
        }
 
}


