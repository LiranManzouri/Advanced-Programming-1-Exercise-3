//
// Created by liran on 25/08/2022.
//

#include "../CreateClassifiedFiles.h"
#include "ConfusionMatrixCommand.h"

#include <iostream>

using namespace std;

void ConfusionMatrixCommand::execute() {

    CreateClassifiedFiles createClassifiedFiles(*k, classifiedTrainData, classifiedTrainData);
    vector<string> classifiedTypes = createClassifiedFiles.createClassified();
    vector<string> realTypes;

    string types = classifiedTrainData;
    cout << types << endl;
//    while (!types.empty()) {
//
//    }

    int counterForIrisSetosa = 0;
    int counterForIrisVersicolor = 0;
    int counterForIrisVirginica = 0;

//    for (int i = 0; i < ; ++i) {
//
//    }


}
//    vector<string> columnsClassifiedTypes = *flowerTypes;
////    string columnClassifiedTypes = classifiedTrainData;
//
//    string line = classifiedTrainData;
//    vector<string> rowsRealTypes;
//    while (!line.empty()) {
//        string type = line.substr(0, line.find('\n'));
//        rowsRealTypes.push_back(type);
//        line.erase(0, line.find('\n') + 1);
//    }
//
//    int l = 1;
//    for (auto &type: rowsRealTypes) {
//        cout << l++ << " " << type << endl;
//    }
//
//
//
////    flowerType = line.substr(0, line.find('\r'));
//
//
//
//    int matrix[3][3];
//
//    /*                0             1               2
//     *              setosa      versicolor      virginica
//     *0 setosa        100%           0%             0%
//     *
//     *1 versicolor     0%           100%            0%
//     *
//     *2 virginica      0%            0%            100%
//     */
//
//    for (int i = 0; i < rowsRealTypes.size(); ++i) {
////        int setosaType = 0;
////        int versicolorType = 0;
////        int virginicaType = 0;
//        int totalSum = 0;
//        int realTypeCounter = 0;
//        int firstWrongTypeCounter = 0;
//        int secondWrongTypeCounter = 0;
//        for (int j = 0; j < columnsClassifiedTypes.size(); ++j) {
//            // Check if the real type is really what it is in the unclassified.csv
//            if (rowsRealTypes.at(i) == columnsClassifiedTypes.at(j)) {
//                realTypeCounter++;
//            } else if (i == 0 && columnsClassifiedTypes.at(j) == "Iris-Versicolor") {
//                firstWrongTypeCounter++;
//            } else if (i == 0 && columnsClassifiedTypes.at(j) == "Iris-Virginica") {
//                secondWrongTypeCounter++;
//            } else if (i == 1 && columnsClassifiedTypes.at(j) == "Iris-Setosa") {
//                firstWrongTypeCounter++;
//            } else if (i == 1 && columnsClassifiedTypes.at(j) == "Iris-Virginica") {
//                secondWrongTypeCounter++;
//            } else if (i == 2 && columnsClassifiedTypes.at(j) == "Iris-Setosa") {
//                firstWrongTypeCounter++;
//            } else if (i == 2 && columnsClassifiedTypes.at(j) == "Iris-Versicolor") {
//                secondWrongTypeCounter++;
//            }
//            totalSum = realTypeCounter + firstWrongTypeCounter + secondWrongTypeCounter;
//            cout << totalSum << endl;
//        }
//    }
////            if (i == j && rowsRealTypes.at(i) == columnsClassifiedTypes.at(j)) {
////                realTypeCounter++;
////            }
////            if (i == 0 && j == 1 && rowsRealTypes.at(i) != columnsClassifiedTypes.at(j)) {
////                firstWrongTypeCounter++;
////            }
////            if (i == 0 && j == 2 && rowsRealTypes.at(i) != columnsClassifiedTypes.at(j)) {
////                secondWrongTypeCounter++;
////            }
////            if (i == 1 & j == 0 && rowsRealTypes.at(i) != columnsClassifiedTypes.at(j)) {
////                firstWrongTypeCounter++;
////            }
////            if (i == 1 & j == 1 && rowsRealTypes.at(i) != columnsClassifiedTypes.at(j)) {
////                secondWrongTypeCounter++;
////            }
////            if (i == 2 & j == 0 && rowsRealTypes.at(i) != columnsClassifiedTypes.at(j)) {
////                firstWrongTypeCounter++;
////            }
////            if (i == 2 & j == 1 && rowsRealTypes.at(i) != columnsClassifiedTypes.at(j)) {
////                secondWrongTypeCounter++;
////            }
//
////            if (i == j - 2 || i == j + 2) { secondWrongTypeCounter++; }
////        }
////    }
//
////    cout << classifiedTrainData << endl;
//
//
//
//}
