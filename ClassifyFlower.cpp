//
// Created by liran on 29/07/2022.
//

#include "ClassifyFlower.h"
#include "DistanceCalculator.h"
#include "KNN.h"
#include <vector>

using namespace std;

vector<pair<Flower *, double>> ClassifyFlower::getEuclideanDistances() const {
    vector<pair<Flower *, double>> euclideanDistances;
    euclideanDistances.reserve(m_numOfFlowers);
    for (int i = 0; i < m_numOfFlowers; i++) {
        euclideanDistances.push_back((pair<Flower *, double>(&m_flowers[i],
                                                             DistanceCalculator::euclidean(m_unclassifiedFlower,
                                                                                           m_flowers[i]))));
    }
    return euclideanDistances;
}

string ClassifyFlower::euclideanClassify() {
    vector<pair<Flower *, double>> euclideanDistances = getEuclideanDistances();
    KNN::QuickSelect(m_k, euclideanDistances, 0, m_numOfFlowers - 1);
    return classifyByKNN(euclideanDistances);
}

vector<pair<Flower *, double>> ClassifyFlower::getChebyshevDistances() const {
    vector<pair<Flower *, double>> chebyshevDistances;
    chebyshevDistances.reserve(m_numOfFlowers);
    for (int i = 0; i < m_numOfFlowers; i++) {
        chebyshevDistances.push_back((pair<Flower *, double>(&m_flowers[i],
                                                             DistanceCalculator::chebyshev(m_unclassifiedFlower,
                                                                                           m_flowers[i]))));
    }
    return chebyshevDistances;
}

string ClassifyFlower::chebyshevClassify() {
    vector<pair<Flower *, double>> chebyshevDistances = getChebyshevDistances();
    KNN::QuickSelect(m_k, chebyshevDistances, 0, m_numOfFlowers - 1);
    return classifyByKNN(chebyshevDistances);
}

vector<pair<Flower *, double>> ClassifyFlower::getManhattanDistances() const {
    vector<pair<Flower *, double>> manhattanDistances;
    manhattanDistances.reserve(m_numOfFlowers);
    for (int i = 0; i < m_numOfFlowers; i++) {
        manhattanDistances.push_back((pair<Flower *, double>(&m_flowers[i],
                                                             DistanceCalculator::manhattan(m_unclassifiedFlower,
                                                                                           m_flowers[i]))));
    }
    return manhattanDistances;
}

string ClassifyFlower::manhattanClassify() {
    vector<pair<Flower *, double>> manhattanDistances = getManhattanDistances();
    KNN::QuickSelect(m_k, manhattanDistances, 0, m_numOfFlowers - 1);
    return classifyByKNN(manhattanDistances);
}


// runs the KNN algo on the array of pairs, then looks at the k first
// elements and classify the flower by them
string ClassifyFlower::classifyByKNN(vector<pair<Flower *, double>> distances) const {
    unsigned long size = m_types->size();
    vector<int> counterForTypes;
    counterForTypes.reserve(size);
    for (int j = 0; j < size; j++) {
        counterForTypes.push_back(0);
    }
    for (int i = 0; i < m_k; i++) {
        for (int j = 0; j < size; j++) {
            if (distances.at(i).first->getFlowerType() == (*m_types).at(j)) {
                counterForTypes.at(j)++;
            }
        }
    }

    unsigned long maxCounterIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (counterForTypes.at(i) > counterForTypes.at(maxCounterIndex)) {
            maxCounterIndex = i;
        }
    }
    return (*m_types).at(maxCounterIndex);
}
