//
// Created by liran on 24/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H


#include <string>
#include <utility>
#include <../Client/ClientFront.h>
#include <ServerFront.h>

class Command {
protected:
    const std::string description;
    std::string unclassifiedPath;
    int k = 5;
    std::string distanceMetric = "EUC";
//    const ClientFront clientFront;
public:
    virtual void execute() = 0;

    std::string getDescription() const {
        return description;
    }

    explicit Command(std::string description) : description(std::move(description)) {}

};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_COMMAND_H
