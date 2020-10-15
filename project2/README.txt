Tim Zhen

i. 
Completed Q1
Completed Q2 pt 1
Completed Q2 pt 2a
Completed Q2 pt 2b
Completed Q2 pt 2c

ii.
- For 2a, I encountered a bug where I was printing too many enzyme acronyms for each recognition sequence but it turned out I did the merge function wrong because I did not read that the recognition sequences had to be equal to each other
- for 2b, it was not allowed to put another private variable into the avl tree class so I had to put it at the top of the class
- for 2b, the number of nodes in my tree was only 27 and it turned out the problem was the operator> from my sequence_map.h, i had written it wrong. I had compared lengths of the strings instead of the strings themselves
- for 2b, my call for recursions of remove was too large which caused 4b to be too large of a number so I made counter = 2 so i could proceed with trying pt 2c

iii.
- for 1 you can just comment out the main function or create your own and run it after compiling
- for 2a, type in make query_tree and either run ./querytree rebase210.txt and put in your own inputs or ./querytree rebase210.txt < input_part2a.txt
- for 2b, type in make test_tree and run ./test_tree rebase210.txt sequences.txt
- for 2c, its the same for 2b but its make test_tree_mod

iv.
input files for everything is rebase210.txt and/or sequences.txt
