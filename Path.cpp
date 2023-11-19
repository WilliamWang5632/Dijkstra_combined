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

        directionsInt = new int[nNodes - 1];
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

        directionsInt = new int[nNodes - 1];
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

    // initialize char* directions and int* directionsInt (length nNodes - 1)

    // char* directions : list of cardinal directions of each travelled edge in path (uppercase)
    // int* directionsInt : list of integers associated with each direction

    // 'X' : direction not found : -1
    // 'N' : North: 0
    // 'E' : East : 1
    // 'S' : South: 2
    // 'W' : West : 3
    
    void findDirections(){
        for (int i = 1; i < nNodes; i++){

            int previous = nodeArray[i - 1].id;
            int current = nodeArray[i].id;

            cout << previous << " " << current << " ";

            if (previous - current == -1){
                directions[i - 1] = 'E';   // 'E' : East : 1
                directionsInt[i - 1] = 1;

                //cout << "East -> ";
            }
            else if (previous - current == 1){
                directions[i - 1] = 'W';   // 'W' : West : 3
                directionsInt[i - 1] = 3;
                //cout << "West -> ";
            }
            else if (previous - current == -7){
                directions[i - 1] = 'S';   // 'S' : South: 2
                directionsInt[i - 1] = 2;
                //cout << "South -> ";
            }
            else if (previous - current == 7){
                directions[i - 1] = 'N';   // 'N' : North: 0
                directionsInt[i - 1] = 0;
                //cout << "North -> ";
            }
            else{
                directions[i - 1] = 'X';   // 'X' : direction not found : -1
                directionsInt[i - 1] = -1;
            }
            cout << directions[i - 1] << endl;
        }
        //cout << "end" << endl;
    }


    // convert array of cardinal directions into instructions given to vehicle

    // approach: subtract previous direction integer from current direction integer 
    // and separate into different cases

    // 'f' :  move forwards 1 edge
    // 'b' :  turn 180 degrees and move forwards 1 edge
    // 'r' :  turn right (90 deg clockwise) and move forwards 1 edge
    // 'l' :  turn left (90 deg counter clockwise) and move forwards 1 edge
    // 'x' :  instruction not found
    // 's' :  arrived at destination, stop

    void findVehicleInstructions(){
        vehicleInstructions[0] = directions[0];

        cout << "face " << vehicleInstructions[0] << " and move forwards" << endl;

        for (int i = 1; i < nNodes; i++){
            int difference = directionsInt[i] - directionsInt[i - 1];
            if (difference == 0){
                vehicleInstructions[i] = 'f'; // move forwards 1 edge

                cout << "move forwards" << endl;
            }
            else if (difference == 2 || difference == -2){
                vehicleInstructions[i] = 'b'; // turn 180 degrees and move forwards 1 edge

                cout << "turn 180 degrees and move forwards" << endl;
            }
            else if (difference == -3 || difference == 1){
                vehicleInstructions[i] = 'r'; // turn right (90 deg clockwise) and move forwards 1 edge

                cout << "turn right and move forwards" << endl;
            }
            else if (difference == 3 || difference == -1){
                vehicleInstructions[i] = 'l'; // turn left (90 deg counter clockwise) and move forwards 1 edge

                cout << "turn left and move forwards" << endl;
            }
            else{
                vehicleInstructions[i] = 'x';

                cout << "instruction not found" << endl;
            }
        }
        vehicleInstructions[nNodes - 1] = 's';

        cout << "arrived at destination, stop" << endl;
    }
    
    ~Path() {
        // delete[] nodeArray;
        // delete[] directions;
        // delete[] directionsInt;
        // delete[] vehicleInstructions; 
    }


    int nNodes;
    int totalCost;

    int* directionsInt;
    char* directions;
    char* vehicleInstructions;

    Node start;
    Node current;
    Node* nodeArray;
    Graph playground;
};