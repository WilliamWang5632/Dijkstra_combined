#pragma once
#include <iostream>

using namespace std;

// number of nodes per line
const int NODES_PER_ROW = 7; //7

// example of instanciation:
// Node n21 = Node(2, 1);
// or 
// Node n21 = Node(7);

class Node{
public:
    // default constructor
    Node(){
        id = 0;  
        x_position = 1;
        y_position = 1;
        is_available = true;
    }

    /** Node constructor with 1 parameter
    @param identifier identifier of Node instance
    */
    Node(int identifier){
        x_position = identifier - NODES_PER_ROW * (identifier / NODES_PER_ROW ) + 1;
        y_position = (identifier / NODES_PER_ROW ) + 1;
        is_available = true;
        id = identifier;
    }

    /** Node constructor with 2 parameters
    @param x x coordinate of Node instance
    @param y y coordinate of Node instance
    */
    Node(int x, int y){
        x_position = x;
        y_position = y;
        is_available = true;
        id = NODES_PER_ROW  * (y - 1) + x - 1;
    }

    // prints node coordinates 
    void printCoordinates(){
        cout << "(" << x_position << ", " << y_position << ")";
    }

    /*
    prints Node id, x coordinate and y coordinate
    */
    void printInfo(){
        cout << "id: " << id << endl;
        printCoordinates();
        cout << endl;
    }
    
    int id;  
    int x_position;
    int y_position;
    bool is_available;

};