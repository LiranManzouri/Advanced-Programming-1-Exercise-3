//
// Created by liran on 25/08/2022.
//

#include "AlgoSettingsCommand.h"

using namespace std;

// Class for the second command which sends the knn parameters to the client.
void AlgoSettingsCommand::execute() {
    string algoSettings = "The current KNN parameters are: K = " + to_string(*k) +
                          ", distance metric = " + (*distanceMetric) + "\n";
    dio->write(algoSettings);
    string userInput = dio->read();

    // Returns after enter.
    if (userInput == "[Enter]") {
        return;
    } else {
        // Waits for a valid input.
        bool failed;
        do {
            // Returns after enter.
            failed = false;
            if (userInput == "[Enter]") {
                failed = false;
                continue;
            }
            // Checks if the server got a number.
            string token = userInput.substr(0, userInput.find(' '));
            for (char c: token) {
                if (!isdigit(c)) {
                    failed = true;
                }
            }
            // Isn't a number.
            if (failed) {
                dio->write("First input needs to be a natural number between 1 and 10\n");
                userInput = dio->read();
                continue;
            }
            // Checks that the number is between 1 and 10.
            int userK = stoi(userInput.substr(0, userInput.find(' ')));
            if (userK > 10 || userK < 1) {
                dio->write("Invalid value for K, enter a natural number between 1 and 10\n");
                failed = true;
                userInput = dio->read();
                continue;
            }
            // Checks the distance metric that the client sent.
            userInput.erase(0, userInput.find(' ') + 1);
            string userDistanceMetric = userInput.substr(0, userInput.find('\n'));
            if (userDistanceMetric != "MAN" && userDistanceMetric != "CHE" && userDistanceMetric != "EUC") {
                dio->write("Invalid distance metric, enter MAN/EUC/CHE\n");
                failed = true;
                userInput = dio->read();
                continue;
            }
            // Updates the knn parameters.
            *k = userK;
            *distanceMetric = userDistanceMetric;
            failed = false;
            // Until the client sends a valid input.
        } while (failed);
    }
}
