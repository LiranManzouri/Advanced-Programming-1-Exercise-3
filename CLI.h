//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H


#include "IO/StandardIO.h"
#include "IO/SocketIO.h"
#include "Command/Command.h"
#include "Command/UploadCommand.h"
#include "Command/AlgoSettingsCommand.h"
#include "Command/ClassifyCommand.h"
#include "Command/PrintClassifiedCommand.h"
#include "Command/DownloadResultsCommand.h"
#include "Command/ConfusionMatrixCommand.h"
#include "Command/ExitCommand.h"

class CLI {
    DefaultIO *dio;
    Command *commands[7]{};
    int k = 5;
    char classifiedTrainData[16384] = {0};
    char unclassifiedTestData[16384] = {0};
    std::string distanceMetric = "EUC";
    std::vector<std::string> flowerTypes;
    void printMenu();

public:
//    int getNewClient() const;

    explicit CLI(DefaultIO * dio/*, int clientSocket*/) : dio(dio) {
//        clientSocket = getNewClient();
//    std::string unclassifiedPath;
        commands[0] = new UploadCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                        &flowerTypes, dio);
        commands[1] = new AlgoSettingsCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                              &flowerTypes, dio);
        commands[2] = new ClassifyCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                          &flowerTypes, dio);
        commands[3] = new PrintClassifiedCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes, dio);
        commands[4] = new DownloadResultsCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes, dio);
        commands[5] = new ConfusionMatrixCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes, dio);
        commands[6] = new ExitCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes, dio);
    }

    ~CLI() {
        for (auto &command : commands) {
            delete command;
        }
    }

    void start();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H
