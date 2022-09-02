//
// Created by liran on 25/08/2022.
//

#include "GetUnclassifiedFileData.h"
#include "ReadFlowers.h"
#include <iostream>
#include <vector>

using namespace std;

string GetUnclassifiedFileData::getData() {
    string stringMessage;
    ReadFlowers unclassifiedReader = ReadFlowers(unclassifiedPath);
    unclassifiedReader.readAndSaveFlowers();
    int numOfUnclassifiedFlowers = unclassifiedReader.getNumOfFlowers();
    if (numOfUnclassifiedFlowers == -1) {
//        dio->write("Error: file couldn't be opened, Rewrite the file path!\n");
        cout << "Wrong file path! Try again:" << endl;
//        unclassifiedPath = dio->read();
        getline(cin, unclassifiedPath);
        return getData();
    }
    vector<string> flowerTypesByOrder;
    flowerTypesByOrder.reserve(numOfUnclassifiedFlowers);
    Flower *unclassifiedFlowers = unclassifiedReader.getFlowers();
    //writes the classified info to the array.
    for (int j = 0; j < numOfUnclassifiedFlowers; j++) {
        const Flower unclassifiedFlower = unclassifiedFlowers[j];
        stringMessage.append(to_string(unclassifiedFlower.getAttribute(0)));
        for (int i = 1; i < unclassifiedFlower.numOfAttributes(); i++) {
            stringMessage.append("," + to_string(unclassifiedFlower.getAttribute(i)));
        }

        if (unclassifiedFlower.getFlowerType().empty()) {
            stringMessage.append("\n");
            continue;
        }
        stringMessage.append("," + unclassifiedFlower.getFlowerType() + "\n");
    }
    return stringMessage;
}
