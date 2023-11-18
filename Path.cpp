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

        directions = new char[nNodes - 1];
        vehicleInstructions = new char[nNodes];
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

        directions = new char[nNodes - 1];
        vehicleInstructions = new char[nNodes];
    }

    // print the ids of all nodes in path in order as well as the totalCost
    void printPath(bool isId){
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

    void findDirections(){
        cout << nNodes <<endl;
        for (int i = 1; i < nNodes; i++){

            int previous = nodeArray[i - 1].id;
            int current = nodeArray[i].id;

            if (previous - current == -1){
                directions[i - 1] = 'E';

                cout << "East -> ";
            }
            else if (previous - current == 1){
                directions[i - 1] = 'W';
                cout << "West -> ";
            }
            else if (previous - current == -7){
                directions[i - 1] = 'S';
                cout << "South -> ";
            }
            else if (previous - current == 7){
                directions[i - 1] = 'N';
                cout << "North -> ";
            }
            else{
                //directions[i] = '-';
            }
        }
        cout << "end" << endl;
    }

    void findVehicleInstructions(){

    }
    
    ~Path() {
        //delete[] nodeArray;
        //delete[] directions;
        //delete[] instructions;
    }


    int nNodes;
    int totalCost;

    char* directions;
    char* vehicleInstructions;

    Node start;
    Node current;
    Node* nodeArray;
    Graph playground;
};