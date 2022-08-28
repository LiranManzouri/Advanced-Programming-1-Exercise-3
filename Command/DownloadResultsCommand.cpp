//
// Created by liran on 25/08/2022.
//

#include "DownloadResultsCommand.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void DownloadResultsCommand::execute() {
    if (flowerTypes->empty()) {
        dio->write("[Print]:You have to classify the data first!\n");
        dio->read();
        return;
    }

    dio->write("[Create File]:Please enter a path to save the output file locally.\n");
    dio->read();

    string outputData;
    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        outputData.append(to_string(i++) + " " + flowerType + "\n");
    }

    dio->write(outputData);
    dio->read();
}
