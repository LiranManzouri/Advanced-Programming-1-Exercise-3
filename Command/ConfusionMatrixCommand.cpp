//
// Created by liran on 25/08/2022.
//

#include "../CreateClassifiedFiles.h"
#include "ConfusionMatrixCommand.h"

#include <cmath>
#include <algorithm>

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
    // Gets the real types of the flowers in the classified train data.
    char delim = ',';
    while (!trainData.empty()) {
        line = trainData.substr(0, trainData.find('\n'));
        while (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
        }
        realTypesByOrder.push_back(line);
        trainData.erase(0, trainData.find('\n') + 1);
    }

    // Creates new matrix size*size and initialize it all to 0.
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

    // The matrix mentioned above will save the details that belong
    // to the type i but were classified by the classifier to type j.
    // Counts for every real type.
    for (int i = 0; i < realTypesByOrder.size(); i++) {
        for (int j = 0; j < size; ++j) {
            // Same type.
            if (realTypesByOrder.at(i) == classifiedTypes.at(i) && realTypesByOrder.at(i) == types->at(j)) {
                matrix.at(j).at(j)++;
            } else {
                // Checks which type is the classifier classified it and increases in the appropriate place.
                for (int l = 0; l < size; l++) {
                    if (realTypesByOrder.at(i) == types->at(j) && classifiedTypes.at(i) == types->at(l)) {
                        matrix.at(j).at(l)++;
                    }
                }
            }
        }
    }

    // Saves the rounded (floor) percents.
    vector<vector<int>> intPercentsMatrix;
    intPercentsMatrix.reserve(size);

    // Calculates the floored percents by the matrix above.
    for (int i = 0; i < size; i++) {
        intPercentsMatrix.emplace_back();
        // Saves the exact percents.
        vector<double> doublePercentsMatrix;
        double totalInRow = 0;
        // Total number of elements in the i-th row.
        for (int j = 0; j < size; j++) {
            totalInRow += matrix[i][j];
        }
        // One saves the exact percent and the other saves the rounded percents.
        for (int j = 0; j < size; ++j) {
            doublePercentsMatrix.push_back((matrix[i][j] / totalInRow) * 100);
            intPercentsMatrix[i].push_back(floor((matrix[i][j] / totalInRow) * 100));
        }
        // Total percents in a row.
        int totalPercentsInRow = 0;
        for (int j = 0; j < size; j++) {
            totalPercentsInRow += intPercentsMatrix[i][j];
        }
        // The number of percents which are missing to complete the percents sum to 100%.
        int remainedTo100 = 100 - totalPercentsInRow;
        // The errors of the double exact percents (the numbers after the dot).
        vector<pair<double, int>> errors;
        errors.reserve(size);
        // Calculates the error and add it to the errors vector.
        for (int j = 0; j < size; j++) {
            errors.emplace_back(doublePercentsMatrix[j] - floor(doublePercentsMatrix[j]), j);
        }
        // Sorting the errors vector.
        sort(errors.begin(), errors.end());
        // Add 1 percent to the percents with the highest errors until the sum is 100%.
        for (int j = 0; j < remainedTo100; j++) {
            // Sorted in ascending order so we need the last elements for the highest error.
            intPercentsMatrix[i][errors[size - j - 1].second]++;
        }
    }

    // The final matrix to send to the client, as a string.
    string percentsString;
    // Prints the types of the columns.
    for (int i = 0; i < size; i++) {
        percentsString.append("\t\t" + types->at(i));
    }
    percentsString.append("\n");
    // Saves the current type and the current row from the percents' matrix.
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