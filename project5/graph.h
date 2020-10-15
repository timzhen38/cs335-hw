#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include <limits.h>
using namespace std;

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outsode those statements
class Graph
{
    private:
        //Vertex struct
        struct Vertex
        {
            //Data Members
            vector<Vertex*> adjVertices;
            vector<float> edgeWeights;
            int vertID;
            bool known;
            float distance;
            Vertex* previousVertex;

            //Constructor
            Vertex()
            {
                vertID = 0;
                known = false;
                distance = 0.0;
                previousVertex = nullptr;
            }

            //parameterized constructor
            Vertex(int ID)
            {
                vertID = ID;
                known = false;
                distance = 0.0;
                previousVertex = nullptr;
            }

            //overload the operator < for comparing vertices
            bool operator<(const Vertex &rhs) const
            {
                return distance < rhs.distance;
            }

            //destructor
            ~Vertex()
            {
                previousVertex = nullptr;
            }
        };
       /* 
        //checks if the vertex is valid to place
        bool checkVertex(int ID)
        {
            if (ID > 1 || ID > numOfVertices)
            {
                return false;
            }
            return true;
        }*/
        vector<Vertex> verticeGraph; //the graph
        int numOfVertices; //number of vertices

    public:
        //constructor
        Graph(int size)
        {
            verticeGraph.resize(size);
            numOfVertices = size;

            for (int i = 0; i < size; i++)
            {
                verticeGraph[i] = Vertex(i+1);
            }
        }

        //place an edge between two vertices
        void placeEdge(int start, int end, float edgeWeight)
        {
            verticeGraph[start-1].adjVertices.push_back(&(verticeGraph[end-1]));
            verticeGraph[start-1].edgeWeights.push_back(edgeWeight);
        }

        //check if there is an existing edge between two vertices
        float checkConnection (int start, int end)
        {
            float weight = -1.0; //set to -1 to show theres no existing edge by default
            auto it1 = verticeGraph[start-1].adjVertices.begin();
            auto it2 = verticeGraph[start-1].edgeWeights.begin();
            auto itEnd = verticeGraph[start-1].adjVertices.end();
            while (it1 != itEnd)
            {
                if ((*it1)->vertID == end)
                {
                    weight = *it2;
                    return weight;
                }
                it1++;
                it2++;
            }
            return weight;
        }

        //implementation of the Dijkstra Algorithm which is an algorithm
        //for finding shortest path between nodes in a graph 
        //this function takes in an input starting vertex and sets
        //cost and number of paths for each adjacent vertex
        void dijkstraAlg(const int startingID)
        {
            BinaryHeap<Vertex> heap;

            for(int i = 0; i < numOfVertices; i++)
            {
                verticeGraph[i].distance = 10000; //set to a large number
                verticeGraph[i].known = false; //unknown
            }

            verticeGraph[startingID-1].distance = 0.0; //set to 0 distance
            heap.insert(verticeGraph[startingID-1]); //insert into the heap

            while (true)
            {
                bool success = false; //looking for unknown vertices
                int selectedID = 0; //selected vertex's ID
                while (!heap.isEmpty() && !success)
                {
                    selectedID = (heap.findMin()).vertID;
                    heap.deleteMin();

                    if (!verticeGraph[selectedID-1].known)
                    {
                        success = true;
                    }
                }
                if (!success)
                {
                    break; //no unknown vertices remain in the heap
                }
                

                auto it1 = verticeGraph[selectedID-1].adjVertices.begin();
                auto it2 = verticeGraph[selectedID-1].edgeWeights.begin();
                auto itEnd = verticeGraph[selectedID-1].adjVertices.end();
                verticeGraph[selectedID-1].known = true;
                while (it1 != itEnd) //iterate through vertices adjacent to the starting vertex
                {
                    if (!(*it1)->known)
                    {
                        float cost = *it2;
                        float updatedDistance = verticeGraph[selectedID-1].distance + cost;
                        if (updatedDistance < (*it1)->distance)
                        {
                            (*it1)->distance = updatedDistance; //update distance
                            (*it1)->previousVertex = &(verticeGraph[selectedID-1]); //update path
                            heap.insert(*(*it1)); //reinsert vertex into the queue
                        }
                    }
                    it1++;
                    it2++;
                }
            }

            //outputting results
            for (int i = 0; i < numOfVertices; i++)
            {
                cout << verticeGraph[i].vertID << ": ";
                if (verticeGraph[i].distance == 10000)
                {
                    cout << "not_possible" << endl;
                }
                else
                {
                    printPath(verticeGraph[i]);
                    cout << " cost: " << fixed << setprecision(1) << verticeGraph[i].distance << endl;
                }
            }
        }

        //prints out the possible paths to a vertex
        void printPath(Vertex &v)
        {
            if (v.previousVertex != nullptr)
            {
                printPath(*(v.previousVertex));
                cout << " ";
            }
            cout << v.vertID;
        }

};




#endif
