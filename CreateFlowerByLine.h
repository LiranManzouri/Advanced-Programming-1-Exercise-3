//
// Created by liran on 23/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATEFLOWERBYLINE_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATEFLOWERBYLINE_H


#include "Flower.h"

#include <string>
#include <utility>

// Gets a line and returns the flower 'hiding' in it.
class CreateFlowerByLine {
    std::string line;
public:
    // Constructor.
    explicit CreateFlowerByLine(std::string line) : line(std::move(line)) {}

    // Returns the flower.
    Flower getFlower();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATEFLOWERBYLINE_H
