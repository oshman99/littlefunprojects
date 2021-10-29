#include <ACO.h>

void ACO::calcShortestPath() {
    calcAntSolution();
}


/*
Main probability P of choosing road from i node to j node equasion:
P_i_j(t) = (pher_i_j(t)^alpha * (1/dist_i_j)^beta)/
            sum_over_all_k_roads_from_i((pher_i_k(t)^alpha * (1/dist_i_k)^beta));

Let (pher_i_j(t)^alpha * (1/dist_i_j)^beta) = phOverDst_i_j, so P becomes:
P_i_j(t) = phOverDst_i_j/sum_aver_all(phOverDst_i_k);

Next iteration pheromone equasion:
pher_i_j(t+1) = (1-rho)pher_i_j(t) + d_pher; where d_pher = 1/L_k if ant k traverses on edje i,j and d_pher = 0 otherwise. L_k - length of path of ant k.
*/
void ACO::calcAntSolution() {
    //test
    while(!isEveryAntFinished()) {
    /*
    for(ant : colony){
        if ant is not on finished node 
            include only probs of cities visited less than 3 times
            if all cities visied 3 times
                set stuck flag?
                skip
            get next city
        else skip
    }
    */
    std::vector<double> probs;
    double adjSum = 0;
    std::string currentAntCity = colony[0].getCurrentCity();
    for(const auto& city : graph.getAdjCities(currentAntCity)) {
        double probOfCurrentCity = calcPhOverDst(city.second.pheromone, city.second.distance);
        adjSum+=probOfCurrentCity;
        probs.push_back(probOfCurrentCity);
    }

    for(double& prob:probs) {
        prob /= adjSum;
    }

    int cityIndx = chooseRndCityIndx(probs);
    auto adjCities = graph.getAdjCities(currentAntCity);
    auto adjCitiesIt = adjCities.begin();
    std::advance(adjCitiesIt, cityIndx);
    std::string resultCity = adjCitiesIt->first;
    graph(currentAntCity, resultCity).distance;
    colony[0].goToCity(resultCity,  graph(currentAntCity, resultCity).distance);

    }
}


double ACO::calcPhOverDst(double pher, double dist) {
    return pow(pher, alpha) * pow(1/dist, beta);
}

bool ACO::isEveryAntFinished() {
    bool antsFlag = true;
    for(auto& ant: colony){
        if(ant.getCurrentCity() != cityEnd)
            antsFlag = false;
        ant.printPath();
    }
    return antsFlag;
}

int ACO::chooseRndCityIndx(std::vector<double> probs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    auto it = probs.begin();

    double probSum = *it;
    double rndProb = dis(gen);
    int cityIndx = 0;
    while(rndProb >= probSum)
    {
        ++cityIndx;
        ++it;
        probSum += *it;
    }
    return cityIndx;
}