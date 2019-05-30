size = 10
# calculate collatz conjecture 
function collatz(n)
    counter = 0 
    if n == 1 
        counter = 0 
    elseif n & 1 == 1
        counter = 1 + collatz((n << 1)+ n + 1)
    else 
        counter = 1 + collatz(n >> 1)
    end 
    return counter 
end

println("Please enter a positive number")
maximum = readline()
maximum = parse(Int64,maximum)
control = maximum
numArray = Array{Int64}(size)
# zero arrays 
zeros(numArray)
stepArray = Array{Int64}(size)
zeros(stepArray)
while control > 1
    maximum = control
    steps = collatz(maximum)
    maximum = control
    dup = false
    dupIndex = 1
    smallIndex = 1
    small = stepArray[1]
    for i = 1:10
        # find smallest in array 
        if stepArray[i] < small
            small = stepArray[i]
            smallIndex = i
        end
        # duplicate is foudn 
        if stepArray[i] == steps
            dup = true
            dupIndex = i
        end
    end
        # if a duplicate is not found, add the number 
        if steps > stepArray[smallIndex] && dup == false
            stepArray[smallIndex] = steps
            numArray[smallIndex] = maximum
        end
        # if a duplicate is foudn, do not add it
        if maximum < numArray[dupIndex] && dup == true
            numArray[dupIndex] = maximum
        end
        control = control - 1
    end
    # bubble sort 
     for i in 2:size
        for j in 1:size-1
            if stepArray[j] > stepArray[j+1]
                temp = stepArray[j]
                stepArray[j] = stepArray[j+1]
                stepArray[j+1] = temp

                temp = numArray[j]
                numArray[j] = numArray[j+1]
                numArray[j+1] = temp
            end
            end
            end
    println("Sorted by sequence length")
    for i = size:-1:1
        println(numArray[i], "  ", stepArray[i])
    end
        # bubble sort 
        for i in 2:size
        for j in 1:size-1
            if numArray[j] > numArray[j+1]
                temp = numArray[j]
                numArray[j] = numArray[j+1]
                numArray[j+1] = temp

                temp = stepArray[j]
                stepArray[j] = stepArray[j+1]
                stepArray[j+1] = temp
            end
            end
            end
    println("Sorted by integer length")
    for i = size:-1:1
        println(numArray[i], "  ", stepArray[i])
    end

