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

// Saves the types from the file data.
void UploadCommand::saveTypes(string fileData) {
    string line;
    char delim = ',';
    // Get the type from each row.
    while (!fileData.empty()) {
        // Gets a line.
        line = fileData.substr(0, fileData.find('\n'));
        // Skips the ','.
        while (line.find(delim) != string::npos) {
            line.erase(0, line.find(delim) + 1);
        }
        // If the last attribute is a double, it means we're in the unclassified file,
        // otherwise, we're in the classified file and this last attribute is a type.
        if (!StringTo::Double(line)) {
            types->push_back(line);
        }
        // Erase the current line.
        fileData.erase(0, fileData.find('\n') + 1);
    }
    // Remove duplicate elements from the types vector.
    sort(types->begin(), types->end());
    types->erase(unique(types->begin(), types->end()), types->end());
}