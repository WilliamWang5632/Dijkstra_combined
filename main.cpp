// questions: plusieurs poteaux possibles?
// peuvent-ils enlever des poteaux

#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"
#include "Dijkstra.cpp"

//#include "memoryDebug.cpp"

using namespace std;

const int START_ID = 0; // starting node
const int END_ID = 27;  // ending node

const int BLOCKED_ID = 10; // blocked node if there is any



int main()
{
    string separationLine = "\n_________________________________________________________\n";
    // important before testing
    // change NODES_PER_ROW in Node.cpp to 7

    cout << separationLine ;

    // playground of final test
    Graph playground = createPlayground();
    int** originalMatrix = playground.getAdjacencyMatrix();

    //playground.displayMatrix();
    //cout << endl;

    //cout << endl;
    //cout << "Before removing node: " << endl;
    //playground.displayList();

    // instanciate removed node
    //Node blocked = Node(BLOCKED_ID);

    // removing some nodes from the playground
    //playground.removeNode(blocked);

    // reset adjacency matrix (reinstate removed node)
    //playground.resetMatrix(originalMatrix);

    //cout << endl;

    //cout << "After removing node: " << endl;
    //playground.displayList();
    //cout << endl;

    int nNodes = playground.getNumNodes();

    //cout << separationLine << endl;
    // DIJKSTRA'S ALGORITHM

    // instanciate start and end node
    Node start = Node(START_ID);
    Node end = Node(END_ID);

    Path initialPath = computeDijkstra(playground, start, end);
    Path detourPath; // if there is any

    Node currentNode = Node(START_ID);


    int initialPathLen = 0;
    bool detour = false;
    for (int i = 0; i < initialPath.getNumNodes(); i++){

        currentNode = initialPath.getNthNode(i);
        Node nextNode = initialPath.getNthNode(i + 1);
        initialPathLen++;

        if (nextNode.getId() == BLOCKED_ID){

            initialPath = computeDijkstra(playground, start, nextNode); // cut short initial path

            playground.removeNode(nextNode);

            detour = true;
            break;
        }
    }
    cout << endl;

    Path finalPath;

    if (detour){
        detourPath = computeDijkstra(playground, currentNode, end);
        for (int i = 0; i < detourPath.getNumNodes(); i++){
            currentNode = detourPath.getNthNode(i);
        }
        finalPath = initialPath + detourPath;
    }
    else{
        finalPath = initialPath;
    }

    finalPath.findInstructions();

    finalPath.printPath(true);
    finalPath.printDirections();


}

