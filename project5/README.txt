Tim Zhen
i.
Q1 Done
Q2 Done
ii.
- the weight only output the default -1 for all vertexes and the bug turned out to be that I messed up a getline in the creategraph function so the graph wasnt being initalized and filled properly
- my djikstra algorithm kept on printing out the same 7 lines 3 times but the problem was that my iterators were starting at the wrong position I had used the parameter instead of the selectedID which was the vertex that we were currently on with the djikstras algorithm

iii.
- put all the files in the same folder
- compile with g++ CreateGraphAndTest.cc -o CreateGraphAndTest and then run it with ./CreateGraphAndTest <graph file> <adj queries file> 
- compile Q2 with g++ FindPaths.cc -o FindPaths and then run with ./FindPaths <graph file> <starting_vertex>

iv.
- input files for part 1 are graph1.txt and adjacencyqueries1.txt
- input file for Q2 is graph2.txt
