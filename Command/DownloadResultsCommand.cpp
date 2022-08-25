//
// Created by liran on 25/08/2022.
//

#include "DownloadResultsCommand.h"
#include <iostream>
#include <fstream>

using namespace std;

void DownloadResultsCommand::execute() {
    cout << "Please enter a path to save the output file locally." << endl;
    string outputPath;
    getline(cin, outputPath);
    if (outputPath[0] == '\"') {
        outputPath.erase(0, 1);
    }
    if (outputPath[outputPath.length() - 1] == '\"') {
        outputPath.pop_back();
    }
    outputPath.append("/results.txt");
    cout << outputPath << endl;
    ofstream outputFile;
    outputFile.open(outputPath);
    if (!outputFile.is_open()) {
        cerr << "Error: file couldn't be opened!" << endl;
        execute();
        return;
    }

    if (flowerTypes->empty()) {
        cout << "You have to classify the data first!" << endl;
        return;
    }

    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        outputFile << i++ << " " << flowerType << endl;
    }
    cout << "Done." << endl;
    outputFile.close();
    string userInput;
    do {
        cin.ignore();
        getline(cin, userInput);
    } while (userInput.length() != 0);

}
