import java.util.*;
public class collatz
{
    public static void main(String[] args)
    {
        long max;
        System.out.println("Please enter a positive number");
        Scanner input = new Scanner(System.in);
        max = input.nextLong();
        int size = 10; 
        long [] num = new long[size];
        long [] step = new long[size]; 
        long temp; 
        // inialize array 
        for(int i = 0; i < size; i++)
        {
            num[i] = 0;
            step[i] = 0;
        }
        while(max != 0)
        {
            long stepnum = numSteps(max);
            boolean dup = false;
            long smallest = 0;
            long small = step[0];
            int dupIndex = 0;
           for(int i = 0; i < size; i++)
            {
                // find smallest number 
                if(step[i] < small)
                {
                   small = step[i];
                   smallest = i;
                }
                // if a number is seen more than once, a duplicate is there 
                if(step[i] == stepnum)
                {
                    dup = true;
                    dupIndex = i;
                }
            }
            int index = (int)smallest;
            // if a duplicate is not there, include both numbers 
            if(stepnum > step[index] && dup == false)
            {
                step[index] = stepnum;
                num[index] = max;
            }
            // if a duplicate is found, do not add it 
            if(max < step[dupIndex] && dup == true)
            {
                num[dupIndex] = max;
            }
            max--;
        }
           // bubble sort 
           for(int j = 0; j < (size -1); j++)
            for(int k = 0; k < (size - j -1);k++)
                 if(step[k] > step[k+1])
                 {
                    temp = num[k];
                    num[k] = num[k+1];
                    num[k+1] = temp;

                    temp = step[k];
                    step[k] = step[k+1];
                    step[k+1] = temp;
                 }

          System.out.println("Sorted based on sequence length");
        
        for(int i = size-1; i >=0 ; i--)
        {
            System.out.println(num[i] + "   " + step[i]);
        }
        // bubble sort 
        System.out.println("Sorted based on integer length");
          for(int j = 0; j < (size-1); j++)

            for(int k = 0; k < (size-j-1);k++)

                if(num[k] > num[k+1])
                {
                   temp = step[k];
                   step[k] = step[k+1];
                   step[k+1] = temp;

                   temp = num[k];
                   num[k] = num[k+1];
                   num[k+1] = temp;
                }
        for(int i = size-1; i >= 0;i--)
        {
            System.out.println(num[i] + "     " + step[i]);
        }
    }
// calculate collatz conjecture 
public static long numSteps(long n)
{
    long count = 0; 
    if(n == 1)
    {
      return count; 
    }
    else if ( (n & 1) == 0)
    {
        count = numSteps(n>>1) + 1; 
    }
    else
    {
        count = numSteps((n<<1)+n+1) + 1; 
    }
    return count; 
}

}
