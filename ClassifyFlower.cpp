//
// Created by liran on 29/07/2022.
//

#include "ClassifyFlower.h"
#include "DistanceCalculator.h"
#include "KNN.h"
#include <vector>
#include <iostream>

using namespace std;

vector<pair<Flower *, double>> ClassifyFlower::getEuclideanDistances() const {
    vector<pair<Flower *, double>> euclideanDistances;
    euclideanDistances.reserve(numOfFlowers);
    for (int i = 0; i < numOfFlowers; i++) {
        euclideanDistances.push_back((pair<Flower *, double>(&flowers[i],
                                                             DistanceCalculator::euclidean(unclassifiedFlower,
                                                                                           flowers[i]))));
    }
    return euclideanDistances;
}

string ClassifyFlower::euclideanClassify() {
    vector<pair<Flower *, double>> euclideanDistances = getEuclideanDistances();
    KNN::QuickSelect(k, euclideanDistances, 0, numOfFlowers - 1);
    return classifyByKNN(euclideanDistances);
}

vector<pair<Flower *, double>> ClassifyFlower::getChebyshevDistances() const {
    vector<pair<Flower *, double>> chebyshevDistances;
    chebyshevDistances.reserve(numOfFlowers);
    for (int i = 0; i < numOfFlowers; i++) {
        chebyshevDistances.push_back((pair<Flower *, double>(&flowers[i],
                                                             DistanceCalculator::chebyshev(unclassifiedFlower,
                                                                                           flowers[i]))));
    }
    return chebyshevDistances;
}

string ClassifyFlower::chebyshevClassify() {
    vector<pair<Flower *, double>> chebyshevDistances = getChebyshevDistances();
    KNN::QuickSelect(k, chebyshevDistances, 0, numOfFlowers - 1);
    return classifyByKNN(chebyshevDistances);
}

vector<pair<Flower *, double>> ClassifyFlower::getManhattanDistances() const {
    vector<pair<Flower *, double>> manhattanDistances;
    manhattanDistances.reserve(numOfFlowers);
    for (int i = 0; i < numOfFlowers; i++) {
        manhattanDistances.push_back((pair<Flower *, double>(&flowers[i],
                                                             DistanceCalculator::manhattan(unclassifiedFlower,
                                                                                           flowers[i]))));
    }
    return manhattanDistances;
}

string ClassifyFlower::manhattanClassify() {
    vector<pair<Flower *, double>> manhattanDistances = getManhattanDistances();
    KNN::QuickSelect(k, manhattanDistances, 0, numOfFlowers - 1);
    return classifyByKNN(manhattanDistances);
}


// runs the KNN algo on the array of pairs, then looks at the k first
// elements and classify the flower by them
string ClassifyFlower::classifyByKNN(vector<pair<Flower *, double>> distances) const {
    int counterForIrisSetosa = 0;
    int counterForIrisVersicolor = 0;
    int counterForIrisVirginica = 0;
    for (int i = 0; i < k; i++) {
        if (distances.at(i).first->getFlowerType() == "Iris-setosa") {
            counterForIrisSetosa++;
        }
        if (distances.at(i).first->getFlowerType() == "Iris-versicolor") {
            counterForIrisVersicolor++;
        }
        if (distances.at(i).first->getFlowerType() == "Iris-virginica") {
            counterForIrisVirginica++;
        }
    }
    int maxCounter = counterForIrisSetosa;
    maxCounter = max(maxCounter, counterForIrisVersicolor);
    maxCounter = max(maxCounter, counterForIrisVirginica);

    if (maxCounter == counterForIrisSetosa) {
        return "Iris-setosa";
    }
    if (maxCounter == counterForIrisVersicolor) {
        return "Iris-versicolor";
    }
    return "Iris-virginica";
}
