//
// Created by liran on 28/07/2022.
//

#include "ReadFlowers.h"
#include "CreateFlowerByLine.h"
#include <iostream>
#include <fstream>

using namespace std;

void ReadFlowers::readAndSaveFlowers() {
    int numOfFlowers = getNumOfFlowers();
    if (numOfFlowers == -1) {
        return;
    }
    flowers = new Flower[numOfFlowers];
    ifstream flowersInputFile;
    flowersInputFile.open(fileName);
    if (!flowersInputFile.is_open()) {
        return;
    }
    string line;
    int index = 0;
    while (!flowersInputFile.eof()) {
        getline(flowersInputFile, line);
        if (line.empty()) {
            continue;
        }
        CreateFlowerByLine createFlowerByLine(line);
        Flower flower = createFlowerByLine.getFlower();
        flowers[index] = flower;
        index++;
    }
}

int ReadFlowers::getNumOfFlowers() {
    int numOfFlowers = 0;
    ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        return -1;
    }
    string line;
    while (!inputFile.eof()) {
        getline(inputFile, line);
        if (line.empty()) {
            continue;
        }
        numOfFlowers++;
    }
    return numOfFlowers;
}