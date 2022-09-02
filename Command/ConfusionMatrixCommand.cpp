//
// Created by liran on 25/08/2022.
//

#include "../CreateClassifiedFiles.h"
#include "ConfusionMatrixCommand.h"

#include <cmath>

using namespace std;
// Class for the sixth command which calculates a matrix that the element (i,j)
// is the percents to classify organ from type i to type j, according to the train data.
void ConfusionMatrixCommand::execute() {

    // If the user hasn't entered the classified file.
    if (classifiedTrainData == nullptr || classifiedTrainData[0] == '\0') {
        dio->write("[Print]:You have to enter the classified (train) file first!\n");
        dio->read();
        return;
    }

    // Classifying the train data.
    CreateClassifiedFiles createClassifiedFiles(*k, *distanceMetric, classifiedTrainData, classifiedTrainData);
    vector<string> classifiedTypes = createClassifiedFiles.createClassified();

    //
    string trainData = classifiedTrainData;
    vector<string> realTypes;

    string line;
    // Gets the real types.
    char delim = ',';
    while (!trainData.empty()) {
        line = trainData.substr(0, trainData.find('\n'));
        while (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
        }
        realTypes.push_back(line);
        trainData.erase(0, trainData.find('\n') + 1);
    }

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

    int percentsMatrix[3][3] = {0};
    for (int j = 0; j < 3; j++) {
        double total = matrix[j][0] + matrix[j][1] + matrix[j][2];
        for (int l = 0; l < 3; l++) {
            percentsMatrix[j][l] = (int) (round((matrix[j][l] / total) * 100));
        }
    }

    string percentsString;
    string typesArray[3] = {"Iris-setosa", "Iris-versicolor", "Iris-virginica"};
    percentsString.append('\t' + typesArray[0] + '\t' + typesArray[1] + '\t' + typesArray[2] + "\n");
    for (int j = 0; j < 3; j++) {
        percentsString.append(typesArray[j] + '\t');
        for (int l = 0; l < 3; l++) {
            percentsString.append(to_string(percentsMatrix[j][l]) + "%" + '\t');
        }
        percentsString.append("\n");
    }

    // Sending the matrix and the knn parameters to the client.
    percentsString.append("The current KNN parameters are: K = " + to_string(*k) +
                          ", distance metric = " + (*distanceMetric) + "\n");
    dio->write(percentsString);
    string userInput = dio->read();
    while (userInput != "[Enter]") {
        dio->write("[Waiting for enter]");
        userInput = dio->read();
    }
    /*                0             1               2
     *              setosa      versicolor      virginica
     *0 setosa        100%           0%             0%
     *
     *1 versicolor     0%           100%            0%
     *
     *2 virginica      0%            7%            93%
     */
}