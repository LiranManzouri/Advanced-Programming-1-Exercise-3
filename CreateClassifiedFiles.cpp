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
    int numOfClassifiedFlowers = 0;
    string currentData = m_classifiedFlowers;
    while (!currentData.empty()) {
        currentData.erase(0, currentData.find('\n') + 1);
        numOfClassifiedFlowers++;
    }

    vector<string> flowerTypesByOrder;

    Flower classified[numOfClassifiedFlowers];
    int i = 0;
    currentData = m_classifiedFlowers;
    string line;
    while (!currentData.empty()) {
        line = currentData.substr(0, currentData.find('\n'));
        currentData.erase(0, currentData.find('\n') + 1);
        if (line.empty()) {
            break;
        }
        CreateFlowerByLine createFlowerByLine(line);
        Flower flower = createFlowerByLine.getFlower();
        classified[i] = flower;
        i++;
    }
    string info = m_flowersInfoToClassify;
    i = 0;
    //writes the classified info to the array.
    while (!info.empty()) {
        line = info.substr(0, info.find('\n'));
        info.erase(0, info.find('\n') + 1);
        if (line.empty()) {
            break;
        }
        CreateFlowerByLine createFlowerByLine(line);
        const Flower unclassifiedFlower = createFlowerByLine.getFlower();
        ClassifyFlower classifyFlower(unclassifiedFlower, classified, numOfClassifiedFlowers, m_k, m_types);
        if (m_distanceMetric == "MAN") {
            flowerTypesByOrder.push_back(classifyFlower.manhattanClassify());
        } else if (m_distanceMetric == "EUC") {
            flowerTypesByOrder.push_back(classifyFlower.euclideanClassify());
        } else if (m_distanceMetric == "CHE") {
            flowerTypesByOrder.push_back(classifyFlower.chebyshevClassify());
        }
        i++;
    }
    return flowerTypesByOrder;
}
