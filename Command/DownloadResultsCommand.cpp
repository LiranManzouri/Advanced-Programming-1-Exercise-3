//
// Created by liran on 25/08/2022.
//

#include "DownloadResultsCommand.h"
#include <iostream>
#include <fstream>

using namespace std;

void DownloadResultsCommand::execute() {
    dio->write("Please enter a path to save the output file locally.\n");
    string outputPath = dio->read();
    if (outputPath[0] == '\"') {
        outputPath.erase(0, 1);
    }
    if (outputPath[outputPath.length() - 1] == '\"') {
        outputPath.pop_back();
    }
    outputPath.append("/results.txt");
//    cout << outputPath << endl;
    ofstream outputFile;
    outputFile.open(outputPath);
    if (!outputFile.is_open()) {
        dio->write("Error: file couldn't be opened!\n");
        execute();
        return;
    }

    if (flowerTypes->empty()) {
        dio->write("You have to classify the data first!\n");
        return;
    }

    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        outputFile << i++ << " " << flowerType << endl;
    }
    outputFile.close();
    string userInput;
    do {
        userInput = dio->read();
    } while (userInput != "\n");
}
