with Ada.Text_IO;
with Ada.Float_Text_IO;
use Ada.Text_IO;
use Ada.Float_Text_IO;

procedure collatz is
-- calculate the collatz conjecture 
function numSteps(num:Long_Integer) return Long_Integer is 
    count:Long_Integer:=0;
    n:Long_Integer:=num; 
    begin 
        if(n = 1) then 
            return count; 
        elsif ( n mod 2 = 1) then   
            count:=numSteps(3*n+1)+1;
        else 
            count:=numSteps(n/2)+1;
        end if;
    return count; 
    end numSteps; 
maximum:Long_Integer;
control:Long_Integer;
num:array(1..10) of Long_Integer;
step:array(1..10) of Long_Integer;
steps:Long_Integer;
dup:Boolean:=False;
dupIndex:Integer;
smallIndex:Integer;
small:Long_Integer;
size:Integer:=10;
temp:Long_Integer; 
begin
Put_Line("Please enter a postive number");
maximum:=Long_Integer'Value(Get_Line);
control:=maximum;
-- initialize the arrary
for i in 1..10 loop
num(i):=0;
step(i):=0;
end loop;
while control > 1 loop
maximum:=control;
steps:=numSteps(maximum);
maximum:=control;
dup:=False;
dupIndex:=1;
smallIndex:=1;
small:=step(1);
-- check for the smallest value 
for i in 1..10 loop
if(step(i) < small) then
small:=step(i);
smallIndex:= i;
end if;
if(step(i) = steps) then
dup:=True;
dupIndex:=i;
end if;
end loop;
-- if a duplicate is not found update the arrays 
if(steps > step(smallIndex) and dup=False) then
step(smallIndex):=steps;
num(smallIndex):=maximum;
end if;
-- if a duplicate is found do not add the same step more than once 
if(maximum < num(dupIndex) and dup=True) then
num(dupIndex):=maximum;
end if;
control:=control - 1;
end loop;
for i in 1..size-2 loop
for k in 1..size-i loop
-- bubble sort
if step(k) > step(k+1) then
temp:= step(k);
step(k):= step(k+1);
step(k+1):= temp;

temp:=num(k);
num(k):=num(k+1);
num(k+1):=temp;
end if;
end loop;
end loop;
-- sort the array by seq length in reverse order 
Put_Line("Sorted by sequence length");
for i in reverse 1..size loop
Put_Line(Long_Integer'Image(num(i)) & Long_Integer'Image(step(i)));

end loop;
for i in 1..size-2 loop
for k in 1..size-i loop
-- bubble sort
if num(k) > num(k+1) then
temp:=num(k);
num(k):=num(k+1);
num(k+1):=temp;

temp:=step(k);
step(k):=step(k+1);
step(k+1):=temp;
end if;
end loop;
end loop;
-- sort the array by integer length in reverse order 
Put_Line("Sorted by integer length");
for i in reverse 1..size loop
Put_Line(Long_Integer'Image(num(i)) & Long_Integer'Image(step(i)));
end loop;

end collatz;
