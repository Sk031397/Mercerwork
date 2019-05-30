import java.util.*;
import java.lang.*;
import java.math.BigInteger;
public class collatz_arb
{
    public static void main(String [] args)
    {
        // Initate needed variable
        BigInteger n; 
        int size = 10;
        BigInteger[] step = new BigInteger[size];
        BigInteger[] num = new BigInteger[size];
        Scanner input = new Scanner(System.in); 
        System.out.println("Enter a positive value");
        n = input.nextBigInteger(); 
        for (int i = 0;i<size;i++)
        {
            step[i] = new BigInteger("0");
            num[i] = new BigInteger("0");
        }

        // Initialize needed constant
        BigInteger Zero = new BigInteger("0");
        BigInteger One = new BigInteger("1");
        BigInteger Two = new BigInteger("2");
        BigInteger Three = new BigInteger("3");

        // Initialize needed variable
        BigInteger count = new BigInteger("0");
        BigInteger steps = new BigInteger("0");
        BigInteger temp = new BigInteger("0");
        BigInteger swap = new BigInteger("0");
        count = n;

        // Run from n to 1
        while (count.compareTo(Zero) > 0)
        {
            temp = count;
            steps = Zero;

            // Find stepsatz number
            while(temp.compareTo(One) > 0)
            {
                while((temp.and(One).compareTo(One)==0))
                {
                    temp = temp.multiply(Three);
                    temp = temp.add(One);
                    temp = temp.divide(Two);

                    steps = steps.add(Two);
                }
                while((temp.and(One).compareTo(Zero)==0))
                {
                    temp = temp.divide(Two);
                    steps = steps.add(One);
                }
            }

            // checks to see if the 
            if (steps.compareTo(step[0]) >0)
            {
                boolean check = true;
                for (int j = 0; j<size;j++)
                    if (steps.compareTo(step[j]) ==0)
                    {
                        check = false;
                        num[j] = count;
                    }

                if (check)
                {
                    step[0] = steps;
                    num[0] = count;

                    // Bubble sort
                    for (int j=0; j<(size-1);j++)
                        for (int k = 0; k < (size-j-1); k++)
                            if (step[k].compareTo(step[k+1])>0)
                            {
                                swap = step[k];
                                step[k] = step[k+1];
                                step[k+1] = swap;

                                swap = num[k];
                                num[k] = num[k+1];
                                num[k+1] = swap;
                            }
                }
            }
            count = count.subtract(One);
        }

        // Print the result by sequence length
        System.out.println("\nSort by sequence length: ");
        for (int i = size-1; i>=0; i--)
        {
            System.out.println(num[i].toString() + " " + step[i].toString()); 
        }

        // Sort by integer size
        for (int j=0; j<(size-1);j++)
            for (int k = 0; k < (size-j-1); k++)
                if (num[k].compareTo(num[k+1])>0)
                {
                    swap = step[k];
                    step[k] = step[k+1];
                    step[k+1] = swap;

                    swap = num[k];
                    num[k] = num[k+1];
                    num[k+1] = swap;
                }

        // Print the result by integer size
        System.out.println("\nSort by Integer Size: ");
        for (int i = size-1; i>=0; i--)
        {
            System.out.println(num[i].toString() + " " + step[i].toString()); 
        }
    }
}

