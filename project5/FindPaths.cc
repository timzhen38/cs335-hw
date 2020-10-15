#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "graph.h"

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

int pathfindDriver(int argc, char **argv) {
    string graph_filename = argv[1];
    string startingVertex = argv[2];

    Graph inputGraph = createGraph(graph_filename);

    inputGraph.dijkstraAlg(stoi(startingVertex));

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }

    pathfindDriver(argc, argv);

    return 0;
}
