#!/usr/bin/perl
use diagnostics;
use warnings;
use feature 'say';
no warnings 'recursion';
my $max;
my $control;
my @num;
my @step;
my $steps;
my $dup;
my $dupIndex;
my $smallIndex;
my $small;
my $temp = 0;
my $size = 10; 
say "Please enter in a positive number";
$max = <STDIN>;
$control = $max;
#initialize array
for(my $i = 0; $i < $size;$i++)
{
    $step[$i] =0;
    $num[$i] = 0;
}
while($control > 1)
{
    $max = $control;
    $steps = collatz($max); 
    $max = $control;
    $dup = 0;
    $dupIndex = 0;
    $smallIndex = 0;
    $small = $step[0];
# update the smallest value
    for(my $i = 0; $i < $size; $i++)
    {
        if($step[$i] < $small)
        {
            $small = $step[$i];
            $smallIndex = $i;
        }
        if($step[$i] == $steps)
        {
            $dup = 1;
            $dupIndex = $i;
        }
    }
# if no duplicate is found add it to the list
    if($steps > $step[$smallIndex] and $dup == 0)
    {
        $step[$smallIndex] = $steps;
        $num[$smallIndex] = $max;
    }
# if a duplicate is found leave it out
    if($max < $num[$dupIndex] and $dup == 1)
    {
        $num[$dupIndex] = $max;
    }
    $control = $control - 1;
}
#bubble sort 
say "Sorted by sequence length";
for($j = 0; $j < $size-1; $j = $j + 1)
{
    for($k = 0; $k < $size-$j-1; $k = $k +1)
    {
        if($step[$k] > $step[$k +1])
        {
            $temp = $step[$k];
            $step[$k] = $step[$k+1];
            $step[$k+1] = $temp;

            $temp = $num[$k];
            $num[$k] = $num[$k+1];
            $num[$k+1] = $temp;
        }
    }
}
 
for(my $j = $size-1; $j >= 0; $j--)
{
    say $num[$j], "  ", $step[$j];
}
#bubble sort 
for($j = 0; $j < $size-1; $j = $j + 1)
{
    for($k = 0; $k < $size-$j-1; $k = $k +1)
    {
        if($num[$k] > $num[$k +1])
        {
            $temp = $num[$k];
            $num[$k] = $num[$k+1];
            $num[$k+1] = $temp;

            $temp = $step[$k];
            $step[$k] = $step[$k+1];
            $step[$k+1] = $temp;
        }
    }
}
say "sorted by integer length";
for(my $i = $size-1; $i >= 0; $i--)
{
    say $num[$i], "   ", $step[$i];
}

sub collatz{
    my ($n) = @_;
    if($n == 1) 
    {
        return 0; 
    }
    else
    {
        if($n & 1 == 1)
        {
            return 1 + collatz(($n<<1)+$n +1); 
        }
        else
        {
            return 1 + collatz($n>>1);
        }
    }
}
