//
// Created by liran on 23/08/2022.
//

#include "CreateFlowerByLine.h"
#include "Converts/StringTo.h"

#include <string>

using namespace std;

Flower CreateFlowerByLine::getFlower() {
    const char delim = ',';
    vector<string> stringAttributes;
    while (line.find(delim) != string::npos) {
        string attribute = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + 1);
        stringAttributes.push_back(attribute);
    }
    string lastAttribute = line.substr(0, line.find('\r'));
    lastAttribute.append("\0");
    line.erase();

    stringAttributes.push_back(lastAttribute);

    vector<double> doubleAttributes;
    doubleAttributes.reserve(stringAttributes.size() - 1);
    for (int i = 0; i < stringAttributes.size() - 1; ++i) {
        doubleAttributes.push_back(stod(stringAttributes.at(i)));
    }

    string flowerType;
    if (StringTo::Double(lastAttribute)) {
        doubleAttributes.push_back(stod(lastAttribute));
    } else {
        flowerType = lastAttribute;
    }

    Flower flower = Flower(flowerType, doubleAttributes);
    return flower;
}
