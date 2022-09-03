//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CONFUSIONMATRIXCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CONFUSIONMATRIXCOMMAND_H


#include "Command.h"

class ConfusionMatrixCommand : public Command {

public:
    // Constructor.
    ConfusionMatrixCommand(int *k, char classifiedTrainData[16384], char unclassifiedTestData[16384],
                           std::string *distanceMetric, std::vector<std::string> *flowerTypes,
                           std::vector<std::string> *types, DefaultIO *dio)
            : Command("display algorithm confusion matrix", k, classifiedTrainData, unclassifiedTestData,
                      distanceMetric, flowerTypes, types, dio) {}

    // Executes the command.
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CONFUSIONMATRIXCOMMAND_H
