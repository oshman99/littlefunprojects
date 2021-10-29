#include <Ant.h>

bool Ant::isCityVisited(const std::string& cityName) const {
    return (visitedCities.count(cityName) == 1);
}

int Ant::numOfVisitsInCity(const std::string& cityName) const {
    //if city been visited
    if(isCityVisited(cityName)) {
        //const access
        return visitedCities.at(cityName);
    }
    return 0;
}

void Ant::goToCity(const std::string& cityName, int roadLength){
    path.push_back(cityName);
    pathLength += roadLength;
    currentCity = cityName; 
    visitedCities[cityName]++;
    }

void Ant::printPath() {
    for(auto city : path) {
        std::cout << city << "->";
    }
    std::cout << "|| " << pathLength << "\n";
}