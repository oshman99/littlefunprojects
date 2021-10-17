#ifndef CITIES_GRAPH_H
#define CITIES_GRAPH_H

/*----
Weighted undirected graph of cities using Adjacency Table.
Unorded map of Unorded maps is created, where in outer map:
keys: names of graph's vertices, 
values: inner maps, where keys: names of edge connection vertex and values: length of edge and pheromone level
----*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <initializer_list>

struct road {
    int distance;
    int pheromone;
};


class CitiesGraph {
public:
    CitiesGraph(int initPheromone): numOfVert(0), initPher(initPheromone){};
    CitiesGraph(): numOfVert(0), initPher(1){};
    
    void addVertex(std::initializer_list<std::string&> vertNameList);
    void addEdge(const std::string& vertName1, const std::string& vertName2, int dist);

    void removeVertex(const std::string& vertName);
    void removeEdge(const std::string& vertName1, const std::string& vertName2);

    void setPheromoneLevel(const std::string& vertName1, const std::string& vertName2, int newPher);
    int getPheromoneLevel(const std::string& vertName1, const std::string& vertName2);

    size_t getNumOfVerts() {return numOfVert;}

    void printGraph();

    
private:
    std::unordered_map<std::string, std::unordered_map<std::string, road>> adjTable;
    size_t numOfVert;
    int initPher;

};



#endif