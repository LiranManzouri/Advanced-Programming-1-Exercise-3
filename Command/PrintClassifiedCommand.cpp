//
// Created by liran on 25/08/2022.
//

#include "PrintClassifiedCommand.h"
#include <iostream>

using namespace std;

void PrintClassifiedCommand::execute() {
    if (flowerTypes->empty()) {
        cout << "You have to classify the data first!" << endl;
        return;
    }

    int i = 1;
    for (auto &flowerType: *flowerTypes) {
        cout << i++ << " " << flowerType << endl;
    }
    cout << "Done." << endl;

    string userInput;
    do {
        cin.ignore();
        getline(cin, userInput);
    } while (userInput.length() != 0);
}