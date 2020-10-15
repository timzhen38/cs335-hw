Tim Zhen

i.
Q1 Part 1 complete
Q1 Part 2 complete
Q1 Part 3 complete
ii.
- findPos is a const function so I wasnt able to alter the value of num_collisions so I put mutable behind it when declaring it in the private members
- sometimes collisions wouldnt be resetting back to 0 and the problem was that I did not reset the collisions everytime we were making it empty 
- I was getting too many probes when I was running the probe count function and I fixed this    by making the condition that the hash table DOES not contain the word an else statement instead of an else if statement
- I was getting an std::out of range error for spell check but the bug was in my removing punctuations function because when I removed a punctuation in my original function, I forgot to account for the string length decreasing
- I was having trouble with appending characters or removing characters at the end of a word with my original formulas so I added code at the end of case A and B just to deal with appending or removing characters at the end of a word
iii.
- for Q1 part 1 you just compile with make create_and_test_hash and run with 
./create_and_test_hash <words file name> <query words file name> <flag>
- for Q1 part 2 it's
./create_and_test_hash <words file name> <query words file name> double <R-VALUE>
and the R-value I used for testing was 44
- for Q1 part 3 it's make spell_check and running it with ./spell_check <document_file> <dictionary_file>
 
iv.
- input files for Q1 part1 and part2 are query_words.txt and words.txt
- input files for Q1 part 3 are document1.txt, wordsEN.txt and document1_short.txt
