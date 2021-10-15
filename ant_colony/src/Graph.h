#ifndef GRAPH_H
#define GRAPH_H

/*----
Weighted undirected graph of cities using Adjacency Table
Unorded map of Unorded maps created, where keys are names of graph's vertices, values maps - keys-names and values-direction of their edges with distance
----*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct road {
    int distance;
    int pheromone;
};


class CitiesGraph {
public:
    CitiesGraph(int initPheromone): numOfVert(0), initPher(initPheromone){};
    void addVertex(const std::string& vertName);
    void addEdge(const std::string& vertName1, const std::string& vertName2, int dist);

    void removeVertex(const std::string& vertName);
    void removeEdge(const std::string& vertName1, const std::string& vertName2);

    std::unordered_map<std::string, std::unordered_map<std::string,road>> adjTable;
private:
    size_t numOfVert;
    int initPher;

};



#endif