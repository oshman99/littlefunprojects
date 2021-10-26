#include <iostream>
#include <string>
#include <vector>

#include <Graph.h>
#include <Ant.h>
#include <ACO.h>


std::vector<std::string> getShortestPathAndDistanceACO(int colonySize, const std::string &city1, const std::string &city2, CitiesGraph &graph);
double generateProb();
double calcNewPheromone(double oldPheromone, double alpha, double beta, double rho, int dist);


int main() {
    CitiesGraph graph;
    graph.addVertex({"A", "B", "V", "G", "D", "E"});

    graph.addEdge("A", "B", 7);
    graph.addEdge("A", "V", 3);
    graph.addEdge("B", "E", 7);
    graph.addEdge("B", "D", 4);
    graph.addEdge("V", "G", 2);
    graph.addEdge("G", "D", 3);
    graph.addEdge("G", "E", 3);
    graph.addEdge("D", "E", 4);

    std::cout << graph.getPheromoneLevel("A", "B") << " A-B pher \n";

    graph.setPheromoneLevel("A", "B", 0.2);

    std::cout << graph.getPheromoneLevel("A", "B") << " A-B new pher \n";
    graph.printGraph();

}

std::vector<std::string> getShortestPathAndDistanceACO(int colonySize, const std::string &city1, const std::string &city2, CitiesGraph &graph) {
    std::vector<Ant> colony(colonySize);
    while(true) {
        for(Ant itAnt: colony) {

        }
    }

}

