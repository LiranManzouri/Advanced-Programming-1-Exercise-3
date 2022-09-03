//
// Created by liran on 24/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H


#include "../IO/DefaultIO.h"

#include <string>
#include <utility>
#include <vector>

class Command {
protected:
    // DefaultIO for reading and writing.
    DefaultIO *dio;
    const std::string description;
    int *k;
    char *classifiedTrainData;
    char *unclassifiedTestData;
    std::string *distanceMetric;
    std::vector<std::string> *types;
    std::vector<std::string> *flowerTypes;
public:
    // Executes command.
    virtual void execute() = 0;

    // Getter for the description.
    std::string getDescription() const {
        return description;
    }

    // Constructor.
    Command(std::string description, int *k, char classifiedTrainData[16384], char unclassifiedTestData[16384],
            std::string *distanceMetric, std::vector<std::string> *flowerTypes, std::vector<std::string> *types,
            DefaultIO *dio)
            : description(std::move(description)), k(k), distanceMetric(distanceMetric), dio(dio) {
        this->classifiedTrainData = classifiedTrainData;
        this->unclassifiedTestData = unclassifiedTestData;
        this->flowerTypes = flowerTypes;
        this->types = types;
    }

    // Destructor.
    virtual ~Command() = default;

};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H
