#!/usr/bin/ruby 

size = 10 
puts "Please enter a positive number"
max = gets.to_i
control = max 

num = [] 
step = [] 
# zero out array 
for i in 0..size
    step[i] = 0
    num[i] = 0
end 

while control > 1
    max = control 
    steps = 0
    # calculate collatz conjecture 
    while max > 1
        if max & 1 == 1
            max = (max << 1) + 1 + max
        else 
            max = max >> 1
        end 
    steps = steps + 1
    end 
    max = control 
    dup = false
    dupIndex = 0 
    smallIndex = 0
    small = step[0] 
    for i in 0..size
        # find the smalest number 
        if step[i] < small 
            small = step[i] 
            smallIndex = i  
        end 
        # a duplicate is here 
        if step[i] == steps
            dup = true
            dupIndex = i 
        end 
      end 
        # if a duplicate is not found, add the numebrs 
        if steps > step[smallIndex] and dup == false
            step[smallIndex] = steps
            num[smallIndex] = max
        end 
        # if a duplicate is found, do not add it 
        if max < num[dupIndex] and dup == true
            num[dupIndex] = max
        end 
    control = control - 1 
    end 
    # bubble sort 
    size.times do |j|
        for i in 0...size
            if step[i] < step[i+1] 
                step[i],step[i+1] = step[i+1], step[i] 
                num[i], num[i+1] = num[i+1], num[i] 
            end
        end 
    end 
puts "Sorted by sequence length"
for i in (0..size-1)
    print num[i], "   ", step[i], "\n"
end 
#bubble sort 
size.times do |j| 
    for i in 0...size
        if num[i] < num[i+1] 
            num[i],num[i+1] = num[i+1], num[i] 
            step[i],step[i+1] = step[i+1],step[i] 
        end 
    end
    end 
puts "Sorted by integer length"
for i in (0..size)
    print num[i], "   ", step[i], "\n"
end

