//
// Created by liran on 25/08/2022.
//

#include "CLI.h"
#include <iostream>
#include <mutex>
#include <netinet/in.h>

using namespace std;

void CLI::start() {
    printMenu();
    string clientInput;
    clientInput = dio->read();
    int choose = stoi(clientInput);
    while (choose != 8) {
        commands[choose - 1]->execute();
        cout << "menu is..." << endl;
        printMenu();
        clientInput = dio->read();
        choose = stoi(clientInput);
    }
}

void CLI::printMenu() {
    string message = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int i = 1;
    for (auto &command: commands) {
        message.append(to_string(i++) + ". " + command->getDescription() + "\n");
    }
    dio->write(message);
}