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

class CLI {
    StandardIO socketIo;
    Command *commands[5]{};
    void printMenu();

public:
//    int getNewClient() const;

    /*explicit*/ CLI(/*int clientSocket*//*, int clientSocket*/) : socketIo(/*clientSocket*/) {
//        clientSocket = getNewClient();
//    std::string unclassifiedPath;
        int k = 5;
        char classifiedTrainData[4096];
        char unclassifiedTestData[4096];
        std::string distanceMetric = "EUC";
        std::vector<std::string> flowerTypes;
        commands[0] = new UploadCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                        &flowerTypes, &socketIo);
        commands[1] = new AlgoSettingsCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                              &flowerTypes, &socketIo);
        commands[2] = new ClassifyCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                          &flowerTypes, &socketIo);
        commands[3] = new PrintClassifiedCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes, &socketIo);
        commands[4] = new DownloadResultsCommand(&k, classifiedTrainData, unclassifiedTestData, &distanceMetric,
                                                 &flowerTypes, &socketIo);
    }

    void start();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H
