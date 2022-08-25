//
// Created by liran on 25/08/2022.
//

#include "AlgoSettingsCommand.h"
#include <iostream>

using namespace std;

void AlgoSettingsCommand::execute() {
    cout << "The current KNN parameters are: K = " << *k << ", distance metric = " << *distanceMetric << endl;
    string userInput;
    cin.ignore();
    getline(cin, userInput);
    if (userInput.length() == 0) {
        return;
    } else {
        bool failed;
        do {
            failed = false;
            string token = userInput.substr(0, userInput.find(' '));
            for (char c : token) {
                if (!isdigit(c)) {
                    failed = true;
                }
            }
            if (failed) {
                cerr << "First input needs to be a number!" << endl;
                getline(cin, userInput);
                continue;
            }
            int userK = stoi(userInput.substr(0, userInput.find(' ')));
            if (userK > 10 || userK < 1) {
                cerr << "Invalid value for K" << endl;
                failed = true;
                getline(cin, userInput);
                continue;
            }
            userInput.erase(0, userInput.find(' ') + 1);
            string userDistanceMetric = userInput.substr(0, userInput.find('\r'));
            if (userDistanceMetric != "MAN" && userDistanceMetric != "CHE" && userDistanceMetric != "EUC") {
                cerr << "Invalid distance metric" << endl;
                failed = true;
                getline(cin, userInput);
                continue;
            }
            *k = userK;
            *distanceMetric = userDistanceMetric;
            failed = false;
        } while (failed);
    }
}
