#include <Graph.h>


void CitiesGraph::addVertex(const std::string& vertName) {

    if (adjTable.count(vertName) == 1){
        std::cout << "City-vertex with name " << vertName << " already exists! \n";
        return;
    }

    adjTable[vertName];
    ++numOfVert;
}

void CitiesGraph::addEdge(const std::string& vertName1, const std::string& vertName2, int dist) {
    if (adjTable.count(vertName1) == 0 || adjTable.count(vertName2) == 0){
        std::cout << "No city-vertex with names " << vertName1 << " or " << vertName2 << " exists \n";
        return;
    }
    else if(adjTable[vertName2].count(vertName2) == 1) {
        std::cout << "Path from " << vertName1 << " to "<< vertName2 <<" already exists! \n";
        return;
    }
    adjTable[vertName1][vertName2].distance = dist;
    adjTable[vertName1][vertName2].pheromone = initPher;
}

void CitiesGraph::removeVertex(const std::string& vertName) {

    if (adjTable.count(vertName) == 1){
        std::cout << "No city-vertex with name " << vertName << " exists \n";
        return;
    }
    adjTable[vertName].clear();
    adjTable.erase(vertName);

}

void CitiesGraph::removeEdge(const std::string& vertName1, const std::string& vertName2) {

    if (adjTable.count(vertName1) == 0 || adjTable.count(vertName2) == 0){
        std::cout << "No city-vertex with names " << vertName1 << " or " << vertName2 << " exists \n";
        return;
    }

    else if(adjTable[vertName2].count(vertName2) == 1) {
        std::cout << "Path from " << vertName1 << " to "<< vertName2 <<" already exists! \n";
        return;
    }
}