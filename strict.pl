#!/usr/bin/perl
use strict;
use Quote;

my $quote = Quote->new(); 
my $phrase = "Foo"; 
my $author = "Bar";
$quote->set_phrase($phrase);
$quote->set_author($author);
print STDOUT $quote->get_phrase(),"\n";
print STDOUT $quote->get_author(), "\n"; 
print STDOUT ($quote->is_approved() ? "is not approved": "Is approved"), "\n\n";


my $phrase2 = "Baz";
my $author2 = "Foo";

my $quote2 = Quote->new();
$quote2->set_phrase($phrase2);
$quote2->set_author($author2);

print STDOUT $quote2->get_phrase(), "\n";
print STDOUT $quote2->get_author(), "\n";
print STDOUT ($quote2->is_approved() ? "Is approved" : "Is not approved"), "\n";

exit 0;
