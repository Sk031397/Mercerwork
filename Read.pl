#!/usr/bin/perl 
use strict;
use warnings;
use diagnostics;
use feature 'say';
my $allInput = "";  
my $file = $ARGV[0];
my $num_args = $#ARGV +1; 


if ( $num_args == 0) 
{
    say "Please enter a filename"; 
    $file = <STDIN>; 
    chomp $file;
    Openfile();  
}
Openfile();  
sub Openfile 
{
    open my $fh, '<', $file
        or die "Can't Open File:";
    while( my $info = <$fh>)
    { 
        $allInput .=$info;  
    }     
    close $fh or die "Couldn't close file: $_";
    printf("The Flesch Readability Index is %.1f\n",computeIndex()); 
    printf("The Flesch Kincaid Grade Index is %.1f\n",gradeIndex());   
} 
#goes through the file and adds all the words together 
sub countWords{
    my $words = 0; 
    my @line_words = split(/ /, $allInput);  
    $words+=@line_words;
    return $words;  

} # goes through the file and if following strings are found, a sentence is ending. 
sub countSentences{
    my $sentences = 0;   
    my $temp = '';       
    for ( my $i = 0; $i < length $allInput;$i++)
    {      
        $temp = substr($allInput,$i,1);  
        if($temp eq '?'||$temp eq '!' || $temp eq ':' || $temp eq ';' || $temp eq '.')
        {
            $sentences++; 
        } 

    } 
    return $sentences;   
}
# countSyllables in each individual word
# uses a regular expression  
sub countSyllables{
my @line = split(/ /, $allInput);
my $p;  
foreach(@line)
{
    $p+=s/(?!e[ds]$)[aeiouy]+//g; 
}
    return $p; 
} 
sub computeIndex{ 
    my $RGrade = 206.835 - 1.015 * ( countWords() / countSentences() ) - 84.6 * (countSyllables() / countWords() ); 
    return $RGrade; 
}

sub gradeIndex{
    my $KGrade = 11.8 * (countSyllables() / countWords()) + 0.39* (countWords() / countSentences() ) -15.59;  
    return $KGrade; 
}

