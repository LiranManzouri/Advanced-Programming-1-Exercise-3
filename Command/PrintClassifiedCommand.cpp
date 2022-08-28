//
// Created by liran on 25/08/2022.
//

#include "PrintClassifiedCommand.h"
#include <iostream>
#include <string>

using namespace std;

void PrintClassifiedCommand::execute() {
    if (flowerTypes->empty()) {
        dio->write("[Print]:You have to classify the data first!\n");
        dio->read();
        return;
    }

    string message;
    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        message.append(to_string(i++) + " " + flowerType + "\n");
    }
    message.append("Done.\n");
    dio->write(message);
    string userInput;
    userInput = dio->read();
    while (!(userInput == "[Enter]")) {
        dio->write("[Waiting for enter]");
        userInput = dio->read();
    }
}