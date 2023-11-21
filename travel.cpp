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
 @return finalPath ONE LARGE COMBINED PATH
 */

// real header:
//void travel(Graph playground, Node& start, Node& end){
Path travel(Graph playground, Node& start, Node& end, Node& blocked){
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

        finalPath = initialPath + detourPath; // concatenate both paths (+ operator overloaded in Path.cpp)
    }
    // case where the blocked node was NOT encountered, and NO detour path was needed
    else{
        finalPath = initialPath;
    }

    finalPath.findInstructions(); // compute directions and vehicle instructions

    return finalPath;
}

/////////////////////////////////////////////////////////////////////////////

struct DoublePath{
    Path initial;
    Path detour;
};


/**
 * same as travel but two separate Paths are returned in DoublePath struct
*/
DoublePath travelSeparated(Graph playground, Node& start, Node& end, Node& blocked){
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
    
    initialPath.findInstructions();

    // case where the blocked node was encountered, and a detour path was necessary
    if (detour){ 
        cout << endl;

        // replace last instruction of initialPath by 'b'
        char back = 'b';
        initialPath.setInstructionsIndex(initialPathLen, back);

        int dirArraySize = initialPath.getNumNodes() - 1;

        // get last direction integer of initialPath 
        // and first direction integer of detourPath
        int i_lastDirInit = initialPath.getCurrentDirectionInt(dirArraySize);
        int i_firstDirDetour = initialPath.getCurrentDirectionInt(0);

        // compute shortest path between current node and the end knowing
        // the location of the blocked node
        detourPath = computeDijkstra(playground, currentNode, end);
        detourPath.findInstructions();

        // using the previously found direction integers, 
        // deduce the first instruction of detourPath, replacing cardinal direction
        char c_firstDirDetour = directionToInstruction(i_lastDirInit, i_firstDirDetour);
        detourPath.setInstructionsIndex(0, c_firstDirDetour);

    }
    // case where the blocked node was NOT encountered, and NO detour path was needed
    else{}

    // return both initial and detour paths with DoublePath struct
    DoublePath doublePath;
    doublePath.initial = initialPath;
    doublePath.detour = detourPath;

    return doublePath;
}



