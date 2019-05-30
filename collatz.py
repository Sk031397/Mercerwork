#!/usr/bin/python

def start():
    maximum = input("Enter a positive number\n")
    control = maximum
    size = 10  
    # zero out array 
    step = [0 for i in range(size) ] 
    num = [0 for i in range(size) ]  
     
    while control > 1:
        maximum = control
        steps = collatz(maximum)
        maximum = control  
        dup = False
        dupIndex = 0
        smallIndex = 0
        small = step[0] 
        for i in range(size):
            # fidn teh smallest number in the array 
            if(step[i] < small):
                small = step[i]
                smallIndex = i
            # a duplicate is foudn 
            if(step[i] == steps):
                dup = True
                dupIndex = i
        # if a duplicate is not found, then add the numbers to the array 
        if(steps > step[smallIndex] and dup == False):
            step[smallIndex] = steps
            num[smallIndex] = maximum
        # if a duplicate is found, do not add it 
        if(maximum < num[dupIndex] and dup == True):
            num[dupIndex] = maximum
        control = control - 1
    for i in range(size -1):
        # bubble sort 
        if step[i] > step[i+1]:
            step[i], step[i+1] = step[i+1], step[i]
            num[i],num[i+1] = num[i+1],num[i]
    print "Sorted by sequence length"
    for i in range(size-1,-1,-1):
        print num[i], "  ", step[i]
    for i in range(size -1):
        #bubble sort 
        if num[i] > num[i+1]:
            num[i], num[i+1] = num[i+1], num[i]
            step[i],step[i+1] = step[i+1],step[i]
    print "Sorted by integer length"
    for i in range(size-1,-1,-1):
        print num[i], "  ", step[i]
    return 
# calculae collatz conjecture 
def collatz(n):
    if n == 1: 
       return 0 
    elif ( n & 1 == 1):
        return 1 + collatz((n<<1)+n+1) 
    else:
         return 1 + collatz(n>>1)                                 
    return 

start() 
