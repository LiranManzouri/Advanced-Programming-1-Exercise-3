//
// Created by liran on 23/08/2022.
//

#include "CreateFlowerByLine.h"
#include <string>

using namespace std;

Flower CreateFlowerByLine::getFlower() {
    const char delim = ',';
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
    return flower;
}
