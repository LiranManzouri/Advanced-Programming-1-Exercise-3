#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_READFLOWERS_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_READFLOWERS_H

#include "Flower.h"

// Class that reads a flowers by the filePath
class ReadFlowers {

    // The file path and a flowers array to store the flowers.
    const std::string filePath;
    Flower *flowers;

public:
    // Constructor.
    explicit ReadFlowers(std::string fileName) : filePath(move(fileName)) {
        flowers = nullptr;
    }

    // Destructor - deletes the flowers array.
    ~ReadFlowers() {
        delete[] flowers;
    }

    // Getter for the flowers.
    Flower *getFlowers() {
        return flowers;
    }

    // Gets the number of flowers in the file by going line by line.
    int getNumOfFlowers();

    // Reads the flowers from the files and saves them.
    void readAndSaveFlowers();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_READFLOWERS_H
