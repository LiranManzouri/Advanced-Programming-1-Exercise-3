//
// Created by liran on 25/08/2022.
//

#include "../CreateClassifiedFiles.h"
#include "ConfusionMatrixCommand.h"

#include <cmath>
#include <algorithm>
#include <iostream>

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
    CreateClassifiedFiles createClassifiedFiles(*k, *distanceMetric, classifiedTrainData,
                                                classifiedTrainData, types);
    vector<string> classifiedTypes = createClassifiedFiles.createClassified();

    string trainData = classifiedTrainData;
    vector<string> realTypesByOrder;

    string line;
    // Gets the real types.
    char delim = ',';
    while (!trainData.empty()) {
        line = trainData.substr(0, trainData.find('\n'));
        while (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
        }
        realTypesByOrder.push_back(line);
        trainData.erase(0, trainData.find('\n') + 1);
    }

    unsigned long size = types->size();
    vector<vector<double>> matrix;
    matrix.reserve(size);
    for (int i = 0; i < size; ++i) {
        vector<double> vec;
        vec.reserve(size);
        for (int j = 0; j < size; ++j) {
            vec.push_back(0);
        }
        matrix.push_back(vec);
    }

    for (int i = 0; i < realTypesByOrder.size(); i++) {
        for (int j = 0; j < size; ++j) {
            if (realTypesByOrder.at(i) == classifiedTypes.at(i) && realTypesByOrder.at(i) == types->at(j)) {
                matrix.at(j).at(j)++;
            } else {
                for (int l = 0; l < size; l++) {
                    if (realTypesByOrder.at(i) == types->at(j) && classifiedTypes.at(i) == types->at(l)) {
                        matrix.at(j).at(l)++;
                    }
                }
            }
        }
    }

    vector<vector<int>> intPercentsMatrix;
    intPercentsMatrix.reserve(size);

    for (int i = 0; i < size; i++) {
        intPercentsMatrix.emplace_back();
        vector<double> doublePercentsMatrix;
        double totalInRow = 0;
        for (int j = 0; j < size; j++) {
            totalInRow += matrix[i][j];
        }
        for (int j = 0; j < size; ++j) {
            doublePercentsMatrix.push_back((matrix[i][j] / totalInRow) * 100);
            intPercentsMatrix[i].push_back(floor((matrix[i][j] / totalInRow) * 100));
        }
        int totalPercentsInRow = 0;
        for (int j = 0; j < size; j++) {
            totalPercentsInRow += intPercentsMatrix[i][j];
        }
        int remainedTo100 = 100 - totalPercentsInRow;
        vector<pair<double, int>> errors;
        errors.reserve(size);
        for (int j = 0; j < size; j++) {
            errors.emplace_back(doublePercentsMatrix[j] - floor(doublePercentsMatrix[j]), j);
        }
        sort(errors.begin(), errors.end());
        for (int j = 0; j < remainedTo100; j++) {
            intPercentsMatrix[i][errors[size - j - 1].second]++;
        }
    }

    string percentsString;
    for (int i = 0; i < size; i++) {
        percentsString.append("\t\t" + types->at(i));
    }
    percentsString.append("\n");
    for (int i = 0; i < size; i++) {
        percentsString.append(types->at(i) + "\t\t");
        for (int j = 0; j < size; j++) {
            percentsString.append(to_string(intPercentsMatrix[i][j]) + "%" + "\t\t");
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
}