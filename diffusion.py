#!/usr/bin/python 
import time 
maxsize= input("How big is the cube?\n")
A = [[[0.0 for k in range(maxsize)] for j in range(maxsize)] for i in range(maxsize)]
diffusion = 0.175
room = 5.0 
speed = 250 
timestep = (room / speed) / maxsize
distance = room / maxsize 
dC = (diffusion * timestep) / (distance * distance ) 
A[0][0][0] = 1.0 * 10 **21  
tacc = 0.0 
ratio =0.0 
mid = maxsize /2
# flag to see if the partition was set on or not 
choice = input("Do you want to add a partition?\n1:Yes\n2:No\n")
t0 = time.time() 
if choice == 1:
     for i in range(0,maxsize):
        for j in range(0,maxsize):
            for k in range(0,maxsize):
                if (i == mid -1) and (j>= mid -1):
                    A[i][j][k] = -1.0 
# loops through each cube while the ratio is less than 99%
while (ratio <=0.99) :
# loops through each cube and checks if each cube is not equal to each other 
    for i in range(0,maxsize):
        for j in range(0,maxsize):
            for k in range(0,maxsize):
             if A[i][j][k]!=-1:
               if k!=0 and A[i][j][k-1]!=-1: 
                         change = (A[i][j][k] - A[i][j][k-1] ) * dC
                         A[i][j][k] = A[i][j][k] - change
                         A[i][j][k-1] = A[i][j][k-1] + change 
               if k!=maxsize-1 and A[i][j][k+1]!=-1: 
                         change = (A[i][j][k] - A[i][j][k+1] ) * dC
                         A[i][j][k] = A[i][j][k] - change
                         A[i][j][k+1] = A[i][j][k+1] + change
               if j!=0 and A[i][j-1][k]!=-1:
                         change = (A[i][j][k] - A[i][j-1][k] ) * dC
                         A[i][j][k] = A[i][j][k] - change
                         A[i][j-1][k] = A[i][j-1][k] + change
               if j!= maxsize -1 and A[i][j+1][k]!=-1:
                         change = (A[i][j][k] - A[i][j+1][k] ) * dC
                         A[i][j][k] = A[i][j][k] - change
                         A[i][j+1][k] = A[i][j+1][k] + change
               if i!=0 and A[i-1][j][k]!=-1:
                         change = (A[i][j][k] - A[i-1][j][k] ) * dC
                         A[i][j][k] = A[i][j][k] - change
                         A[i-1][j][k] = A[i-1][j][k] + change
               if i!= maxsize-1 and A[i+1][j][k]!=-1:
                         change = (A[i][j][k] - A[i+1][j][k] ) * dC
                         A[i][j][k] = A[i][j][k] - change
                         A[i+1][j][k] = A[i+1][j][k] + change
    tacc = tacc + timestep
    # mass consistency 
    sumval = 0.0 
    maxc,minc = A[0][0][0],A[0][0][0]
    # find the maximum and minimum of each cube 
    for i in range(0,maxsize):
        for j in range(0,maxsize):
            for k in range(0,maxsize):
              if A[i][j][k]!=-1:
                maxc = max(A[i][j][k],maxc)
                minc = min(A[i][j][k],minc)    
                sumval = sumval + A[i][j][k]   
    ratio = minc / maxc   
    print ("ratio %f"% ratio ,"sumval %f"%sumval, "maxval %f" %maxc, "minval %f"%minc)   
print ("Box equilibrated in %.2f" %tacc) 
t1 = time.time()
# calculate the wall time after the function is completed  
wall = t1 - t0 
print "Wall Time", wall  
