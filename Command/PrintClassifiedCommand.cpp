//
// Created by liran on 25/08/2022.
//

#include "PrintClassifiedCommand.h"

#include <string>

using namespace std;

// Class for the fourth command which prints the classifying data in the client.
void PrintClassifiedCommand::execute() {
    // If the user hasn't entered the files.
    if (flowerTypes->empty()) {
        dio->write("[Print]:You have to classify the data first!\n");
        dio->read();
        return;
    }

    // Saves the data and sends to the client.
    string message;
    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        message.append(to_string(i++) + " " + flowerType + "\n");
    }
    message.append("Done.\n");
    dio->write(message);

    // Move on to the menu after the client enters the enter key.
    string userInput;
    userInput = dio->read();
    while (!(userInput == "[Enter]")) {
        dio->write("[Waiting for enter]");
        userInput = dio->read();
    }
}