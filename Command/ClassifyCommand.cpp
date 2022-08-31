//
// Created by liran on 25/08/2022.
//

#include "../CreateClassifiedFiles.h"
#include "../GetUnclassifiedFileData.h"
#include "ClassifyCommand.h"
#include <iostream>
#include <cstring>

using namespace std;

void ClassifyCommand::execute() {
    // GetUnclassifiedFileData getTrainFileData("TrainFile.csv");
    // strcpy(classifiedTrainData, getTrainFileData.getData().c_str());

    // GetUnclassifiedFileData getTestFileData("TestFile.csv");
    // strcpy(unclassifiedTestData, getTrainFileData.getData().c_str());

    // CreateClassifiedFiles createClassifiedFiles(*k, unclassifiedTestData);
    // *flowerTypes = createClassifiedFiles.createClassified();
    if (!unclassifiedTestData || !classifiedTrainData) {
        dio->write("[Print]:You have to enter the files first!\n");
        dio->read();
        return;
    }
    CreateClassifiedFiles createClassifiedFiles(*k, unclassifiedTestData, classifiedTrainData);
    *flowerTypes = createClassifiedFiles.createClassified();
    dio->write("[Print]:classifying data complete\n");
    dio->read();
}