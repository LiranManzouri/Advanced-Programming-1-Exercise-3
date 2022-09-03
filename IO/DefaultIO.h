//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_DEFAULTIO_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_DEFAULTIO_H


#include <string>

// Abstract class which capable of writing and reading.
class DefaultIO {
public:
    virtual void write(std::string message) = 0;

    virtual std::string read() = 0;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_DEFAULTIO_H
