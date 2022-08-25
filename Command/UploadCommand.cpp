//
// Created by liran on 24/08/2022.
//

#include "UploadCommand.h"
#include "GetUnclassifiedFileData.h"
#include <iostream>
#include <cstring>

using namespace std;

void UploadCommand::execute() {
    cout << "Please upload your local train CSV file." << endl;

    string path;

    cin >> path;
    GetUnclassifiedFileData getTrainFileData(path);
    //    char message[4096] = {0};
    strcpy(classifiedTrainData, getTrainFileData.getData().c_str());

    // Send the unclassified path to the server.

//    clientFront.sendMessage(message);

    cout << "Upload complete." << endl;

    cout << "Please upload your local test CSV file." << endl;

    cin >> path;

    GetUnclassifiedFileData getTestFileData(path);
    strcpy(unclassifiedTestData, getTestFileData.getData().c_str());
//    cout << unclassifiedTestData << endl;
    // Send the unclassified path to the server.

//    clientFront.sendMessage(message);

    cout << "Upload complete." << endl;

}