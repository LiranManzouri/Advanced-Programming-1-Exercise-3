#include "KNN.h"

using namespace std;


// It takes a vector of pairs of pointers to flowers and their distance to the flower,
// and returns the index of the pivot element. It also moves all smaller element to the left of
// the pivot and greater elements to the right of the pivot.
int KNN::partition(vector<pair<Flower *, double>> &arr, int left, int right, int pivot) {
    // Gets the pivot to its right place using swaps.
    double x = arr.at(pivot).second;
    swap(arr.at(pivot), arr.at(right));
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr.at(j).second <= x) {
            swap(arr.at(j), arr.at(i));
            i++;
        }
    }
    swap(arr.at(right), arr.at(i));
    return i;
}


// It takes a vector of pairs of pointers to flowers and distances, and sort it
// such that the first k elements in the vector are the k smallest distances.

void KNN::QuickSelect(int k, vector<pair<Flower *, double>> &arr, int left, int right) {
    // If the vector contains only one element, return.
    if (left == right) {
        return;
    }
    // Takes the middle as the pivot and does the partition on it.
    int pivotIndex = left + (right - left) / 2;
    pivotIndex = partition(arr, left, right, pivotIndex);
    // The pivot is in its right position.
    if (pivotIndex == k) {
        return;
    }
    // Recursive quick select on the left side.
    if (k < pivotIndex) {
        return QuickSelect(k, arr, left, pivotIndex - 1);
    }
    // Recursive quick select on the right side.
    return QuickSelect(k, arr, pivotIndex + 1, right);
}
