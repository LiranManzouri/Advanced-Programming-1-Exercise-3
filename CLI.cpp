//
// Created by liran on 25/08/2022.
//

#include "CLI.h"
#include <vector>
#include <iostream>

using namespace std;

void CLI::start() {
//    ServerFront front;
    printMenu();
    int choose = 0;
    cin >> choose;
    while (choose != 8) {
        commands[choose - 1]->execute();
        printMenu();
        cin >> choose;
    }
}

void CLI::printMenu() {
    cout << "Welcome to the KNN Classifier Server. Please choose an option:" << endl;
    int i = 1;
    for (auto &command: commands) {
        cout << i << ". " << command->getDescription() << endl;
        i++;
    }
}
