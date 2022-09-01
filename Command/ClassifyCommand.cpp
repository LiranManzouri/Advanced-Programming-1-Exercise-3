//
// Created by liran on 25/08/2022.
//

#include <iostream>
#include "../CreateClassifiedFiles.h"
#include "../GetUnclassifiedFileData.h"
#include "ClassifyCommand.h"

using namespace std;

void ClassifyCommand::execute() {
    if (unclassifiedTestData == nullptr || classifiedTrainData == nullptr ||
        unclassifiedTestData[0] == '\0' || classifiedTrainData[0] == '\0') {
        dio->write("[Print]:You have to enter the files first!\n");
        dio->read();
        return;
    }
    CreateClassifiedFiles createClassifiedFiles(*k, unclassifiedTestData, classifiedTrainData);
    *flowerTypes = createClassifiedFiles.createClassified();
    dio->write("[Print]:classifying data complete\n");
    dio->read();
}