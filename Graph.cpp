#pragma once
#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"

#include "memoryDebug.cpp"

using namespace std;

// example of instanciation
// Graph graph1(28);
class Graph{
public:
    // default constructor
    // graph with a single node with no edges
    // initialize empty adjacency matrix
    Graph(){
        nEdges_ = 0;
        nNodes_ = 1;
        adjacencyMatrix_ = new int*[nNodes_];
        for (int i = 0; i < nNodes_; ++i) {
            adjacencyMatrix_[i] = new int[nNodes_];
            // Initialize the matrix with -1
            for (int j = 0; j < nNodes_; ++j) {
                adjacencyMatrix_[i][j] = -1;
            }
        }
    }


    /**
     * constructor with parameters
    @param nNodesP number of nodes in the graph
    */
    Graph(int nNodesP){
        // Creates matrix
        nEdges_ = 0;
        nNodes_ = nNodesP;
        adjacencyMatrix_ = new int*[nNodesP];
        for (int i = 0; i < nNodesP; i++) {
            adjacencyMatrix_[i] = new int[nNodesP];
            // Initialize the adjacency matrix with -1
            for (int j = 0; j < nNodesP; j++) {
                adjacencyMatrix_[i][j] = -1;
            }
        }
    }
    
    /**
     * adds an edge to the graph and updates adjacency matrix
     @param edge Edge instance that will be added to graph 
     */
    void addEdge(Edge& edge) {
        // Add an edge between vertex1 and vertex2
        // Assumes an undirected graph
        int node1id = edge.getAdjNode1()->getId();
        int node2id = edge.getAdjNode2()->getId();
        
        adjacencyMatrix_[node1id][node2id] = edge.getWeight();
        adjacencyMatrix_[node2id][node1id] = edge.getWeight();
        nEdges_++;
    }

    /**
     * displays entire adjacency matrix 
     */
    void displayMatrix() {
        cout << "adjacency matrix: " << endl;

        for (int i = 0; i < nNodes_; ++i) {
            cout << "Node " << i << ": ";
            for (int j = 0; j < nNodes_; ++j) {
                cout << adjacencyMatrix_[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    
    //displays adjacency list
    void displayList() {
        // Display the adjacency list
        cout << "adjacency list" << endl;
        for (int i = 0; i < nNodes_; ++i) {
            cout << "Node " << i << ": ";
            for (int j = 0; j < nNodes_; ++j) {
                if (adjacencyMatrix_[i][j] > 0) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    /**
     * the rows and columns corresponding to the selected node
     * in the adjacency matrix will be reset to -1 eliminating
     * all connections to it
     @param node node that will be removed from graph
     */
    void removeNode(Node& node){
        int id = node.getId();
        for (int i = 0; i < nNodes_; i++){
            adjacencyMatrix_[id][i] = -1;
            adjacencyMatrix_[i][id] = -1;
        }
    }

    ~Graph(){}

    // getters

    const int getNumNodes() const{
        return nNodes_;
    }

    int** getAdjacencyMatrix() const{
        return adjacencyMatrix_;
    }

    // setters

    void resetMatrix(int** originalMatrix){
        adjacencyMatrix_ = originalMatrix;
    }

private:
    int nNodes_;
    int nEdges_;
    int** adjacencyMatrix_;
};


