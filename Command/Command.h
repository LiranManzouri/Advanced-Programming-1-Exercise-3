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
    DefaultIO *dio;
    const std::string description;
    int *k;
    char *classifiedTrainData;
    char *unclassifiedTestData;
    std::string *distanceMetric/* = new std::string("EUC")*/;
    std::vector<std::string> *flowerTypes;
public:
    virtual void execute() = 0;

    std::string getDescription() const {
        return description;
    }

    Command(std::string description, int *k, char classifiedTrainData[8192], char unclassifiedTestData[8192],
            std::string *distanceMetric, std::vector<std::string> *flowerTypes, DefaultIO *dio)
            : description(std::move(description)), k(k), distanceMetric(distanceMetric), dio(dio) {
        this->classifiedTrainData = classifiedTrainData;
        this->unclassifiedTestData = unclassifiedTestData;
        this->flowerTypes = flowerTypes;
    }

    virtual ~Command() = default;

};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H
