//
// Created by liran on 25/08/2022.
//

#include "../CreateClassifiedFiles.h"
#include "../GetUnclassifiedFileData.h"
#include "ClassifyCommand.h"

using namespace std;

// Class for the third command which classifying the unclassified (test) data.
void ClassifyCommand::execute() {
    // If the client didn't enter the files.
    if (unclassifiedTestData == nullptr || classifiedTrainData == nullptr ||
        unclassifiedTestData[0] == '\0' || classifiedTrainData[0] == '\0') {
        dio->write("[Print]:You have to enter the files first!\n");
        dio->read();
        return;
    }
    // Classifying the unclassified flowers.
    CreateClassifiedFiles createClassifiedFiles(*k, unclassifiedTestData, classifiedTrainData);
    *flowerTypes = createClassifiedFiles.createClassified();
    dio->write("[Print]:classifying data complete\n");
    dio->read();
}