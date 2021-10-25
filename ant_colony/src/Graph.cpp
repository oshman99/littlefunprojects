#include <Graph.h>


void CitiesGraph::addVertex(std::initializer_list<std::string> vertNameList) {

    for(auto vertName : vertNameList) {

    if (adjTable.count(vertName) == 1){
        std::cout << "City-vertex with name " << vertName << " already exists! \n";
        return;
    }
    adjTable[vertName];
    ++numOfVert;
    }
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

    //undirected graph - both ways
    adjTable[vertName1][vertName2].distance = dist;
    adjTable[vertName1][vertName2].pheromone = initPher;

    adjTable[vertName2][vertName1].distance = dist;
    adjTable[vertName2][vertName1].pheromone = initPher;
}

void CitiesGraph::removeVertex(const std::string& vertName) {

    if (adjTable.count(vertName) == 0){
        std::cout << "No city-vertex with name " << vertName << " exists \n";
        return;
    }
    adjTable.erase(vertName);
    --numOfVert;

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

    adjTable[vertName1].erase(vertName2);
}

void CitiesGraph::setPheromoneLevel(const std::string& vertName1, const std::string& vertName2, int newPher) {

    adjTable[vertName1][vertName2].pheromone = newPher;
    adjTable[vertName2][vertName1].pheromone = newPher;
}

int CitiesGraph::getPheromoneLevel(const std::string& vertName1, const std::string& vertName2) {
    return adjTable[vertName1][vertName2].pheromone;
}

void CitiesGraph::printGraph() {
    for(auto inVert : adjTable) {
        std::cout << "[" << inVert.first << "] -->";
        for(auto outVert : inVert.second) {
            std::cout << "[" << outVert.first << "] DIST: " << outVert.second.distance << " PHER: " << outVert.second.pheromone << "; ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}