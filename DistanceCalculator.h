#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_DISTANCECALCULATOR_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_DISTANCECALCULATOR_H

#include "Flower.h"

// Calculates distance between 2 flowers in several ways.
class DistanceCalculator {

public:
    static double euclidean(const Flower &f1, const Flower &f2);

    static double chebyshev(const Flower &f1, const Flower &f2);

    static double manhattan(const Flower &f1, const Flower &f2);


};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_DISTANCECALCULATOR_H
