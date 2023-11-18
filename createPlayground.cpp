#pragma once
#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"

#include "memoryDebug.cpp"

using namespace std;

const int NUM_NODES_IN_GRAPH = 28;

const int BLACK = 1;
const int YELLOW = 2;
const int RED = 3;


Graph createPlayground(){
    // instanciation of nodes
    // row 1
    Node n11 = Node(1,1);
    Node n21 = Node(2,1);
    Node n31 = Node(3,1);
    Node n41 = Node(4,1);
    Node n51 = Node(5,1);
    Node n61 = Node(6,1);
    Node n71 = Node(7,1);
    
    // row 2
    Node n12 = Node(1,2);
    Node n22 = Node(2,2);
    Node n32 = Node(3,2);
    Node n42 = Node(4,2);
    Node n52 = Node(5,2);
    Node n62 = Node(6,2);
    Node n72 = Node(7,2);
    
    // row 3
    Node n13 = Node(1,3);
    Node n23 = Node(2,3);
    Node n33 = Node(3,3);
    Node n43 = Node(4,3);
    Node n53 = Node(5,3);
    Node n63 = Node(6,3);
    Node n73 = Node(7,3);
    
    // row 4
    Node n14 = Node(1,4);
    Node n24 = Node(2,4);
    Node n34 = Node(3,4);
    Node n44 = Node(4,4);
    Node n54 = Node(5,4);
    Node n64 = Node(6,4);
    Node n74 = Node(7,4);
    
    // instanciation of edges
    
    // instanciation of horizontal edges
    
    // row 1 horizontal edges
    Edge e11_21 = Edge(BLACK, n11, n21);
    Edge e21_31 = Edge(BLACK, n21, n31);
    Edge e31_41 = Edge(BLACK, n31, n41);
    Edge e51_61 = Edge(BLACK, n51, n61);
    Edge e61_71 = Edge(BLACK, n61, n71);
    
    // row 2 horizontal edges
    Edge e12_22 = Edge(RED, n12, n22);
    Edge e22_32 = Edge(BLACK, n22, n32);
    Edge e42_52 = Edge(YELLOW, n42, n52);
    Edge e52_62 = Edge(BLACK, n52, n62);
    Edge e62_72 = Edge(BLACK, n62, n72);
    
    // row 3 horizontal edges    
    Edge e13_23 = Edge(YELLOW, n13, n23);
    Edge e23_33 = Edge(BLACK, n23, n33);
    Edge e33_43 = Edge(BLACK, n33, n43);
    Edge e43_53 = Edge(RED, n43, n53);
    
    // row 4 horizontal edges    
    Edge e14_24 = Edge(BLACK, n14, n24);
    Edge e24_34 = Edge(BLACK, n24, n34);
    Edge e44_54 = Edge(YELLOW, n44, n54);
    Edge e54_64 = Edge(RED, n54, n64);
    Edge e64_74 = Edge(BLACK, n64, n74);
    
    // instanciation of vertical edges
    
    // column 1 vertical edges
    Edge e11_12 = Edge(BLACK, n11, n12);
    Edge e13_14 = Edge(RED, n13, n14);
    
    // column 2 vertical edges
    Edge e22_23 = Edge(BLACK, n22, n23);
    
    // column 3 vertical edges    
    Edge e31_32 = Edge(BLACK, n31, n32);
    Edge e32_33 = Edge(RED, n32, n33);
    Edge e33_34 = Edge(BLACK, n33, n34);
    
    // column 4 vertical edges
    Edge e41_42 = Edge(BLACK, n41, n42);
    Edge e43_44 = Edge(BLACK, n43, n44);
    
    // column 5 vertical edges
    Edge e52_53 = Edge(RED, n52, n53);
    Edge e53_54 = Edge(RED, n53, n54);
    
    // column 6 vertical edges
    Edge e61_62 = Edge(YELLOW, n61, n62);
    Edge e62_63 = Edge(BLACK, n62, n63);
    Edge e63_64 = Edge(BLACK, n63, n64);
    
    // column 7 vertical edges
    Edge e71_72 = Edge(BLACK, n71, n72);
    Edge e72_73 = Edge(BLACK, n72, n73);
    Edge e73_74 = Edge(BLACK, n73, n74);
    
    
    
    //e12_13.printInfo();
    Graph playground = Graph(NUM_NODES_IN_GRAPH);
    
    PrintMemoryUsage();
    
    // adding edges to playground
    
    // adding horizontal edges to playground
    
    // adding row 1 horizontal edges to graph
    playground.addEdge(e11_21);
    playground.addEdge(e21_31);
    playground.addEdge(e31_41);
    playground.addEdge(e51_61);
    playground.addEdge(e61_71);

    // adding row 2 horizontal edges to graph  
    playground.addEdge(e12_22);
    playground.addEdge(e22_32);
    playground.addEdge(e42_52);
    playground.addEdge(e52_62);
    playground.addEdge(e62_72);
    
    // adding row 3 horizontal edges to graph  
    playground.addEdge(e13_23);
    playground.addEdge(e23_33);
    playground.addEdge(e33_43);
    playground.addEdge(e43_53);
    
    // adding row 4 horizontal edges to graph  
    playground.addEdge(e14_24);
    playground.addEdge(e24_34);
    playground.addEdge(e44_54);
    playground.addEdge(e54_64);
    playground.addEdge(e64_74);
    
    // adding vertical edges to playground
    
    // adding column 1 vertical edges to graph  
    playground.addEdge(e11_12);
    playground.addEdge(e13_14);
    
    // adding column 2 vertical edges to graph  
    playground.addEdge(e22_23);
    
    // adding column 3 vertical edges to graph  
    playground.addEdge(e31_32);
    playground.addEdge(e32_33);
    playground.addEdge(e33_34);
    
    // adding column 4 vertical edges to graph  
    playground.addEdge(e41_42);
    playground.addEdge(e43_44);
    
    // adding column 5 vertical edges to graph  
    playground.addEdge(e52_53);
    playground.addEdge(e53_54);
    
    // adding column 6 vertical edges to graph  
    playground.addEdge(e61_62);
    playground.addEdge(e62_63);
    playground.addEdge(e63_64);
    
    // adding column 7 vertical edges to graph  
    playground.addEdge(e71_72);
    playground.addEdge(e72_73);
    playground.addEdge(e73_74);

    return playground;
}