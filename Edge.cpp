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
        weight_ = weightColor;
        adjacentNodes_[0] = &node1;
        adjacentNodes_[1] = &node2;
    }

    /*
    prints the weight_ as well as information of both connected nodes
    */
    void printInfo(){
        cout << "weight: " << weight_ << endl;
        cout << "Node 1: " << endl;
        cout << "\t id: " << adjacentNodes_[0]->getId() << endl;
        cout << "\t coordinates: (" << adjacentNodes_[0] -> getX();
        cout << ", " << adjacentNodes_[0] -> getY() << ")" << endl;
        cout << "Node 2: " << endl;
        cout << "\t id: " << adjacentNodes_[1]->getId() << endl;
        cout << "\t coordinates: (" << adjacentNodes_[1] -> getX();
        cout << ", " << adjacentNodes_[1] -> getY() << ")" << endl;
    }

    //getters
    const int getWeight() const{
        return weight_;
    }

    const Node* getAdjNode1() const{
        return adjacentNodes_[0];
    }

    const Node* getAdjNode2() const{
        return adjacentNodes_[1];
    }

private:
    int weight_;
    Node* adjacentNodes_[2];
};