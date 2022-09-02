//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_PRINTCLASSIFIEDCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_PRINTCLASSIFIEDCOMMAND_H


#include "Command.h"

class PrintClassifiedCommand : public Command {

public:
    // Constructor.
    PrintClassifiedCommand(int *k, char classifiedTrainData[16384], char unclassifiedTestData[16384],
                           std::string *distanceMetric, std::vector<std::string> *flowerTypes, DefaultIO *dio)
            : Command("display results", k, classifiedTrainData, unclassifiedTestData, distanceMetric,
                      flowerTypes, dio) {}
    // Executes the command.
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_PRINTCLASSIFIEDCOMMAND_H
