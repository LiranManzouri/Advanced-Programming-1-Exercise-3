#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_KNN_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_KNN_H

#include "Flower.h"

#include <vector>

// The class implements the quick select algorithm by the second element in the pair - the distance.
class KNN {
    // The partition part in quick select algorithm.
    static int partition(std::vector<std::pair<Flower *, double>> &arr, int left, int right, int pivot);

public:
    // The quick select algorithm.
    static void QuickSelect(int k, std::vector<std::pair<Flower *, double>> &arr, int left, int right);
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_KNN_H
