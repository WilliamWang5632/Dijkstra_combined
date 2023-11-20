// questions: plusieurs poteaux possibles?
// peuvent-ils enlever des poteaux

#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"
#include "Dijkstra.cpp"

#include "memoryDebug.cpp"

using namespace std;

const int START_ID = 0; // starting node
const int END_ID = 27;  // ending node

const int BLOCKED_ID = 10; // blocked node if there is any


//temp

Path travel(Graph playground, Node& start, Node& end){
    Path minimumCostPath = computeDijkstra(playground, start, end);

    minimumCostPath.printPath(true);
    cout << endl;
    minimumCostPath.printPath(false);

    minimumCostPath.findDirections();            // create array of cardinal directions
    cout << endl;
    minimumCostPath.findVehicleInstructions();   // create array of vehicle instructions

    int currentId = minimumCostPath.getCurrentNode().getId();
    char currentDirection = minimumCostPath.getCurrentDirection();

    cout << "We are currently at node " << currentId << " facing the ";
    cout << currentDirection << " direction" << endl;

    return minimumCostPath;
}


int main()
{
    string separationLine = "\n_________________________________________________________\n";
    // important before testing
    // change NODES_PER_ROW in Node.cpp to 7

    cout << separationLine ;

    // playground of final test
    Graph playground = createPlayground();
    int** originalMatrix = playground.getAdjacencyMatrix();

    playground.displayMatrix();
    cout << endl;

    cout << endl;
    cout << "Before removing node: " << endl;
    playground.displayList();

    // instanciate removed node
    Node blocked = Node(BLOCKED_ID);

    // removing some nodes from the playground
    playground.removeNode(blocked);

    // reset adjacency matrix (reinstate removed node)
    playground.resetMatrix(originalMatrix);

    cout << endl;

    cout << "After removing node: " << endl;
    playground.displayList();
    cout << endl;

    int nNodes = playground.getNumNodes();

    //cout << separationLine << endl;
    // DIJKSTRA'S ALGORITHM

    // instanciate start and end node
    Node start = Node(START_ID);
    Node end = Node(END_ID);

    // print(true) -> identifier
    // print(false) -> coordinates
    Path minimumCostPath = travel(playground, start, end);

}

