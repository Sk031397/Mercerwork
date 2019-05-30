#!/usr/bin/python
size = 10 
maximum = input("Enter a positive number\n")
control = maximum 

num = [0 for i in range(size)]
step = [0 for i in range(size)]

while control > 1:
    maximum = control
    steps = 0
    # calculate collatz conjecture  
    while maximum > 1:
        if maximum & 1 == 1:
            maximum = (maximum << 1) + 1 + maximum  
        else:
            maximum= maximum >> 1 
        steps = steps + 1 
    maximum = control   
    dup = False
    dupIndex = 0 
    smallIndex = 0 
    small = step[0]
    for i in range(size):
        # find the smallest number 
        if(step[i] < small):
            small = step[i]     
            smallIndex = i 
        # find duplicate numbers 
        if(step[i] == steps):
            dup = True
            dupIndex = i 
    # if the duplicate are not foudn, add them 
    if(steps > step[smallIndex] and dup == False):
        step[smallIndex] = steps
        num[smallIndex] = maximum 
    # if a duplicate do not add it 
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
    # bubble sort 
    if num[i] > num[i+1]:
        num[i], num[i+1] = num[i+1], num[i]
        step[i],step[i+1] = step[i+1],step[i]
print "Sorted by integer length" 
for i in range(size-1,-1,-1):
    print num[i], "  ", step[i] 
