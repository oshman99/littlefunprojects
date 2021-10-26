#include <Ant.h>

bool Ant::isCityVisited(const std::string &cityName) {
    return (visitedCities.count(cityName) == 1);
}

int Ant::numOfVisitsInCity(const std::string &cityName) {
    //if city been visited
    if(isCityVisited(cityName)) {
        return visitedCities[cityName];
    }
    return 0;
}

void Ant::goToCity(std::string cityName){
    currentCity = cityName; 
    visitedCities[cityName]++;
    }

