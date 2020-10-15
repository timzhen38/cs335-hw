#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "graph.h"
#include <iostream>
#include <fstream>

using namespace std;

Graph createGraph(string &file_name)
{
    ifstream inputFile(file_name);
    int size;
    int startingVert;
    int endingVert;
    float edgeWeight;
    string line;
    stringstream copyLine;
    
    inputFile >> size; //read size
    Graph theGraph(size); //initalize graph


    while(getline(inputFile,line))
    {
      copyLine.clear(); //clear the copy line every loop
      copyLine.str(line); //copying line
      copyLine >> startingVert;

      while(copyLine >> endingVert)
      {
        copyLine >> edgeWeight;
        theGraph.placeEdge(startingVert,endingVert,edgeWeight); //place the edge into the graph
      }
    }

    inputFile.close();
    return theGraph;
}

int graphTestDriver(int argc, char **argv) {
    
    //Begin your code here. Feel free to add any helper functions or classes you need,
    //as long as we only have to call this function to run the specified assignment.
    string graph_filename = argv[1];
    string query_filename = argv[2];
    Graph inputGraph = createGraph(graph_filename);
    ifstream inputFile(query_filename);
    int startingVert;
    int endingVert;
    float edgeWeight = 0.0;
    string line;
    stringstream copyLine;

    //check if an edge exists between the starting vertex and ending vertex
    while (inputFile >> line)
    {
      copyLine.clear(); //clear the copy line at start of every loop
      copyLine.str(line);

      copyLine >> startingVert;

      inputFile >> line;
      copyLine.clear();
      copyLine.str(line);
      copyLine >> endingVert;
      edgeWeight = inputGraph.checkConnection(startingVert, endingVert);

      if (edgeWeight != -1.0)
      {
        cout << startingVert << " " << endingVert << ": " << "connected " << edgeWeight << endl;
      }
      else
      {
        cout << startingVert << " " << endingVert << ": " << "not_connected" << endl;
      }
    }
    inputFile.close();

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
		return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}
