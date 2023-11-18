#pragma once
#include <iostream>
#include "Node.cpp"

using namespace std;

// example of instanciation
// Edge e11_21 = Edge(black, n11, n21);

class Edge{
public:
    /**
     * constructor with parametres
    @param weightColor variable representing a colour that conveys the 
     * numerical value associated with the weight of the edge
    @param node1 first node connected to the edge
    @param node2 second node connected to the edge
     */
    Edge(int weightColor, Node& node1, Node& node2){
        weight = weightColor;
        adjacentNodes[0] = &node1;
        adjacentNodes[1] = &node2;
    }

    /*
    prints the weight as well as information of both connected nodes
    */
    void printInfo(){
        cout << "weight: " << weight << endl;
        cout << "Node 1: " << endl;
        cout << "\t id: " << adjacentNodes[0]->id << endl;
        cout << "\t coordinates: (" << adjacentNodes[0] -> x_position;
        cout << ", " << adjacentNodes[0] -> y_position << ")" << endl;
        cout << "Node 2: " << endl;
        cout << "\t id: " << adjacentNodes[1]->id << endl;
        cout << "\t coordinates: (" << adjacentNodes[1] -> x_position;
        cout << ", " << adjacentNodes[1] -> y_position << ")" << endl;
    }

    int weight;
    Node* adjacentNodes[2];
};