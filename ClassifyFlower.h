//
// Created by liran on 29/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYFLOWER_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYFLOWER_H

#include <utility>
#include <vector>
#include "Flower.h"

class ClassifyFlower {

    const Flower m_unclassifiedFlower;
    const int m_numOfFlowers;
    const int m_k;
    const std::vector<std::string> *m_types;
    Flower *m_flowers;

    std::vector<std::pair<Flower *, double>> getEuclideanDistances() const;

    std::vector<std::pair<Flower *, double>> getChebyshevDistances() const;

    std::vector<std::pair<Flower *, double>> getManhattanDistances() const;


    std::string classifyByKNN(std::vector<std::pair<Flower *, double>> distances) const;

public:

    ClassifyFlower(const Flower &unclassifiedFlower, Flower *flowers, int numOfFlowers, int k,
                   const std::vector<std::string> *types) :
            m_unclassifiedFlower(unclassifiedFlower), m_flowers(flowers), m_numOfFlowers(numOfFlowers), m_k(k) {
        m_types = types;
    }

    std::string euclideanClassify();

    std::string chebyshevClassify();

    std::string manhattanClassify();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYFLOWER_H
