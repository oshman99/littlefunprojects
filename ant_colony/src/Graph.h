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
    double pheromone;
};

//esasier on the eyes
using adjacencyTableMap = std::unordered_map<std::string, std::unordered_map<std::string, road>>;

class CitiesGraph {
public:
    CitiesGraph(int initPheromone): numOfVert(0), initPher(initPheromone){};
    CitiesGraph(): numOfVert(0), initPher(1.0){};
    //copy constructor
    CitiesGraph(const CitiesGraph &g);
    
    void addVertex(std::initializer_list<std::string> vertNameList);
    void addEdge(const std::string& vertName1, const std::string& vertName2, int dist);

    void removeVertex(const std::string& vertName);
    void removeEdge(const std::string& vertName1, const std::string& vertName2);

    void setPheromoneLevel(const std::string& vertName1, const std::string& vertName2, double newPher);
    double getPheromoneLevel(const std::string& vertName1, const std::string& vertName2);

    std::unordered_map<std::string, road> getAdjCities(const std::string &cityName);

    std::vector<std::string> getVecOfCities();


    size_t getNumOfVerts() {return numOfVert;}

    void printGraph();

    
private:
    adjacencyTableMap adjTable;
    size_t numOfVert;
    double initPher;

};


#endif