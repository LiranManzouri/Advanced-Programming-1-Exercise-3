//
// Created by liran on 30/07/2022.
//

#include <iostream>
#include "CreateClassifiedFiles.h"
#include "ReadFlowers.h"
#include "ClassifyFlower.h"
#include "CreateFlowerByLine.h"

using namespace std;

/**
 * It reads the classified and unclassified flowers, and then
 * classifies the unclassified flowers by the three methods, and writes the results to the files
 */
vector<string> CreateClassifiedFiles::createClassified() const {
    //reads the flowers
    ReadFlowers classifiedReader = ReadFlowers("classified.csv");
    classifiedReader.readAndSaveFlowers();

    int numOfClassifiedFlowers = classifiedReader.getNumOfFlowers();
    if (numOfClassifiedFlowers == -1) {
        return {};
    }

    Flower *classifiedFlowers = classifiedReader.getFlowers();

    vector<string> flowerTypesByOrder;

    string info = flowersInfo;
    int i = 0;
    //writes the classified info to the array.
    while (!info.empty()) {
        string line = info.substr(0, info.find('\n'));
        info.erase(0, info.find('\n') + 1);
        CreateFlowerByLine createFlowerByLine(line);
        const Flower unclassifiedFlower = createFlowerByLine.getFlower();
        ClassifyFlower classifyFlower(unclassifiedFlower, classifiedFlowers, numOfClassifiedFlowers, k);
        flowerTypesByOrder.push_back(classifyFlower.euclideanClassify());
        i++;
    }
    return flowerTypesByOrder;
}
