//
// Created by liran on 25/08/2022.
//

#include "DownloadResultsCommand.h"

#include <string>

using namespace std;

// Class for the fifth command which saves the classifying data in a local file of the client.
void DownloadResultsCommand::execute() {
    // If the user hasn't entered the files.
    if (flowerTypes->empty()) {
        dio->write("[Print]:You have to classify the data first!\n");
        dio->read();
        return;
    }

    // Asks for a file.
    dio->write("[Create File]:Please enter a path to save the output file locally.\n");
    dio->read();

    // Saves the data.
    string outputData;
    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        outputData.append(to_string(i++) + " " + flowerType + "\n");
    }

    // Sends the data.
    dio->write(outputData);
    dio->read();
}
