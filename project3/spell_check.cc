// Tim Zhen

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hashing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //for transform

using namespace std;

// converts the word to lowercase form and removes punctuation from front and end
void removePunctuation(string &file_word)
{
  transform(file_word.begin(),file_word.end(),file_word.begin(),::tolower); //converts entire string to lowercase
  if (ispunct(file_word[file_word.length()-1]))
  {
    file_word.erase(file_word.length()-1); //removes the punctuation at the end first
  }
  if (ispunct(file_word[0]))
  {
    file_word.erase(0); //then removes the punctuation at the beginning
  }

}

/*
  tests the possible cases for corrections of each word
  Case A: adding one character in any possible position
  Case B: removing one character from the word
  Case C: swapping adjacent characters in the word
*/
template <typename HashTableType> 
void possibleCorrections(HashTableType &hash_table,const string word)
{
  if (!hash_table.Contains(word))
  {
    //Case A - adding
    cout << word << " is INCORRECT" << endl; 
    for (int t = 0; t < word.length(); t++)
    {
      for (char c = 'a'; c <= 'z'; c++)
      {
        string caseA = word.substr(0,t) + c + word.substr(t);
        if (hash_table.Contains(caseA))
        {
          cout << "** " << word << " -> " << caseA << " ** Case A" << endl;
        }
      }
    }
    for (char c2 = 'a'; c2 <= 'z'; c2++)
    {
      string caseALast = word.substr(0,word.length()) + c2; //adding a character to the end
      if (hash_table.Contains(caseALast))
      {
        cout << "** " << word << " -> " << caseALast << " ** Case A" << endl;
      }
    }

    //Case B - removing
    for (int j = 0; j < word.length()-1;j++)
    {
      string caseB = word.substr(0,j) + word.substr(j+1);
      if (hash_table.Contains(caseB))
      {
        cout << "** " << word << " -> " << caseB << " ** Case B" << endl;
      }
    }
    string caseBlast = word.substr(0,word.length()-1); //a case for removing last letter
    if (hash_table.Contains(caseBlast))
    {
      cout << "** " << word << " -> " << caseBlast << " ** Case B" << endl;
    }
    
    //Case C - swapping 
    for (int l = 0; l < word.length()-1;l++)
    {
      string caseC = word.substr(0,l) + word[l+1] + word[l] + word.substr(l+2);
      if (hash_table.Contains(caseC))
      {
        cout << "** " << word << " -> " << caseC << " ** Case C" << endl;
      }
    }
  }
  else
  {
    cout << word << " is CORRECT" << endl;
  }
  
}

//fill a hash table with all the words in the dictionary
template <typename HashTableType>
void fillDictionaryHashTable(HashTableType &hash_table, const string &dictionary_file)
{
  string word;
  ifstream inputFile(dictionary_file);
  while (inputFile >> word)
  {
    hash_table.Insert(word);
  }
  inputFile.close();
}

//formats the words from the document file and then prints out the cases
//for each word if they are incorrect
template <typename HashTableType>
void checkWords(HashTableType &hash_table, const string &document_file)
{
  string word;
  ifstream inputFile(document_file);
  while (inputFile >> word)
  {
    removePunctuation(word);
    possibleCorrections(hash_table,word);
  }
  inputFile.close();
}

int testSpellingWrapper(int argument_count, char** argument_list) {

  const string document_filename(argument_list[1]);
  const string dictionary_filename(argument_list[2]);
  
  //cout << "Input document filename is " << document_filename << endl;
  //cout << "Input dictionary filename is " << dictionary_filename << endl;

  // Call functions implementing the assignment requirements.
  HashTableQuadratic<string> quadratic_probing_table;//I will be using quadratic probing
  quadratic_probing_table.MakeEmpty();
  quadratic_probing_table.resetCollisions();
  fillDictionaryHashTable(quadratic_probing_table,dictionary_filename);
  checkWords(quadratic_probing_table,document_filename);
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE MAIN.
// WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE THERE.
// This main is only here for your own testing purposes.
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);

  return 0;
}
