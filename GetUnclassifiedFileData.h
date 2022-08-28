//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_GETUNCLASSIFIEDFILEDATA_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_GETUNCLASSIFIEDFILEDATA_H


#include <string>
#include "IO/DefaultIO.h"

class GetUnclassifiedFileData {
    std::string unclassifiedPath;
public:
    explicit GetUnclassifiedFileData(std::string unclassifiedPath) : unclassifiedPath(std::move(unclassifiedPath)) {}

    std::string getData();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_GETUNCLASSIFIEDFILEDATA_H
