//
// Created by liran on 28/07/2022.
//

#include "ReadFlowers.h"
#include <iostream>
#include <fstream>

using namespace std;

void ReadFlowers::readAndSaveFlowers() {
    int numOfFlowers = getNumOfFlowers();
    if (numOfFlowers == -1) {
        cerr << "Error: file couldn't be opened" << endl;
        return;
    }
    flowers = new Flower[numOfFlowers];
    ifstream flowersInputFile;
    flowersInputFile.open(fileName);
    if (!flowersInputFile.is_open()) {
        cerr << "Error: file couldn't be opened" << endl;
        return;
    }
    string line;
    const char delim = ',';
    int index = 0;
    while (!flowersInputFile.eof()) {
        getline(flowersInputFile, line);
        if (line.empty()) {
            continue;
        }
        string token1 = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        string token2 = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        string token3 = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        string token4 = line.substr(0, line.find(delim));
        string flowerType;
        if (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
            flowerType = line.substr(0, line.find('\r'));
            flowerType.append("\0");
            line.erase();
        }
        double calyxLeavesLength = stod(token1);
        double calyxLeavesWidth = stod(token2);
        double petalLength = stod(token3);
        double petalWidth = stod(token4);
        Flower flower = Flower(flowerType, calyxLeavesLength, calyxLeavesWidth, petalLength, petalWidth);
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