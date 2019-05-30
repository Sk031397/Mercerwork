using System;

struct numbers
{
    public long nums;
    public long steps;
}

class Collatz
{

    static void Main(string [] args)
    {
        int size = 10; 
        numbers [] c = new numbers[size];
        long max;
        Console.WriteLine("Please enter in a positive number");
        max = Convert.ToInt32(Console.ReadLine());

        // fill array
        for(long i = 0; i < size;i++)
        {
            c[i].nums = 0;
            c[i].steps = 0;
        }
        while(max != 0)
        {
            long stepnum = nSteps(max);
            bool dup = false;
            long smallest = 0;
            long small = c[0].steps;
            long dupIndex = 0;
            // find the smallest value 
            for(long i = 0; i < size; i++)
            {
                if(c[i].steps < small)
                {
                    small = c[i].steps;
                    smallest = i;
                }
                // if what is in the array is equal to the list say a duplicate is found  
                if(c[i].steps == stepnum)
                {
                    dup = true;
                    dupIndex = i;
                }
            }
            long index = smallest;
            // a duplicate is not found, then add numbers to the arrays 
            if(stepnum > c[index].steps && dup==false)
            {
                c[index].steps = stepnum;
                c[index].nums = max;
            }
            // if a duplicate is found, add only the number 
            if(max < c[dupIndex].steps && dup==true)
            {
                c[dupIndex].nums = max;
            }
            max--;
        }
        // sort based on seq Length 
        Console.WriteLine("Sorted by sequence length");
        Array.Sort(c,delegate(numbers a, numbers b) {return a.steps.CompareTo(b.steps);});
        for(long i = size-1; i>=0; i--)
        {
            Console.WriteLine(c[i].nums + "    " + c[i].steps);
        }
        // Sort based on integer Length 
        Console.WriteLine("Sorted by integer length");
        Array.Sort(c,delegate(numbers a, numbers b) {return b.nums.CompareTo(a.nums);});
        for(long i = 0; i <size ; i++)
        {
            Console.WriteLine(c[i].nums + "    " + c[i].steps);
        }
    }
     // calculate collatz conjecture 
    static long nSteps(long n)
    {
        long count = 0;
        if(n == 1) 
        {
            return count; 
        }
        else if ( (n & 1)==0 )
        {
            count = nSteps(n>>1) + 1; 
        }
        else
        {
            count = nSteps((n<<1)+n+1)+1;
        }
        return count; 
    }
}

