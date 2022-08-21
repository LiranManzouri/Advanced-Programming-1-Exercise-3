//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H

#include <string>

class CreateClassifiedFiles {

    const int k;
    const std::string unclassifiedPath;

public:

    CreateClassifiedFiles(int k, std::string unclassifiedPath) :
            k(k), unclassifiedPath(std::move(unclassifiedPath)) {}

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    std::pair<std::string *, int> createClassified() const;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H
