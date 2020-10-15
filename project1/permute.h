//Tim Zhen
//Permutes a string and lists all possible permutations of that string

#ifndef PERMUTE_H_
#define PERMUTE_H_

#include <iostream>
using namespace std;

/*
@str: string you're permuting
@low: starting index
@high: last index
*/
void permute(const string str, int low, int high)
{
    string toPerm = str;
    if (low == high)
        cout << toPerm << endl; //prints the permutations
    else
    {
        for (int i = low; i <= high; i++)
        {
            swap(toPerm[i],toPerm[low]); //swap the two indexes
            permute(toPerm,low+1,high); //recursion line
            swap(toPerm[low], toPerm[i]); //backtrack
        }
    } 
}

/*
@str: the string you're permuting 
*/
void permute(const string str)
{
    cout << "String: " << str << endl;
    cout << "Permutations: " << endl;
    permute(str,0,str.length()-1); //call to permute(str,low,high)
}

#endif
