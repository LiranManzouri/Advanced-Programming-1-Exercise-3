//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H

#include <string>
#include <vector>

class CreateClassifiedFiles {

    const int k;
    const std::string flowersInfo;

public:

    CreateClassifiedFiles(int k, std::string flowersInfo) : k(k), flowersInfo(std::move(flowersInfo)) {}

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    std::vector<std::string> createClassified() const;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H
