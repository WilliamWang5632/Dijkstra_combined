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
const int BLOCKED_1 = 11;

const int FIRST_INTERVAL = 6;
const int BLOCKED_2 = 2;

const int SECOND_INTERVAL = 21;
const int BLOCKED_3 = 16;
const int END = 27;  // ending node

int main()
{
    string separationLine = "\n_________________________________________________________\n";
    // important before testing
    // change NODES_PER_ROW in Node.cpp to 7

    cout << separationLine ;

    // playground of final test
    Graph playground = createPlayground();
    int** originalMatrix = playground.getAdjacencyMatrixCopy();

    //playground.displayMatrix();
    //cout << endl;

    //playground.displayList();

    //cout << separationLine << endl;
    // DIJKSTRA'S ALGORITHM

    cout << "first journey: " << endl << endl;

    Node start = Node(START);
    Node interval_1 = Node(FIRST_INTERVAL);
    Node blocked_1 = Node(BLOCKED_1);
    travel(playground, start, interval_1, blocked_1);

    cout << separationLine << endl;

    cout << "second journey: " << endl << endl;
    playground.resetMatrix(originalMatrix);

    Node interval_2 = Node(SECOND_INTERVAL);
    Node blocked_2 = Node(BLOCKED_2);
    travel(playground, interval_1, interval_2, blocked_2);

    cout << separationLine << endl;

    cout << "third journey: " << endl << endl;

    playground.resetMatrix(originalMatrix);
    Node end = Node(END);
    Node blocked_3 = Node(BLOCKED_3);
    travel(playground, interval_2, end, blocked_3);

}

