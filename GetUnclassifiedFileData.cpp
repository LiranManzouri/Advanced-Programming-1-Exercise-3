//
// Created by liran on 25/08/2022.
//

#include "GetUnclassifiedFileData.h"
#include "ReadFlowers.h"

#include <iostream>

using namespace std;

// Reads the given file and returns the data in it.
string GetUnclassifiedFileData::getData() {
    string stringMessage;
    // Reads the flowers and saves them.
    ReadFlowers unclassifiedReader = ReadFlowers(unclassifiedPath);
    unclassifiedReader.readAndSaveFlowers();
    // Gets the number of flowers.
    int numOfUnclassifiedFlowers = unclassifiedReader.getNumOfFlowers();
    // Empty file - which means wrong file path, ask the client for a new path.
    if (numOfUnclassifiedFlowers == -1) {
        cout << "Wrong file path! Try again:" << endl;
        getline(cin, unclassifiedPath);
        // Returns the data according to this new path.
        return getData();
    }
    // Saves the flowers that stored in the file.
    Flower *unclassifiedFlowers = unclassifiedReader.getFlowers();
    // Saves the current flower to the string - attributes are seperated by ',' and flowers seperated by  '\n'.
    for (int j = 0; j < numOfUnclassifiedFlowers; j++) {
        const Flower unclassifiedFlower = unclassifiedFlowers[j];
        // Appends the attributes.
        stringMessage.append(to_string(unclassifiedFlower.getAttribute(0)));
        for (int i = 1; i < unclassifiedFlower.numOfAttributes(); i++) {
            stringMessage.append("," + to_string(unclassifiedFlower.getAttribute(i)));
        }
        // Appends the flower types if its classified flower only.
        if (unclassifiedFlower.getFlowerType().empty()) {
            stringMessage.append("\n");
            continue;
        }
        stringMessage.append("," + unclassifiedFlower.getFlowerType() + "\n");
    }
    return stringMessage;
}
