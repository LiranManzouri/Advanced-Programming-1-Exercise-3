#include "DistanceCalculator.h"

#include <cmath>

double DistanceCalculator::euclidean(const Flower &f1, const Flower &f2) {
    double sum = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        sum += pow(f1.getAttribute(i) - f2.getAttribute(i), 2);
    }
    return sqrt(sum);
}

double DistanceCalculator::chebyshev(const Flower &f1, const Flower &f2) {
    //the distance is the max of the simple distances
    double max = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        max = std::max(std::abs(f1.getAttribute(i) - f2.getAttribute(i)), max);
    }
    return max;
}

double DistanceCalculator::manhattan(const Flower &f1, const Flower &f2) {
    double distance = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        distance += std::abs(f1.getAttribute(i) - f2.getAttribute(i));
    }
    return distance;
}
