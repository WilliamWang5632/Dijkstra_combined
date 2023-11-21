#pragma once
#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"

#include "memoryDebug.cpp"


using namespace std;

// example of instanciation
// Path path1 = Path(n11, graph1);
// Path path2 = Path(n0, graph1)
class Path{
public:
    // default constructor
    // single node graph with start at (1, 1)
    Path(){
        playground_ = Graph(1);
        start_ = Node(1,1);
        totalCost_ = 0;
        nNodes_ = 1;

        nodeArray_ = new Node[nNodes_];
        nodeArray_[0] = Node(1,1);

        directionsInt_ = new int[nNodes_ - 1];
        directions_ = new char[nNodes_ - 1];
        vehicleInstructions_ = new char[nNodes_];             
    }

    /**
     * constructor with parameters
     @param startingPoint starting node
     @param graph graph that the path will take place in
     @param nNodes number of nodes in path
     */
    Path(Node& startingPoint, Graph& graph, int nNodes){
        start_ = startingPoint;
        playground_ = graph;
        totalCost_ = 0;
        nNodes_ = nNodes;

        nodeArray_ = new Node[nNodes_];
        nodeArray_[0] = startingPoint;

        directionsInt_ = new int[nNodes_ - 1];
        directions_ = new char[nNodes_ - 1];
        vehicleInstructions_ = new char[nNodes_];
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

        for (int i = 1; i < nNodes_; i++){

            int previous = nodeArray_[i - 1].getId();
            int current = nodeArray_[i].getId();
            
            if (previous - current == -1){
                directions_[i - 1] = 'E';   // 'E' : East : 1
                directionsInt_[i - 1] = 1;

                //cout << "East -> ";
            }

            else if (previous - current == 1){
                directions_[i - 1] = 'W';   // 'W' : West : 3
                directionsInt_[i - 1] = 3;

                //cout << "West -> ";
            }
            else if (previous - current == -NODES_PER_ROW){
                directions_[i - 1] = 'S';   // 'S' : South: 2
                directionsInt_[i - 1] = 2;

                //cout << "South -> ";
            }
            else if (previous - current == NODES_PER_ROW){
                directions_[i - 1] = 'N';   // 'N' : North: 0
                directionsInt_[i - 1] = 0;

                //cout << "North -> ";
            }
            else{
                directions_[i - 1] = 'X';   // 'X' : direction not found : -1
                directionsInt_[i - 1] = -1;
            }
        }
        //cout << "end" << endl;
    }


    // convert array of cardinal directions into instructions given to vehicle (lowercase)

    // approach: subtract previous direction integer from current direction integer 
    // and separate into different cases

    // 'N', 'E', 'S', 'W' : first character of vehicleInstructions:  
    // initial direction and move forwards 1 edge

    // 'f' :  move forwards 1 edge
    // 'b' :  turn 180 degrees and move forwards 1 edge
    // 'r' :  turn right (90 deg clockwise) and move forwards 1 edge
    // 'l' :  turn left (90 deg counter clockwise) and move forwards 1 edge
    // 'x' :  instruction not found
    // 's' :  arrived at destination, stop

    void findVehicleInstructions(){
        //vehicleInstructions_[0] = directions_[0];

        vehicleInstructions_[0] = 'f'; // assumes vehicle is in the right direction

        //cout << "face " << vehicleInstructions_[0] << " and move forwards" << endl;

        for (int i = 1; i < nNodes_; i++){
            int difference = directionsInt_[i] - directionsInt_[i - 1];
            if (difference == 0){
                vehicleInstructions_[i] = 'f';

                //cout << "move forwards 1 edge" << endl;
            }
            else if (difference == 2 || difference == -2){
                vehicleInstructions_[i] = 'b'; 

                //cout << "turn 180 degrees and move forwards 1 edge" << endl;
            }
            else if (difference == -3 || difference == 1){
                vehicleInstructions_[i] = 'r';

                //cout << "turn right and move forwards 1 edge" << endl;
            }
            else if (difference == 3 || difference == -1){
                vehicleInstructions_[i] = 'l';

                //cout << "turn left and move forwards 1 edge" << endl;
            }
            else{
                vehicleInstructions_[i] = 'x';

                //cout << "instruction not found 1 edge" << endl;
            }
        }
        vehicleInstructions_[nNodes_- 1] = 's';

        //cout << "arrived at destination, stop" << endl;

        for (int j = 0; j < nNodes_; j++){
            //cout << vehicleInstructions_[j] << " -> ";
        }
        //cout << "end" << endl;
    }

