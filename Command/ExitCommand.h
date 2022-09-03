//
// Created by liran on 01/09/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_EXITCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_EXITCOMMAND_H


#include "Command.h"

class ExitCommand : public Command {
public:
    // Constructor.
    ExitCommand(int *k, char classifiedTrainData[16384], char unclassifiedTestData[16384],
                std::string *distanceMetric, std::vector<std::string> *flowerTypes, std::vector<std::string> *types,
                DefaultIO *dio)
            : Command("exit", k, classifiedTrainData, unclassifiedTestData, distanceMetric,
                      flowerTypes, types, dio) {}

    // Executes the command.
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_EXITCOMMAND_H
