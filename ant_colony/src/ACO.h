#ifndef ACO_H
#define ACO_H
#include <Graph.h>
#include <Ant.h>
#include <unordered_map>
#include <vector>
#include <string>

class ACO {

public:
    ACO(const CitiesGraph &g, const std::string &startCity, const std::string &endCity, int colonySize):
    graph(g), cityStart(startCity), cityEnd(endCity), colony(std::vector<Ant>(colonySize)){};
    void calcShortestPath();

    std::vector<std::string> shortestPath;
    int shortestDist;

private:
    void calcAntSolution();
    void compareSolutions();
    void updatePher();
    bool endOfSearchCondition();

    std::vector<Ant> colony;
    CitiesGraph graph;
    std::string cityStart;
    std::string cityEnd;
    

    double alpha = 1.0;
    double beta = 1.0;
    double rho = 0.5;
};

#endif