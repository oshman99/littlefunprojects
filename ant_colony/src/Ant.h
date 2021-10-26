#ifndef ANT_H
#define ANT_H
#include <Graph.h>
#include <cstdlib>
#include <unordered_map>
#include <string>

class Ant {

public:
    Ant(int visitsMax=3):maxVisits(visitsMax){}
    void goToCity(std::string cityName);
    bool isCityVisited(const std::string &cityName);
    int numOfVisitsInCity(const std::string &cityName);
    std::string getCurrentCity(){return currentCity;}

    std::vector<std::string> path;
    int dist;
    int maxVisits;
    
private:
    std::unordered_map<std::string, int> visitedCities; 
    std::string currentCity;    
    
    
};


#endif