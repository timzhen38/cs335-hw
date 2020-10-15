Tim Zhen's README.txt
---------------------------------------
i.
- Completed the two permutation functions
- Completed entirety of question 2

ii.
- I was getting a read-only reference error for the permute(str,low,high) function because
I couldnt use swap on a const string so I instantiated a normal string and set it equal to
the string in the parameter then I permuted that normal string I instantiated
- I was constantly getting a memory error when I tried test running the test_points2
file on my machine but when I tried running it on gradescope it compiled successfully

iii.
- make a main.cpp file that includes the "permute.h" then create a int main() function 
like this:
#include "permute.h"
int main()
{
    string test = "abc";
    permute(test);
    return 0;
}
then you can run it in terminal with "g++ main.cpp -o program" and ./program

- you can just run test_points2.cc with "g++ test_points2.cc -o test_points2" and 
doing either ./test_points2 or ./test_points2 < test_input_file.txt

iv.
- input file for second question is test_input_file.txt
