// Tim Zhen
// CS 335

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hashing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//insert words into the hash table
template <typename HashTableType>
void insertHashTable(HashTableType &hash_table, const string &words_filename)
{
  string word;
  ifstream inputFile(words_filename);
  while (inputFile >> word)
  {
    hash_table.Insert(word);
  }
  inputFile.close();
}

// Figures out whether or not we can find the queried words
// and how many probes it takes to determine this
template <typename HashTableType>
void findWords (HashTableType &hash_table, const string &query_filename)
{
  string word;
  ifstream inputFile(query_filename);
  while (inputFile >> word)
  {
    hash_table.resetCollisions();
    if (hash_table.Contains(word))
    {
      cout << word << ": Found " << hash_table.getCollisions()+1 << " probes" << endl;
    }
    else
    {
      cout << word << ": Not_found " << hash_table.getCollisions()+1 << " probes" << endl;
    }
  }
  inputFile.close();
}

template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  /*cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl << endl;*/
  hash_table.MakeEmpty();  
  hash_table.resetCollisions(); //reset the collisions as well
  
  //..Insert your own code
  //cout << "Inserting words into the Hash table..." << endl << endl;
  insertHashTable(hash_table,words_filename);

  //statistics
  //cout << "Statistics for this Hash Table:" << endl;
  cout << "Number_of_items: " << hash_table.getNumItems() << endl;
  cout << "Size_of_hash_table: " << hash_table.getSizeOfHash() << endl;

  float loadFactor = (float)hash_table.getNumItems()/(float)hash_table.getSizeOfHash();
  cout << "Load_factor: " << loadFactor << endl;

  cout << "Collisions: " << hash_table.getCollisions() << endl;

  float avgCollisions = (float)hash_table.getCollisions()/(float)hash_table.getNumItems();
  cout << "Average_Number_of_Collisions: " << avgCollisions << endl << endl;

  // search for query words
  //cout << "Beginning searching for query words: " << endl;
  findWords(hash_table, query_filename);

}

int testFunctionWrapper(int argument_count, char **argument_list) {
  const string words_filename(argument_list[1]);
  const string query_filename(argument_list[2]);
  const string param_flag(argument_list[3]);

  //cout << "Input file is " << words_filename << ", and query file is " << query_filename << endl;

  if (param_flag == "linear") {
    HashTableLinear<string> linear_probing_table;
    //cout << "I will run the linear Hash code" << endl;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } else if (param_flag == "quadratic") {
    HashTableQuadratic<string> quadratic_probing_table;
    //cout << "I will run the quadratic Hash code" << endl;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    const string r_value(argument_list[4]); //rvalue that we take in
    HashTableDouble<string> double_probing_table;
    double_probing_table.setR(stoi(r_value));
    cout << "r-value: " << r_value << endl; // print r-value on first line
    //cout << "I will run the double Hash code" << endl;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } else {
    cout << "Unknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}

// Sample main for program create_and_test_hash.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE MAIN.
// WE WILL DIRECTLY CALL testFunctionWrapper. ALL FUNCTIONALITY SHOULD BE THERE.
// This main is only here for your own testing purposes.
int main(int argc, char **argv) {

  if (argc != 4 && argc != 5) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  testFunctionWrapper(argc, argv);
  return 0;
}
