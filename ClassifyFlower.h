//
// Created by liran on 29/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYFLOWER_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYFLOWER_H

#include <vector>
#include "Flower.h"

class ClassifyFlower {

    const Flower unclassifiedFlower;
    const int numOfFlowers;
    const int k;
    Flower *flowers;

    std::vector<std::pair<Flower *, double>> getEuclideanDistances() const;

    std::vector<std::pair<Flower *, double>> getChebyshevDistances() const;

    std::vector<std::pair<Flower *, double>> getManhattanDistances() const;


    std::string classifyByKNN(std::vector<std::pair<Flower *, double>> distances) const;

public:

    ClassifyFlower(const Flower &unclassifiedFlower, Flower *flowers, int numOfFlowers, int k) :
            unclassifiedFlower(unclassifiedFlower), flowers(flowers), numOfFlowers(numOfFlowers), k(k) {}

    std::string euclideanClassify();

    std::string chebyshevClassify();

    std::string manhattanClassify();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYFLOWER_H
