//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H


#include "Command/Command.h"
#include "Command/UploadCommand.h"
#include "Command/AlgoSettingsCommand.h"
#include "ClassifyCommand.h"
#include "PrintClassifiedCommand.h"
#include "DownloadResultsCommand.h"

class CLI {
    int serverSocket;
    Command *commands[5]{};

    void printMenu();

public:
    explicit CLI(int serverSocket) : serverSocket(serverSocket) {
//    std::string unclassifiedPath;
        int k = 5;
        char classifiedTrainData[4096];
        char unclassifiedTestData[4096];
        std::string distanceMetric = "EUC";
        std::vector<std::string> flowerTypes;
        commands[0] = new UploadCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                        &flowerTypes);
        commands[1] = new AlgoSettingsCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                              &flowerTypes);
        commands[2] = new ClassifyCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                          &flowerTypes);
        commands[3] = new PrintClassifiedCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes);
        commands[4] = new DownloadResultsCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes);
    }

    void start();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H
