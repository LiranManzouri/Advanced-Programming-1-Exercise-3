//
// Created by liran on 25/08/2022.
//

#include "CreateClassifiedFiles.h"
#include "ClassifyCommand.h"
#include <iostream>

using namespace std;

void ClassifyCommand::execute() {
    CreateClassifiedFiles createClassifiedFiles(*k, unclassifiedTestData);
    *flowerTypes = createClassifiedFiles.createClassified();
//    int i = 1;
//    for (auto &flowerType: *flowerTypes) {
//        cout << i++ << " " << flowerType << endl;
//    }
    cout << "classifying data complete" << endl;
//    char flowerTypesAsChar[4096] = {0};
//    int l = 0;
//    // Writes the classifiers types to the char array, seperated by '\n'.
//    for (auto &flowerType: flowerTypes) {
//        for (char k: flowerType) {
//            flowerTypesAsChar[l] = k;
//            l++;
//        }
//        flowerTypesAsChar[l] = '\n';
//        l++;
//    }
//    flowerTypesAsChar[l] = '\0';
//    // Sends the classified to the client.
//    cout << "==> Classified! Sending back to you..." << endl;
//    cout << flowerTypesAsChar << endl;
//    front.sendMessage(flowerTypesAsChar);
}