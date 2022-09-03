//
// Created by liran on 30/07/2022.
//

#include "CreateClassifiedFiles.h"
#include "ReadFlowers.h"
#include "ClassifyFlower.h"
#include "CreateFlowerByLine.h"

using namespace std;

// Classifies the given unclassified data by the given classified data and returns the classification types.
vector<string> CreateClassifiedFiles::createClassified() const {
    // Calculates the number of classified flowers.
    int numOfClassifiedFlowers = 0;
    string currentData = m_classifiedFlowers;
    while (!currentData.empty()) {
        currentData.erase(0, currentData.find('\n') + 1);
        numOfClassifiedFlowers++;
    }

    // Saves the classified flowers.
    Flower classified[numOfClassifiedFlowers];
    // Saves a copy of the classified flowers.
    currentData = m_classifiedFlowers;
    int i = 0;
    string line;
    // Runs on the whole data and cut it by lines and get the flowers.
    while (!currentData.empty()) {
        line = currentData.substr(0, currentData.find('\n'));
        currentData.erase(0, currentData.find('\n') + 1);
        if (line.empty()) {
            break;
        }
        // Get the flower from the line.
        CreateFlowerByLine createFlowerByLine(line);
        Flower flower = createFlowerByLine.getFlower();
        classified[i] = flower;
        i++;
    }
    // Saves a copy of the unclassified flowers.
    string info = m_flowersInfoToClassify;
    i = 0;
    // Saves the types after classifying.
    vector<string> flowerTypesByOrder;
    // Runs on the unclassified data, cut it by lines, get the flower from the line and classify it.
    while (!info.empty()) {
        // Gets the line.
        line = info.substr(0, info.find('\n'));
        info.erase(0, info.find('\n') + 1);
        if (line.empty()) {
            break;
        }
        // Gets the flower.
        CreateFlowerByLine createFlowerByLine(line);
        const Flower unclassifiedFlower = createFlowerByLine.getFlower();
        // Classifies the flower accordingly to the given distance metric and save the type.
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
    // Returns the types.
    return flowerTypesByOrder;
}
