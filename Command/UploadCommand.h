//
// Created by liran on 24/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H

#include "Command.h"

class UploadCommand : public Command {
    void saveTypes(std::string fileData);

public:
    // Constructor.
    UploadCommand(int *k, char classifiedTrainData[16384], char unclassifiedTestData[16384],
                  std::string *distanceMetric, std::vector<std::string> *flowerTypes, std::vector<std::string> *types,
                  DefaultIO *dio) : Command(
            "upload un unclassified csv data file", k, classifiedTrainData, unclassifiedTestData,
            distanceMetric, flowerTypes, types, dio) {}

    // Executes the command.
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
