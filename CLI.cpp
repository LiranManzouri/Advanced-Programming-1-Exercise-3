//
// Created by liran on 25/08/2022.
//

#include "CLI.h"
#include <iostream>
#include <mutex>
#include <netinet/in.h>

using namespace std;
mutex m;

void CLI::start() {
    printMenu();
    string clientInput;
    clientInput = socketIo.read();
    int choose = stoi(clientInput);
    while (choose != 8) {
        commands[choose - 1]->execute();
        printMenu();
        clientInput = socketIo.read();
        choose = stoi(clientInput);
    }
}

void CLI::printMenu() {
    unique_lock<mutex> ul(m);
    string message = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int i = 1;
    for (auto &command: commands) {
        message.append(to_string(i++) + ". " + command->getDescription() + "\n");
    }
    socketIo.write(message);
}