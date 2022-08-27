//
// Created by liran on 25/08/2022.
//

#include "PrintClassifiedCommand.h"
#include <iostream>

using namespace std;

void PrintClassifiedCommand::execute() {
    if (flowerTypes->empty()) {
        dio->write("You have to classify the data first!\n");
        return;
    }

    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        dio->write(to_string(i++) + " " + flowerType + "\n");
    }
    dio->write("Done.\n");

    string userInput;
    do {
        userInput = dio->read();
    } while (userInput != "\n");
}