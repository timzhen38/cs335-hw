Tim Zhen
i.
Q1 Done
Q2 Done

ii.
- my verifyOrder function was taking forever to run but it turned out to be that I forgot 
to set input_vector equal to the vector that the generateVector functions return. I just called
GenerateVector without doing anything with it.
- I had to move some functions around in sort.h because some functions using other functions
inside it, could not detect the declaration of the function if it was after it on the file
- my middle pivot quicksort was not correctly sorting the array but i realized I needed a helper function similar to median3 which moved the pivot to position right-1
- My quick sorts were not working with greater comparator but the error was that i did not modify the insertion sort to have a comparator as a parameter

iii.
- compile it with g++ test_sorting_algorithms.cc -o program -std=c++11
- run it with ./program <sorted/random> <num> <less/greater>

iv.
no input or output files
