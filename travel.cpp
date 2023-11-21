#pragma once
#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"
#include "Dijkstra.cpp"

#include "memoryDebug.cpp"

using namespace std;

/**
 * this function allows travel between two nodes while taking into account the blocked node
 * the vehicle doesn't know the blocked node at the beginning of the route
 * while on its initial path, if it encounters the blocked node, it will recalculate its trajectory
 * and change its course of direction
 @param playground graph representing the area the vehicle will travel on
 @param start starting node
 @param end ending node of that specific route
 @param blocked blocked node, temporary parameter
 */

// real header:
//void travel(Graph playground, Node& start, Node& end){
void travel(Graph playground, Node& start, Node& end, Node& blocked){
    Path initialPath = computeDijkstra(playground, start, end); // initial computed path
    Path detourPath; // initialisation, in case there is a detour path (there might not be one needed)

    Node currentNode = start;

    int initialPathLen = 0;
    bool detour = false;
    for (int i = 0; i < initialPath.getNumNodes(); i++){

        currentNode = initialPath.getNthNode(i);
        Node nextNode = initialPath.getNthNode(i + 1);
        initialPathLen++;

        if (nextNode.getId() == blocked.getId()){ //condition where the vehicle detects the pole

            initialPath = computeDijkstra(playground, start, nextNode); // segment initial path to stop point

            playground.removeNode(nextNode); // remove unavailable node

            detour = true; // flag indicating that there was a detour
            break;
        }
    }
    cout << endl;

    Path finalPath; // official final path of that specific route

    // case where the blocked node was encountered, and a detour path was necessary
    if (detour){ 
        detourPath = computeDijkstra(playground, currentNode, end);
        for (int i = 0; i < detourPath.getNumNodes(); i++){
            currentNode = detourPath.getNthNode(i);
        }
        finalPath = initialPath + detourPath; // concatenate both paths (+ operator overloaded in Path.cpp)
    }
    // case where the blocked node was NOT encountered, and NO detour path was needed
    else{
        finalPath = initialPath;
    }

    finalPath.findInstructions(); // compute directions and wehicle instructions

    finalPath.printPath(true);    // change how path is printed
    finalPath.printDirections();
}

