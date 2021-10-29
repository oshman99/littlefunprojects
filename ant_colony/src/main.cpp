#include <iostream>
#include <string>
#include <vector>

#include <Graph.h>
#include <Ant.h>
#include <ACO.h>



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

    ACO solver(graph, "B", "V", 1);
    std::cout << solver.colony[0].getCurrentCity() << "\n";
    solver.calcAntSolution();
    std::cout << solver.colony[0].getCurrentCity()<< "\n";

}


