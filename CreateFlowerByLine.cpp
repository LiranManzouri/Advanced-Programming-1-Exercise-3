//
// Created by liran on 23/08/2022.
//

#include "CreateFlowerByLine.h"
#include "Converts/StringTo.h"

#include <string>

using namespace std;

// Reads the line, save the data and attributes and returns the flower.
Flower CreateFlowerByLine::getFlower() {
    const char delim = ',';
    // Adding every attribute.
    vector<string> stringAttributes;
    while (line.find(delim) != string::npos) {
        string attribute = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        stringAttributes.push_back(attribute);
    }
    // Saves the last attribute.
    string lastAttribute = line.substr(0, line.find('\r'));
    lastAttribute.append("\0");
    line.erase();
    stringAttributes.push_back(lastAttribute);

    // Saves the attributes without the flower type.
    vector<double> doubleAttributes;
    doubleAttributes.reserve(stringAttributes.size() - 1);
    for (int i = 0; i < stringAttributes.size() - 1; ++i) {
        doubleAttributes.push_back(stod(stringAttributes.at(i)));
    }
    string flowerType;
    // The last attribute can be either a double number (if the flower
    // is unclassified) or the flower type (if the flower is classified).
    if (StringTo::Double(lastAttribute)) {
        doubleAttributes.push_back(stod(lastAttribute));
    } else {
        flowerType = lastAttribute;
    }
    // Returns a flower appropriate to the flower type and the attributes.
    Flower flower = Flower(flowerType, doubleAttributes);
    return flower;
}
