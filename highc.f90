program main 
integer(kind=16)::minimum,maximum,largeone,largetwo,largest,numSteps,step 
integer(kind=16),dimension(10)::listone,listtwo
external numSteps
    print *, "Please enter in a intial value"
    read *, minimum 
    print *, "Please enter a final value"
    read *, maximum 
    do i = 1,10 
        listone(i) =0 
        listtwo(i)=0
    end do    
       do i = 1,10 
           listone(i) = numSteps(minimum)
            listtwo(i) = numSteps(maximum) 
        end do 
        largeone = listone(
        do i = 1,10 
            if(largeone < listone(i)) then 
                largeone = listone(i) 
            end if 
        end do 
        largetwo = listtwo(1)
        do i = 1,10
            if(largetwo < listtwo(i)) then
                largetwo = listtwo(i)
            end if
        end do
        largest = 0 
        if(largeone > largetwo) then 
            largest = largeone
        else 
            largest = largetwo 
        end if 
        print *, largest 
 
end program main 


recursive integer(kind=16) function numSteps(n) result(counter)

    integer(kind=16)::n
    if( n == 1) then
        counter= 0
        return
    else if (mod(n,2)== 0 ) then
        counter = numSteps(n/2)
    else
        counter = numSteps(n*3+1)  
    end if
    end function numSteps
 
