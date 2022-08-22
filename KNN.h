#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_KNN_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_KNN_H

#include <vector>
#include "Flower.h"

// the class implements the quickselect algorithm by the second element in the pair, "double"
// which is responsable for the distance.
class KNN {
    // the partion part in quickselect
    static int partition(std::vector<std::pair<Flower *, double>>& arr, int left, int right, int pivot);

public:
    // the quickselect itself
    static void QuickSelect(int k, std::vector<std::pair<Flower *, double>>& arr, int left, int right);
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_KNN_H
