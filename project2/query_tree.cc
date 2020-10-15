// Tim Zhen
// Main file for Part2(a) of Homework 2.

#include "avl_tree_p2a.h"
#include "sequence_map.h"
// You will have to add #include "sequence_map.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

namespace {

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
  // Code for running Part2(a)
  // You can use public functions of TreeType. For example:
  //a_tree.insert(10);
  //a_tree.printTree();
  string db_line;

  //opens file
  ifstream input_file;
  input_file.open(db_filename);

  //need to skip the first 10 lines of rebase210.txt
  for (int j = 0; j < 10; j++)
  {
    getline(input_file,db_line);
  }

  while(getline(input_file,db_line))
  {
    stringstream input_stream(db_line);
    string an_enz_acro;
    getline(input_stream,an_enz_acro,'/'); //gets the enzyme acronym
    string a_reco_seq;
    while (getline(input_stream,a_reco_seq,'/')) //gets recognition sequence
    {
      SequenceMap new_sequence_map(a_reco_seq,an_enz_acro);
      a_tree.insert(new_sequence_map);
    } //end second while loop
  } //end first while loop
  input_file.close();
  

  //user queries
  string userSeq;
  while (cin >> userSeq)
  {
    SequenceMap query{userSeq,""};
    if (a_tree.contains(query))
      a_tree.printEnzyme(query);
    else
    {
      cout << "Not Found" << endl;
    }
    
  }

}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);
  return 0;
}
