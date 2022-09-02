//
// Created by liran on 24/08/2022.
//

#include "UploadCommand.h"
#include "../GetUnclassifiedFileData.h"

#include <cstring>

using namespace std;

// Class for the first command which gets the files from the user and saves them.
void UploadCommand::execute() {
    // Asks for the file.
    dio->write("[File]:Please upload your local train CSV file.\n");
    // Gets the data.
    string fileData = dio->read();
    // Saves the data.
    strcpy(classifiedTrainData, fileData.c_str());

    // Asks for the file.
    dio->write("[File]:Upload complete.\nPlease upload your local test CSV file.\n");

    fileData = dio->read();
    // Gets the data.
    strcpy(unclassifiedTestData, fileData.c_str());
    // Saves the data.
    dio->write("[Print]:Upload complete.\n");

    dio->read();
}