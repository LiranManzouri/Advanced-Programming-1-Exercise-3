//
// Created by liran on 23/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATEFLOWERBYLINE_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATEFLOWERBYLINE_H


#include <string>
#include <utility>
#include "Flower.h"

class CreateFlowerByLine {

    std::string line;

public:

    explicit CreateFlowerByLine(std::string line) : line(std::move(line)) {}
    Flower getFlower();

};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATEFLOWERBYLINE_H
