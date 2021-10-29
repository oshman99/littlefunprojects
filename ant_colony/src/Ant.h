#ifndef ANT_H
#define ANT_H
#include <Graph.h>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <string>

class Ant {

public:
    Ant(const std::string& base):baseCity(base), currentCity(base) {path.push_back(base);}
    //sets new city, if exeedes maxVisits, does nothing and returns 0
    void goToCity(const std::string& cityName, int roadLength);
    bool isCityVisited(const std::string& cityName) const;
    int numOfVisitsInCity(const std::string& cityName) const;
    void resetPath(){path.clear(); pathLength = 0;}
    void printPath();
    std::string getCurrentCity() const {return currentCity;}

    std::vector<std::string> path;
    int pathLength = 0;
    
private:
    std::unordered_map<std::string, int> visitedCities; 
    std::string currentCity;    
    std::string baseCity;
    
    
};


#endif