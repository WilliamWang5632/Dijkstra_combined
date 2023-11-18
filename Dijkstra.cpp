#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"

using namespace std;

const int INF = 255; // very large number representing infinity

/**
 *  this function computes the shortest path between a starting and ending node in a graph
    @param adjacencyMatrix 2D matrix representing adjacency between all nodes of a graph
    @param nNodes number of nodes inside of graph
    @param start starting node
    @param end ending node
    @return class Path representing the shortest path between two nodes
*/

Path computeDijkstra(Graph playground, Node& start, Node& end) {

    int** adjacencyMatrix = playground.adjacencyMatrix;
    int nNodes = playground.nNodes;

    // Initialize distanceArr and visitedArr arrays
    int* distanceArr = new int[nNodes];
    bool* visitedArr = new bool[nNodes];
    int* previousNodes = new int[nNodes];

    for (int i = 0; i < nNodes; i++) {
        distanceArr[i] = INF;   // distance to all other nodes = infinity
        visitedArr[i] = false;  // no nodes have been visited yet
        previousNodes[i] = -1;
    }

    // distance from start to itself is 0 
    distanceArr[start.id] = 0;

    // Dijkstra's algorithm
    for (int i = 0; i < nNodes-1; i++) {
        // Find the minimum distance node that hasn't been utilised yet
        int cur = -1;
        for (int j = 0; j < nNodes; j++) {
            if (!visitedArr[j] && (cur == -1 || distanceArr[j] < distanceArr[cur])) {
                cur = j;
            }
        }

        // Mark the current node as visited
        visitedArr[cur] = true;

        // Update the distanceArr value of the adjacent nodes
        for (int adj = 0; adj < nNodes; ++adj) {
            if (!visitedArr[adj] && adjacencyMatrix[cur][adj] != -1 && distanceArr[cur] != INF &&
                distanceArr[cur] + adjacencyMatrix[cur][adj] < distanceArr[adj]) {
                distanceArr[adj] = distanceArr[cur] + adjacencyMatrix[cur][adj];
                previousNodes[adj] = cur;
            }
        }
    }

    int* path = new int[nNodes];
    int pathLength = 0;
    int current = end.id;

    while (current != -1){
        pathLength++;
        path[pathLength] = current;
        current = previousNodes[current];
    }

    int* IdArray = new int[pathLength];
    int j = 0;
    for (int i = pathLength; i >= 0; i--){
        if (path[i] >= 0){
            IdArray[j] = path[i];
            j++;
        }
    }

    Path minimumCostPath = Path(start, playground);
    minimumCostPath.nNodes = pathLength;
    minimumCostPath.totalCost = distanceArr[end.id];
    minimumCostPath.current = end;

    Node finalNodeArray[pathLength];
    for (int i = 0; i < pathLength; i++){
        int id = IdArray[i];
        Node newNode = Node(id);
        finalNodeArray[i] = newNode;
    }
    
    for (int i = 0; i < pathLength; i++){
        minimumCostPath.nodeArray[i] = finalNodeArray[i];
    }
    
    return minimumCostPath;
}

