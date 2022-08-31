//
// Created by liran on 25/08/2022.
//

#include "../CreateClassifiedFiles.h"
#include "ConfusionMatrixCommand.h"

#include <iostream>
#include <cmath>

using namespace std;

void ConfusionMatrixCommand::execute() {

    CreateClassifiedFiles createClassifiedFiles(*k, classifiedTrainData, classifiedTrainData);
    vector<string> classifiedTypes = createClassifiedFiles.createClassified();

    string types = classifiedTrainData;
    vector<string> realTypes;

    // cout << types << endl;
    string line;
    char delim = ',';
    while (!types.empty()) {
        line = types.substr(0, types.find('\n'));
        while (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
        }
        realTypes.push_back(line);
        types.erase(0, types.find('\n') + 1);
    }

    // for (auto &type : realTypes) {
    //     cout << type << endl;
    // }

    double matrix[3][3] = {0};

    for (int i = 0; i < realTypes.size(); i++) {
        if (realTypes.at(i) == classifiedTypes.at(i) && realTypes.at(i) == "Iris-setosa") {
            matrix[0][0]++;
        } else if (realTypes.at(i) == classifiedTypes.at(i) && realTypes.at(i) == "Iris-versicolor") {
            matrix[1][1]++;
        } else if (realTypes.at(i) == classifiedTypes.at(i) && realTypes.at(i) == "Iris-virginica") {
            matrix[2][2]++;
        } else if (realTypes.at(i) == "Iris-setosa" && classifiedTypes.at(i) == "Iris-versicolor") {
            matrix[0][1]++;
        } else if (realTypes.at(i) == "Iris-setosa" && classifiedTypes.at(i) == "Iris-virginica") {
            matrix[0][2]++;
        } else if (realTypes.at(i) == "Iris-versicolor" && classifiedTypes.at(i) == "Iris-setosa") {
            matrix[1][0]++;
        } else if (realTypes.at(i) == "Iris-versicolor" && classifiedTypes.at(i) == "Iris-virginica") {
            matrix[1][2]++;
        } else if (realTypes.at(i) == "Iris-virginica" && classifiedTypes.at(i) == "Iris-setosa") {
            matrix[2][0]++;
        } else if (realTypes.at(i) == "Iris-virginica" && classifiedTypes.at(i) == "Iris-versicolor") {
            matrix[2][1]++;
        }
    }

    double percentsMatrix[3][3] = {0};
    for (int j = 0; j < 3; j++) {
        double total = matrix[j][0] + matrix[j][1] + matrix[j][2];
        for (int l = 0; l < 3; l++) {
            percentsMatrix[j][l] = round((matrix[j][l] / total) * 100);
        }
    }

    string typesArray[3] = {"Iris-setosa", "Iris-versicolor", "Iris-virginica"};
    for (int j = 0; j < 3; j++) {
        cout << typesArray[j] << '\t';
        for (int l = 0; l < 3; l++) {
            cout << percentsMatrix[j][l] << "%" << '\t';
        }
        cout << endl;
    }
    cout << '\t' << typesArray[0] << '\t' << typesArray[1] + '\t' << typesArray[2] << endl;


    /*                0             1               2
     *              setosa      versicolor      virginica
     *0 setosa        100%           0%             0%
     *
     *1 versicolor     0%           100%            0%
     *
     *2 virginica      0%            7%            93%
     */
}