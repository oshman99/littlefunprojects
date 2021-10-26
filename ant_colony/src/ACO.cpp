#include <ACO.h>

void ACO::calcShortestPath() {
    while(endOfSearchCondition()) {
        void calcAntSolution();
        void compareSolutions();
        void updatePher();
    }
}

bool ACO::endOfSearchCondition() {

    //visit every possible city 3 times
    bool isAntVisitedEveryCity = 0;
    std::vector<std::string> vecOfCities = graph.getVecOfCities();
    for(Ant ant:colony) {
        for(std::string city: vecOfCities){
            if(ant.numOfVisitsInCity(city) != ant.maxVisits){
                isAntVisitedEveryCity = 1;
            }
                
        }
    }

}
