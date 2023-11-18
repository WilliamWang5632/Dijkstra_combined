#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"
#include "Dijkstra.cpp"

//#include "memoryDebug.cpp"

using namespace std;

/*

    This is a test file

    9 nodes graph in a 3 x 3 arrangement
    with 9 edges forming an "R" shape

    ______  ______ 
   |              |
   |              |
    ______  ______
   |      |
   |      |
   |       _______


*/


int main(){

    // important before testing
    // change NODES_PER_ROW in Node.cpp to 3

    Node n11 = Node(1,1);
    Node n21 = Node(2,1);
    Node n31 = Node(3,1);
    Node n12 = Node(1,2);
    Node n22 = Node(2,2);
    Node n32 = Node(3,2);
    Node n13 = Node(1,3);
    Node n23 = Node(2,3);
    Node n33 = Node(3,3);

    Edge e11_21 = Edge(1, n11, n21);
    Edge e21_31 = Edge(2, n21, n31);
    Edge e12_22 = Edge(3, n12, n22);
    Edge e22_32 = Edge(4, n22, n32);
    Edge e23_33 = Edge(5, n23, n33);
    Edge e11_12 = Edge(6, n11, n12);
    Edge e12_13 = Edge(7, n12, n13);
    Edge e22_23 = Edge(8, n22, n23);
    Edge e31_32 = Edge(9, n31, n32);

    Graph r = Graph(9);

    r.addEdge(e11_21);
    r.addEdge(e21_31);
    r.addEdge(e12_22);
    r.addEdge(e22_32);
    r.addEdge(e23_33);
    r.addEdge(e11_12);
    r.addEdge(e12_13);
    r.addEdge(e22_23);
    r.addEdge(e31_32);

    //r.displayMatrix();
    r.displayList();

    Path minimumCostPath = computeDijkstra(r, n11, n33);
    minimumCostPath.print(false);


}