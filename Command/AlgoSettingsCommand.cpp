//
// Created by liran on 25/08/2022.
//

#include "AlgoSettingsCommand.h"
#include <iostream>

using namespace std;

void AlgoSettingsCommand::execute() {
//    cout << "The current KNN parameters are: K = " << *k << ", distance metric = " << *distanceMetric << endl;
    string algoSettings = "The current KNN parameters are: K = " + to_string(*k) +
                          ", distance metric = " + (*distanceMetric) + "\n";
    dio->write(algoSettings);
    string userInput = dio->read();
    if (userInput == "[Enter]") {
        return;
    } else {
        bool failed;
        do {
            failed = false;
            if (userInput == "[Enter]") {
                failed = false;
                continue;
            }
            string token = userInput.substr(0, userInput.find(' '));
            for (char c: token) {
                if (!isdigit(c)) {
                    failed = true;
                }
            }
            if (failed) {
                dio->write("First input needs to be a natural number between 1 and 10\n");
                userInput = dio->read();
                continue;
            }
            int userK = stoi(userInput.substr(0, userInput.find(' ')));
            if (userK > 10 || userK < 1) {
                dio->write("Invalid value for K, enter a natural number between 1 and 10\n");
                failed = true;
                userInput = dio->read();
                continue;
            }
            userInput.erase(0, userInput.find(' ') + 1);
            string userDistanceMetric = userInput.substr(0, userInput.find('\n'));
            if (userDistanceMetric != "MAN" && userDistanceMetric != "CHE" && userDistanceMetric != "EUC") {
                dio->write("Invalid distance metric, enter MAN/EUC/CHE\n");
                failed = true;
                userInput = dio->read();
                continue;
            }
            *k = userK;
            *distanceMetric = userDistanceMetric;
            failed = false;
        } while (failed);
    }
}
