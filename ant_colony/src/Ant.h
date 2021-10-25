#ifndef ANT_H
#define ANT_H
#include <Graph.h>
#include <cstdlib>
#include <unordered_map>
#include <string>

class Ant {

public:
    void goToCity(std::string cityName);

    bool isCityVisited();
    int numOfVisitsInCity(std::string cityName);

    std::string getCurrentCity(){return currentCity;}
    void setCurrentCity(std::string cityName){currentCity = cityName; visitedCities[cityName]++;}

    std::unordered_map<std::string, int> visitedCities;
    
private:
    std::string currentCity;    
};


#endif