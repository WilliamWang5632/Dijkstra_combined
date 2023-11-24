#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"
#include "Dijkstra.cpp"
#include "travel.cpp"

#include "memoryDebug.cpp"

using namespace std;

const int START = 0; // starting node
const int BLOCKED_1 = 6;

const int FIRST_INTERVAL = 27;
// const int BLOCKED_2 = 2;

// const int SECOND_INTERVAL = 21;
// const int BLOCKED_3 = 17;
// const int END = 27;  // ending node

int main()
{
    string separationLine = "\n_________________________________________________________\n";
    // important before testing
    // change NODES_PER_ROW in Node.cpp to 7

    cout << separationLine ;

    // playground of final test
    Graph playground = createPlayground();
    int** originalMatrix = playground.getAdjacencyMatrixCopy();

    playground.displayMatrix();
    //cout << endl;

    playground.displayList();

    //cout << separationLine << endl;
    // DIJKSTRA'S ALGORITHM

    cout << "first journey: " << endl << endl;

    Node start = Node(START);
    Node interval_1 = Node(FIRST_INTERVAL);
    Node blocked_1 = Node(BLOCKED_1);


    // implementation where there is one combined path

    Path finalPath = travel(playground, start, interval_1, blocked_1);
    //Path finalPath = computeDijkstra(playground, start, interval_1);

    finalPath.printPath(true); // true -> id, false -> coordonees
    finalPath.printDirections();


    //playground.resetMatrix(originalMatrix);
    cout << separationLine << endl;

    // implementation where there are two seperate paths
    // one before pole detection, one after

    DoublePath doublePath = travelSeparated(playground, start, interval_1, blocked_1);

    doublePath.initial.printPath(true);
    doublePath.initial.printDirections();
    cout << "pole detected" << endl;
    cout << endl;
    doublePath.detour.printPath(true);
    doublePath.detour.printDirections();

    // cout << separationLine << endl;

    // cout << "second journey: " << endl << endl;
    // playground.resetMatrix(originalMatrix);

    // Node interval_2 = Node(SECOND_INTERVAL);
    // Node blocked_2 = Node(BLOCKED_2);
    // Path finalPath_2 = travel(playground, interval_1, interval_2, blocked_2);

    // finalPath_2.printPath(true);
    // finalPath_2.printDirections();

    // cout << separationLine << endl;

    // cout << "third journey: " << endl << endl;

    // playground.resetMatrix(originalMatrix);
    // Node end = Node(END);
    // Node blocked_3 = Node(BLOCKED_3);
    // Path finalPath_3 = travel(playground, interval_2, end, blocked_3);

    // finalPath_3.printPath(true);
    // finalPath_3.printDirections();

    // char* allInstructions = finalPath.getAllInstructions();
    PrintMemoryUsage();
}

