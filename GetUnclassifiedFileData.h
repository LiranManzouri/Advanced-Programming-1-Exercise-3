//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_GETUNCLASSIFIEDFILEDATA_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_GETUNCLASSIFIEDFILEDATA_H


#include <string>

// Gets file data by the file path and returns it.
class GetUnclassifiedFileData {
    // The file path.
    std::string unclassifiedPath;
public:
    // Constructor.
    explicit GetUnclassifiedFileData(std::string unclassifiedPath) : unclassifiedPath(std::move(unclassifiedPath)) {}

    // Returns the data that stored in the file path.
    std::string getData();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_GETUNCLASSIFIEDFILEDATA_H
