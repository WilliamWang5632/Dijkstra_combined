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

const int START_ID = 27; // starting node
const int END_ID = 0;  // ending node

const int BLOCKED_ID = 10; // blocked node if there is any

int main()
{
    string separationLine = "\n_________________________________________________________\n";
    // important before testing
    // change NODES_PER_ROW in Node.cpp to 7

    cout << separationLine ;

    // playground of final test
    Graph playground = createPlayground();

    //playground.displayMatrix();
    cout << endl;

    cout << endl;
    cout << "Before removing node: " << endl;
    //playground.displayList();

    // instanciate removed node
    //Node blocked = Node(BLOCKED_ID);

    Node n9 = Node(9);
    Node n12 = Node(12);
    Node n16 = Node(16);

    // removing some nodes from the playground
    //playground.removeNode(blocked);

    //playground.removeNode(n9);
    //playground.removeNode(n12);
    //playground.removeNode(n16);

    cout << endl;

    //cout << "After removing node: " << endl;
    playground.displayList();
    cout << endl;

    int nNodes = playground.getNumNodes();

    cout << separationLine << endl;
    // DIJKSTRA'S ALGORITHM

    // instanciate start and end node
    Node start = Node(START_ID);
    Node end = Node(END_ID);

    Path minimumCostPath = computeDijkstra(playground, start, end);

    // print(true) -> identifier
    // print(false) -> coordinates

    minimumCostPath.printPath(true);
    cout << separationLine << endl;
    minimumCostPath.printPath(false);



    minimumCostPath.findDirections();            // must call findDirections before findVehicleInstructions
    //minimumCostPath.findVehicleInstructions();   // cannot be called in computeDijkstra

}