    void findInstructions(){

        findDirections();            // create array of cardinal directions
        findVehicleInstructions();   // create array of vehicle instructions
    }
    
    ~Path() {
        // delete[] nodeArray_;
        // delete[] directions_;
        // delete[] directionsInt_;
        // delete[] vehicleInstructions_; 
    }

    // operator overloads

    // how is this operator not needed?
    Path& operator=(const Path& other) {
        if (this != &other) {  // Check for self-assignment
            nNodes_ = other.nNodes_;
            totalCost_ = other.totalCost_;

            directionsInt_ = other.directionsInt_;
            directions_ = other.directions_;
            vehicleInstructions_ = other.vehicleInstructions_;

            start_ = other.start_;
            nodeArray_ = other.nodeArray_;
        }
        return *this;
    }

    template <typename T>
    T* concatenateArrays(const T* array1, int size1, const T* array2, int size2) {
        // Check for valid input
        if (array1 == nullptr || array2 == nullptr || size1 <= 0 || size2 <= 0) {
            return nullptr;
        }
        T* result = new T[size1 + size2];

        for (int i = 0; i < size1; ++i) {
            result[i] = array1[i];
        }

        for (int i = 0; i < size2; ++i) {
            result[size1 + i] = array2[i];
        }

        return result;
    }

    // concatenate two paths together
    Path operator+(const Path& other) {
        int totalNumNodes = nNodes_ + other.nNodes_;
        Path combinedPath = Path(start_, playground_, totalNumNodes);

        combinedPath.nNodes_ = totalNumNodes;
        combinedPath.totalCost_ = totalCost_ + other.totalCost_;

        combinedPath.directionsInt_ = new int[nNodes_ + other.nNodes_ - 1];

        combinedPath.directions_ = new char[nNodes_ + other.nNodes_ - 2];

        combinedPath.vehicleInstructions_ = new char[nNodes_ + other.nNodes_];

        combinedPath.start_ = start_;

        combinedPath.nodeArray_ = 
        concatenateArrays<Node>(nodeArray_, nNodes_, other.nodeArray_, other.nNodes_);

        combinedPath.playground_ = playground_;

        return combinedPath;
    }

    // print information of all nodes in path in order as well as the totalCost
    // isId == false : print coordinates
    // isId == true  : print ids
    void printPath(bool isId){
        if (isId){
            cout << "The shortest path between node " << start_.getId();
            cout << " and "<< nodeArray_[nNodes_ - 1].getId() << " is: " << endl;

            for (int i = 0; i < nNodes_; i++){
                cout << nodeArray_[i].getId() << " -> ";
            }
        }
        else{
            cout << "The shortest path between node ";
            start_.printCoordinates();
            cout << " and ";
            nodeArray_[nNodes_ - 1].printCoordinates();
            cout << " is: " << endl;

            for (int i = 0; i < nNodes_; i++){
                nodeArray_[i].printCoordinates();
                cout << " -> ";
            }
        }

        cout << "end" << endl;
        cout << endl;
        cout << "There are " << nNodes_ - 1 << " edges in this path" << endl;
        cout << endl;
        cout << "Total cost of this path: " << totalCost_ << endl;
        cout << endl;
    }

    void printDirections(){
        for (int i = 0; i < nNodes_ - 1; i++){
            cout << directions_[i] << " -> ";
        }
        cout << "end" << endl;
        cout << endl;
        for (int i = 0; i < nNodes_; i++){
            cout << vehicleInstructions_[i] << " -> ";
        }
        cout << "end" << endl;
    }


    // getters

    const int getNumNodes() const{
        return nNodes_;
    }

    const Node getNthNode(int index) const{
        return nodeArray_[index];
    }

    const char getCurrentDirection(int index) const{
        return directions_[index];
    }

    // setters

    void setTotalCost(int totalCost){
        totalCost_ = totalCost;
    }

    void setNodeArrayElem(int index, Node& node){
        nodeArray_[index] = node;
    }

    void setDirectionsArrayElem(int index, char& direction){
        directions_[index] = direction;
    }

    void setInstructionsArrayElem(int index, char& instruction){
        vehicleInstructions_[index] = instruction;
    }

private:
    int nNodes_;
    int totalCost_;

    int* directionsInt_;
    char* directions_;
    char* vehicleInstructions_;

    Node start_;
    Node* nodeArray_;
    Graph playground_;
};