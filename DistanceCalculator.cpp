#include "DistanceCalculator.h"

#include <cmath>

// Calculates the euclidean distance according to the flowers attributes.
double DistanceCalculator::euclidean(const Flower& f1, const Flower& f2) {
    // Calculates the distance.
    double distance = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        distance += pow(f1.getAttribute(i) - f2.getAttribute(i), 2);
    }
    return sqrt(distance);
}

// Calculates the chebyshev distance according to the flowers attributes.
double DistanceCalculator::chebyshev(const Flower& f1, const Flower& f2) {
    // Calculates the distance.
    double distance = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        distance = std::max(std::abs(f1.getAttribute(i) - f2.getAttribute(i)), distance);
    }
    return distance;
}

// Calculates the manhattan distance according to the flowers attributes.
double DistanceCalculator::manhattan(const Flower& f1, const Flower& f2) {
    // Calculates the distance.
    double distance = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        distance += std::abs(f1.getAttribute(i) - f2.getAttribute(i));
    }
    return distance;
}