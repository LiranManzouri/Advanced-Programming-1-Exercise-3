#include "DistanceCalculator.h"

#include <cmath>

// Calculates the euclidean distance according to the flowers attributes.
double DistanceCalculator::euclidean(Flower &f1, Flower &f2) {
    // Add zeros if one flower has more attributes than the other one.
    if (f1.numOfAttributes() > f2.numOfAttributes()) {
        for (int i = 0; i < f1.numOfAttributes() - f2.numOfAttributes(); i++) {
            f2.addAttribute(0);
        }
    } else if (f1.numOfAttributes() < f2.numOfAttributes()) {
        for (int i = 0; i < f2.numOfAttributes() - f1.numOfAttributes(); i++) {
            f1.addAttribute(0);
        }
    }
    // Calculates the distance.
    double distance = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        distance += pow(f1.getAttribute(i) - f2.getAttribute(i), 2);
    }
    return sqrt(distance);
}

// Calculates the chebyshev distance according to the flowers attributes.
double DistanceCalculator::chebyshev(Flower &f1, Flower &f2) {
    // Add zeros if one flower has more attributes than the other one.
    if (f1.numOfAttributes() > f2.numOfAttributes()) {
        for (int i = 0; i < f1.numOfAttributes() - f2.numOfAttributes(); i++) {
            f2.addAttribute(0);
        }
    } else if (f1.numOfAttributes() < f2.numOfAttributes()) {
        for (int i = 0; i < f2.numOfAttributes() - f1.numOfAttributes(); i++) {
            f1.addAttribute(0);
        }
    }
    // Calculates the distance.
    double distance = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        distance = std::max(std::abs(f1.getAttribute(i) - f2.getAttribute(i)), distance);
    }
    return distance;
}

// Calculates the manhattan distance according to the flowers attributes.
double DistanceCalculator::manhattan(Flower &f1, Flower &f2) {
    // Add zeros if one flower has more attributes than the other one.
    if (f1.numOfAttributes() > f2.numOfAttributes()) {
        for (int i = 0; i < f1.numOfAttributes() - f2.numOfAttributes(); i++) {
            f2.addAttribute(0);
        }
    } else if (f1.numOfAttributes() < f2.numOfAttributes()) {
        for (int i = 0; i < f2.numOfAttributes() - f1.numOfAttributes(); i++) {
            f1.addAttribute(0);
        }
    }
    // Calculates the distance.
    double distance = 0;
    for (int i = 0; i < f1.numOfAttributes(); i++) {
        distance += std::abs(f1.getAttribute(i) - f2.getAttribute(i));
    }
    return distance;
}