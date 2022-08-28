//
// Created by liran on 24/08/2022.
//

#include "UploadCommand.h"
#include "../GetUnclassifiedFileData.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <mutex>

using namespace std;

void UploadCommand::execute() {
//    dio->write("[File]");
    dio->write("[File]:Please upload your local train CSV file.\n");

    string fileData = dio->read();
//    GetUnclassifiedFileData getTrainFileData(dio, path);
//    strcpy(classifiedTrainData, getTrainFileData.getData().c_str());

    strcpy(classifiedTrainData, fileData.c_str());

    // dio->write("Upload complete.\n");

//    dio->write("[File]");
    dio->write("[File]:Upload complete.\nPlease upload your local test CSV file.\n");

    fileData = dio->read();

//    GetUnclassifiedFileData getTestFileData(dio, path);
//    strcpy(unclassifiedTestData, getTestFileData.getData().c_str());

    strcpy(unclassifiedTestData, fileData.c_str());

    dio->write("[Print]:Upload complete.\n");

    dio->read();
}