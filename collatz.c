#include <stdio.h>



unsigned short result[MAXNUM];

long long int collatz(long long int n,long long int largestVal)
{
    if(n == 1)
    {
        return largestVal; 
    }   
    else if (n % 2 == 1)
    {
        if(largestVal < n)
        {
            largestVal = n; 
            return collatz(n * 3 + 1,largestVal);
        }
        collatz(n*3+1,largestVal); 
    }
    else
    {
    if(largestVal < n)
    {
        largestVal = n;
        return collatz(n/2,largestVal);
    }
        collatz(n/2,largestVal);
    }
}

int main()
{
    long long int largestVal = 1; 
    long long int x = 11; 
    largestVal = collatz(x,largestVal);
    printf("%d\n",largestVal);
    return 0;
}
