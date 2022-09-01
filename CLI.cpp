//
// Created by liran on 25/08/2022.
//

#include "CLI.h"

using namespace std;

// Starts the client-server communication.
void CLI::start() {
    printMenu();
    // Gets the wished command.
    string clientInput;
    clientInput = dio->read();
    while (!isStringANumber(clientInput) ||
           (isStringANumber(clientInput) && (stoi(clientInput) > 7 || stoi(clientInput) < 1))) {
        dio->write("The input for the menu should be a natural number between 1 and 7!\n");
        clientInput = dio->read();
    }
    int choose = stoi(clientInput);
    // Does the command that the client wanted until exit.
    while (choose != 7) {
        commands[choose - 1]->execute();
        printMenu();
        clientInput = dio->read();
        while (!isStringANumber(clientInput) ||
               (isStringANumber(clientInput) && (stoi(clientInput) > 7 || stoi(clientInput) < 1))) {
            dio->write("The input for the menu should be a natural number between 1 and 7!\n");
            clientInput = dio->read();
        }
        choose = stoi(clientInput);
    }
    commands[choose - 1]->execute();
}

// Prints the menu by the commands' description.
void CLI::printMenu() {
    string message = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int i = 1;
    for (auto &command: commands) {
        message.append(to_string(i++) + ". " + command->getDescription() + "\n");
    }
    dio->write(message);
}

// Checks if a string is a number.
bool CLI::isStringANumber(const string &str) {
    bool isANumber = true;
    for (auto &ch: str) {
        if (!isdigit(ch)) {
            isANumber = false;
            break;
        }
    }
    return isANumber;
}
