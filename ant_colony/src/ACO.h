#ifndef ACO_H
#define ACO_H
#include <Graph.h>
#include <Ant.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <random>

class ACO {

public:
    ACO(const CitiesGraph &g, const std::string &startCity, const std::string &endCity, int colonySize):
    graph(g), cityStart(startCity), cityEnd(endCity), colony(std::vector<Ant>(colonySize, startCity)){};
    void calcShortestPath();
    void calcAntSolution();
    std::vector<std::string> shortestPath;
    int shortestDist;
    std::vector<Ant> colony;

private:
    //void calcAntSolution();
    void compareSolutions();
    int chooseRndCityIndx(std::vector<double> probs);
    bool isEveryAntFinished();
    void updatePher();
    bool endOfSearchCondition();
    double calcPhOverDst(double pher, double dist);

    //std::vector<Ant> colony;
    CitiesGraph graph;
    std::string cityStart;
    std::string cityEnd;
    

    double alpha = 1.0;
    double beta = 1.0;
    double rho = 0.5;
    int antMaxVisit;
};

#endif