//
// Created by liran on 24/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H


#include "IO/DefaultIO.h"
#include <string>
#include <utility>
#include <vector>

class Command {
protected:
//    DefaultIO dio;
    const std::string description;
//    std::string unclassifiedPath;
    int *k;
    char *classifiedTrainData;
    char *unclassifiedTestData;
    std::string *distanceMetric = new std::string("EUC");
    std::vector<std::string> *flowerTypes;
    //    const ClientFront clientFront;
public:
    virtual void execute() = 0;

    std::string getDescription() const {
        return description;
    }

    Command(std::string description, int *k, char classifiedTrainData[4096], char unclassifiedTestData[4096],
            std::string *distanceMetric, std::vector<std::string> *flowerTypes)
         : description(std::move(description)), k(k), distanceMetric(distanceMetric) {
        this->classifiedTrainData = classifiedTrainData;
        this->unclassifiedTestData = unclassifiedTestData;
        this->flowerTypes = flowerTypes;
    }

};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H
