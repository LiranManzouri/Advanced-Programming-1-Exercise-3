//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_STANDARDIO_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_STANDARDIO_H


#include "DefaultIO.h"

// Reading and writing using cout and cin.
class StandardIO : public DefaultIO {

public:
    // Reading method.
    std::string read() override;

    // Writing method.
    void write(std::string message) override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_STANDARDIO_H
