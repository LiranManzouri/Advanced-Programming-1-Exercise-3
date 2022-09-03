//
// Created by liran on 28/07/2022.
//

#include "ReadFlowers.h"
#include "CreateFlowerByLine.h"

#include <iostream>
#include <fstream>

using namespace std;

// Reads the file and saves the flowers.
void ReadFlowers::readAndSaveFlowers() {
    // Gets the number of flowers.
    int numOfFlowers = getNumOfFlowers();
    // Checks that the file isn't empty.
    if (numOfFlowers == -1) {
        return;
    }
    // Creates the flowers array on the heap.
    flowers = new Flower[numOfFlowers];
    // Open the file path and makes sure that the file is opened.
    ifstream flowersInputFile;
    flowersInputFile.open(filePath);
    if (!flowersInputFile.is_open()) {
        return;
    }
    // Saves a line every time and gets the flower by the line.
    string line;
    int index = 0;
    while (!flowersInputFile.eof()) {
        // Saves the line.
        getline(flowersInputFile, line);
        if (line.empty()) {
            continue;
        }
        // Creates the flower and adds it to the flowers array.
        CreateFlowerByLine createFlowerByLine(line);
        Flower flower = createFlowerByLine.getFlower();
        flowers[index] = flower;
        index++;
    }
}

// Gets the number of flowers in the file.
int ReadFlowers::getNumOfFlowers() {
    // Opens the file.
    int numOfFlowers = 0;
    ifstream inputFile;
    inputFile.open(filePath);
    if (!inputFile.is_open()) {
        return -1;
    }
    // Gets a line and increasing the numOfFlowers counter until the end of the file.
    string line;
    while (!inputFile.eof()) {
        getline(inputFile, line);
        if (line.empty()) {
            continue;
        }
        numOfFlowers++;
    }
    // Returns the number of flowers.
    return numOfFlowers;
}