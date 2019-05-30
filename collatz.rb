#!/usr/bin/ruby

class Collatz 
def main
begin 
puts "Please enter a positive number"
max = gets.to_i
control = max
size = 10 
num = []
step = []
# zero array 
for i in 0..10
step[i] = 0
num[i] = 0
end

while control > 1
max = control
steps = Collatz.new.nSteps(max) 
max = control
dup = false
dupIndex = 0
smallIndex = 0
small = step[0]
# find the smallest in the arrya 
for i in 0..10
if step[i] < small
small = step[i]
smallIndex = i
end
# a duplicate is foudn 
if step[i] == steps
dup = true
dupIndex = i
end
end
# if a duplicate is not found, then add it to the array 
if steps > step[smallIndex] and dup == false
step[smallIndex] = steps
num[smallIndex] = max
end
# if a duplicate is foudn, do not add it 
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

end  
end 
#calcualte collatz conjecture 
def nSteps(n)
    if n == 1
        return 0 
    elsif n & 1 == 1
        return 1 + nSteps((n<<1)+1+n)
    else
        return 1 + nSteps(n>>1)
    end
end
end

test = Collatz.new.main()  
