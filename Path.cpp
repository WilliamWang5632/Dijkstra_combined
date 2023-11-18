#pragma once
#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"

#include "memoryDebug.cpp"


using namespace std;

// example of instanciation
// Path path1 = Path(n11, graph1);
class Path{
public:
    // default constructor
    // single node graph with start at (1, 1)
    Path(){
        playground = Graph(1);
        start = Node(1,1);
        current = Node(1,1);
        totalCost = 0;
        nNodes = 1;

        nodeArray = new Node[1];
        nodeArray[0] = Node(1,1);
    }

    /**
     * constructor with parameters
     @param startingPoint starting node
     @param graph graph that the path will take place in
     */
    Path(Node& startingPoint, Graph& graph){
        start = startingPoint;
        current = startingPoint;
        playground = graph;
        totalCost = 0;
        nNodes = 1;

        nodeArray = new Node[1];
        nodeArray[0] = startingPoint;
    }

    // print the ids of all nodes in path in order as well as the totalCost
    void print(bool isId){
        if (isId){
            cout << "The shortest path between node " << start.id << " and "<< current.id << " is: " << endl;

            for (int i = 0; i < nNodes; i++){
                cout << nodeArray[i].id << " -> ";
            }
        }
        else{
            cout << "The shortest path between node ";
            start.printCoordinates();
            cout << " and ";
            current.printCoordinates();
            cout << " is: " << endl;

            for (int i = 0; i < nNodes; i++){
                nodeArray[i].printCoordinates();
                cout << " -> ";
            }
        }

        cout << "end" << endl;
        cout << endl;
        cout << "There are " << nNodes - 1 << " edges in this path" << endl;
        cout << endl;
        cout << "Total cost of this path: " << totalCost << endl;
        cout << endl;
    }
    
    ~Path(){} 

    int nNodes;
    int totalCost;
    Node start;
    Node current;
    Node* nodeArray;
    Graph playground;
};