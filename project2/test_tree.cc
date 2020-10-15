// Tim Zhen
// Main file for Part2(b) of Homework 2.

#include "avl_tree_p2b.h"
#include "sequence_map.h"
// You will have to add #include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

namespace {

// searches the tree for each string in the sequences.txt file
// gives us the amount of successful queries and recursive calls
template <typename TreeType>
void find(const string& db_filename, TreeType& a_tree)
{
  ifstream input_file;
  input_file.open(db_filename);
  string currLine;
  int recursionCalls = 0;
  int successQueries = 0;
  while (input_file >> currLine)
  {
    SequenceMap seq{currLine,""};
    if (a_tree.contains(seq))
      successQueries++;
    recursionCalls += a_tree.recFind(seq);
  }
  input_file.close();
  cout << "4a: " << successQueries << endl;
  cout << "4b: " << float(recursionCalls)/float(successQueries) << endl;
}

//removes every other sequence and counts the amount of 
//recursive calls, successful removals and total number of remove calls
template <typename TreeType>
void removeSeq(const string& db_filename, TreeType& a_tree)
{
  ifstream input_file;
  input_file.open(db_filename);
  string currLine;
  int recursiveCalls = 0; //num of recursive calls
  int successRemove = 0; //successful removals
  int counter = 0; //number of times removed is called
  while (input_file >> currLine)
  {
    SequenceMap seq{currLine,""};
    a_tree.remove(seq);
    counter++;
    input_file >> currLine; //every other line
  }
  input_file.close();
  recursiveCalls = a_tree.getRemoveCalls();
  successRemove = a_tree.getRemoves();
  cout << "5a: " << successRemove << endl;
  cout << "5b: " << (float)recursiveCalls/(float)counter << endl;
}

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Code for running Part2(b) 

  //opening file 
  ifstream input_file(db_filename);
  string db_line;

  for (int i = 0; i < 10; i++) //skipping first 10 lines
  {
    getline(input_file,db_line);
  }

  //1. constructs a search tree
  while(getline(input_file,db_line))
  {
    if (db_line.length() < 1)
      continue;
    stringstream input_stream(db_line);
    string an_enz_acro;
    string a_reco_seq;
    getline(input_stream,an_enz_acro,'/'); //gets the enzyme acronym
    while (getline(input_stream,a_reco_seq,'/')) //gets recognition sequence
    {
      if (a_reco_seq.length() > 0)
      {
        SequenceMap new_sequence_map(a_reco_seq,an_enz_acro);
        a_tree.insert(new_sequence_map);
      }
    } //end second while loop
  } //end first while loop
  input_file.close();

  //2. printing number of nodes in the tree
  int nodeNum = a_tree.countNodes();
  cout << "2: " << nodeNum << endl;

  //3a. computes the average depth of the tree / internal path length divided by n
  float avgDepth = (float)a_tree.calcTotalDepth()/(float)nodeNum;
  cout << "3a: " << avgDepth << endl;

  //3b. prints the ratio of average depth to log2n
  float logN = log(nodeNum)/log(2);
  float ratioDepth = avgDepth/logN;
  cout << "3b: " << ratioDepth << endl;
  
  //4. Searches the tree for each string in the sequences.txt file and counts the
  //total number of recursive calls for all executions of find().
  find(seq_filename, a_tree);

  //5. Removes every other sequence in sequences.txt from the tree and counts the total
  //number of recursion calls for all executions of remove()
  removeSeq(seq_filename, a_tree);

  //6. redoing printing number of nodes and average depth of the tree
  nodeNum = a_tree.countNodes();
  avgDepth = a_tree.calcTotalDepth()/(float)nodeNum;
  cout << "6a: " << nodeNum << endl;
  cout << "6b: " << avgDepth << endl;
  logN = log(nodeNum)/log(2);
  ratioDepth = avgDepth/logN;
  cout << "6c: " << ratioDepth << endl; 
}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
