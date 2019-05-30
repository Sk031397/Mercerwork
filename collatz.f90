program main
implicit none

    integer,dimension(10)::numArray,stepArray
    integer(kind=16)::i,steps,duplicate,smallIndex,small,dupIndex,control,input,numSteps,sizer,temp,j
    external numSteps
    sizer = 10 
    print *, "Please enter a positive number"
    read *, input
    control = input
    ! initialzie the array 
    do i = 1,sizer
        numArray(i) = 0
        stepArray(i) = 0
    end do

    do while(control .gt. 1)
        input = control
            steps = numSteps(input) 
            input = control
            duplicate = 0
            dupIndex = 1
            smallIndex = 1
            small = stepArray(1)
            do i = 1,sizer
                ! find the smallest number 
                if(stepArray(i) .le. small) then
                    small = stepArray(i)
                    smallIndex = i
                end if
                ! if a number appears more than once a duplicate has occured 
                if(stepArray(i) .eq. steps) then
                    duplicate = 1
                    dupIndex = i
                end if
                end do
                ! if a duplicate is not here than add the numbers to the arrays 
                if(steps > stepArray(smallIndex) .and. duplicate .eq. 0)then
                     stepArray(smallIndex) = steps
                     numArray(smallIndex) = input
                end if
                ! if a duplicate is here, than do not include the number 
                if(input < numArray(dupIndex) .and. duplicate .eq. 1)then
                    numArray(dupIndex) = input
                end if
                control = control - 1
                end do
                do j = sizer-1, 1,-1
                do i = 1, j
                    ! bubble sort 
                    If (stepArray(i) > stepArray(i+1)) THEN
                         temp = stepArray(i)
                         stepArray(i) = stepArray(i+1)
                         stepArray(i+1) = temp

                         temp = numArray(i)
                         numArray(i) = numArray(i+1)
                         numArray(i+1) = temp
                    end if
                    end do
                    end do
            print *, "Sorted by sequence length"
            do i = sizer,1,-1
                print *, numArray(i), "     ", stepArray(i)
            end do
             do j = sizer-1,1,-1
                do i = 1, j
                    ! bubble sort 
                    If (numArray(i) > numArray(i+1)) THEN
                         temp = numArray(i)
                         numArray(i) = numArray(i+1)
                         numArray(i+1) = temp

                         temp = stepArray(i)
                         stepArray(i) = stepArray(i+1)
                         stepArray(i+1) = temp
                    end if
                    end do
                    end do
            print *, "Sorted by integer length"
            do i = sizer,1,-1
                print *, numArray(i), "    ", stepArray(i)
            end do
  end program main
! calculate collatz conjecture 
recursive integer(kind=16) function numSteps(n) result(counter)

    integer(kind=16)::n 
    if( n == 1) then 
        counter= 0   
        return 
    else if (iand(n,1).eq.0 ) then
        counter = numSteps(shiftr(n,1))+ 1 
    else 
        counter = numSteps(shiftl(n,1)+n+1) + 1 
    end if 
    end function numSteps
