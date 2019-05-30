#include <iostream>
#include <algorithm>
using namespace std;
// keep hold of the data in a struct 
struct numbers {
     long long  num;
     long long steps;
} c[10];

// prototype
long long numSteps( long long n);

int  main()
{
     int size = 10; 
     long long max;
    cout << "Enter a positive number"<<endl;
    cin >> max;

    // fill array
    for( long long i = 0; i < size; i++)
    {
        c[i].steps = 0;
        c[i].num = 0;
    }
    // number with largest amount
    while(max != 0)
    {
         long long stepnum = numSteps(max); 
        bool dup = false;
         long long smallest = 0;
         long long small = c[0].steps;
         long long dupIndex = 0;
        // loop through the first size elements
        for( long long i = 0; i < size; i++)
        {
            if(c[i].steps < small)
            {
                small = c[i].steps;
                smallest = i;
            }
            // if one has duplicate, eliminate it
            if(c[i].steps == stepnum)
            {
                dup = true;
                dupIndex = i;
            }
        }
         long long index = smallest;
        if(stepnum > c[index].steps && dup == false)
        {
            c[index].steps = stepnum;
            c[index].num = max;
        }
        if(max < c[dupIndex].steps && dup == true)
        {
            c[dupIndex].num = max;
        }
        max--;
    }
    cout << "Sorted based on sequence length"<< endl;
    sort(c,c+size,[] (numbers a, numbers b){return a.steps > b.steps;});
    for(long long  i = 0; i< size; i++)
    {
        cout << c[i].num << "     "<< c[i].steps << endl;
    }
    cout << "Sorted based on integer length"<< endl;
    sort(c,c+size,[](numbers a, numbers b){return a.num > b.num;});
    for(long long  i =0; i < size;i++)
    {
        cout << c[i].num << "      " << c[i].steps << endl;
    }
}

long long numSteps(long long n)
{ 
    if(n == 1)
    {
        return 0; 
    }
    else if ( n & 1)
    {
        return numSteps((n<<1)+n+1) + 1; 
    }
    else
    { 
        return  numSteps(n>>1) + 1; 
    }  
}
