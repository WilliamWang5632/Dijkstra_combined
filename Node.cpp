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
        id_ = 0;  
        x_position_ = 1;
        y_position_ = 1;
        is_available_ = true;
    }

    /** Node constructor with 1 parameter
    @param identifier identifier of Node instance
    */
    Node(int identifier){
        x_position_ = identifier - NODES_PER_ROW * (identifier / NODES_PER_ROW ) + 1;
        y_position_ = (identifier / NODES_PER_ROW ) + 1;
        is_available_ = true;
        id_ = identifier;
    }

    /** Node constructor with 2 parameters
    @param x x coordinate of Node instance
    @param y y coordinate of Node instance
    */
    Node(int x, int y){
        x_position_ = x;
        y_position_ = y;
        is_available_ = true;
        id_ = NODES_PER_ROW  * (y - 1) + x - 1;
    }

    // prints node coordinates 
    void printCoordinates(){
        cout << "(" << y_position_ << ", " << x_position_ << ")";
    }

    /*
    prints Node id, x coordinate and y coordinate
    */
    void printInfo(){
        cout << "id: " << id_ << endl;
        printCoordinates();
        cout << endl;
    }

    /**
     *  assignment/copy constructor
     @param other rvalue other node that we want to assign to lvalue node
     @return *this instance of Node object
    */ 
    Node& operator=(const Node& other) {
        if (this != &other) {  // Check for self-assignment
            id_ = other.id_;
            x_position_ = other.x_position_;
            y_position_ = other.y_position_;
            is_available_ = other.is_available_;
        }
        return *this;
    }

    //getters
    const int getId() const{
        return id_;
    }

    const int getX() const{
        return x_position_;
    }
    
    const int getY() const{
        return y_position_;
    }

private:
    int id_;  
    int x_position_;
    int y_position_;
    bool is_available_;

};