//
// Created by liran on 24/08/2022.
//

#include "UploadCommand.h"
#include "../GetUnclassifiedFileData.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void UploadCommand::execute() {

    dio->write("Please upload your local train CSV file.\n");

    string path = dio->read();
    GetUnclassifiedFileData getTrainFileData(dio, path);
    strcpy(classifiedTrainData, getTrainFileData.getData().c_str());

    dio->write("Upload complete.\n");

    dio->write("Please upload your local test CSV file.\n");

    path = dio->read();
    GetUnclassifiedFileData getTestFileData(dio, path);
    strcpy(unclassifiedTestData, getTestFileData.getData().c_str());

    dio->write("Upload complete.\n");


}