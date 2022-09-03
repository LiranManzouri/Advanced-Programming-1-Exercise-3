//
// Created by liran on 24/08/2022.
//

#include "UploadCommand.h"
#include "../Converts/StringTo.h"

#include <cstring>
#include <algorithm>

using namespace std;

// Class for the first command which gets the files from the user and saves them.
void UploadCommand::execute() {
    // Asks for the file.
    dio->write("[File]:Please upload your local train CSV file.\n");
    // Gets the data.
    string fileData = dio->read();
    // Saves the data.
    strcpy(classifiedTrainData, fileData.c_str());

    // Saves all the flower types.
    saveTypes(fileData);

    // Asks for the file.
    dio->write("[File]:Upload complete.\nPlease upload your local test CSV file.\n");

    fileData = dio->read();
    // Gets the data.
    strcpy(unclassifiedTestData, fileData.c_str());

    // Saves all the flower types.
    saveTypes(fileData);

    // Saves the data.
    dio->write("[Print]:Upload complete.\n");

    dio->read();
}

void UploadCommand::saveTypes(string fileData) {
    string line;
    char delim = ',';
    while (!fileData.empty()) {
        line = fileData.substr(0, fileData.find('\n'));
        while (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
        }
        if (!StringTo::Double(line)) {
            types->push_back(line);
        }
        fileData.erase(0, fileData.find('\n') + 1);
    }
    sort(types->begin(), types->end());
    types->erase(unique(types->begin(), types->end()), types->end());
}
