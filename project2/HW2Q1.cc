//Tim Zhen
//Looks for an object using iterators

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/*
start: starting range
end: last index and returned if object can not be found
x: object we are looking for
*/
template <typename Iterator, typename object>
Iterator my_find(Iterator start, Iterator end, const object & x)
{
    while (start < end-1) //loop that begins at start and ends at the object before end
    {
        if (*start == x) //have to convert start to pointer in order to compare pointers
            return start;
        start++;
    }
    return end; //return end if the object is not found
}

/*int main()
{
    int intArr[] = {1,2,3,4};
    int *p;

    p = my_find(intArr,intArr+3,2);
    cout << *p;
}*/