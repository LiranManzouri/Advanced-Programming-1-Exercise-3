//
// Created by liran on 01/09/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_EXITCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_EXITCOMMAND_H


#include "Command.h"

class ExitCommand : public Command {
public:
    ExitCommand(int *k, char classifiedTrainData[8192], char unclassifiedTestData[8192],
                           std::string *distanceMetric, std::vector<std::string> *flowerTypes, DefaultIO *dio)
            : Command("exit", k, classifiedTrainData, unclassifiedTestData, distanceMetric,
                      flowerTypes, dio) {}

    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_EXITCOMMAND_H
