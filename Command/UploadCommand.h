//
// Created by liran on 24/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H

#include "Command.h"

class UploadCommand : public Command {
public:
    UploadCommand(int *k, char classifiedTrainData[4096], char unclassifiedTestData[4096],
                  std::string *distanceMetric, std::vector<std::string> *flowerTypes) : Command(
            "upload un unclassified csv data file", k, classifiedTrainData,
            unclassifiedTestData, distanceMetric, flowerTypes) {}

    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
