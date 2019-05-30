println("Please enter a initial value")
minimum = readline() 
minimum = parse(Int64,minimum)
println("Please enter a final value")
maximum = readline()
maximum = parse(Int64,maximum) 

listone = Array{Int64}(10)
zeros(listone)
listtwo = Array{Int64}(10) 
zeros(listtwo)
counter = 0
for i=1:10
        if minimum % 2 == 0 
            minimum = minimum / 2
        else 
            minimum = minimum * 3 + 1 
        end 
    counter = counter + 1 
    listone[i] = minimum 
    end  
      for i=1:10
        if maximum % 2 == 0
            maximum = maximum / 2
        else
            maximum = maximum * 3 + 1
        end
    counter = counter + 1
    listtwo[i] = maximum
    end

    largeone = listone[1] 
    for i=1:10
        if largeone < listone[i] 
            largeone = listone[i] 
        end 
    end
      largetwo = listtwo[1] 
      for i=1:10
        if largetwo < listtwo[i]
            largetwo = listtwo[i]
        end
    end

        largest = 0 
        if(largeone > largetwo) 
            largest = largeone 
        else 
            largest = largetwo 
    end 
        println(largest) 
