//
// Created by liran on 24/08/2022.
//

#include "UploadCommand.h"
#include "../GetUnclassifiedFileData.h"
#include <iostream>
#include <fstream>

using namespace std;

void UploadCommand::execute() {

    dio->write("Please upload your local train CSV file.\n");
    ofstream outTrainFileInServer("TrainFile.csv");
    string line;
    while ((line = dio->read()).length() != 0) {
        outTrainFileInServer << line << endl;
    }

    outTrainFileInServer.close();
    dio->write("Upload complete.\n");


    dio->write("Please upload your local test CSV file.\n");
    ofstream outTestFileInServer("TestFile.csv");
    while (!(line = dio->read()).empty()) {
        outTestFileInServer << line << endl;
    }
    outTestFileInServer.close();
    dio->write("Upload complete.");


}