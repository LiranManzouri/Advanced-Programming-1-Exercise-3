//
// Created by liran on 24/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H

#include "Command.h"

class UploadCommand : public Command {
public:
    // Constructor.
    UploadCommand(int *k, char classifiedTrainData[8192], char unclassifiedTestData[8192],
                  std::string *distanceMetric, std::vector<std::string> *flowerTypes, DefaultIO *dio) : Command(
            "upload un unclassified csv data file", k, classifiedTrainData, unclassifiedTestData,
            distanceMetric, flowerTypes, dio) {}
    // Executes the command.
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
