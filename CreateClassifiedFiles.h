//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H

#include <string>
#include <utility>
#include <vector>

class CreateClassifiedFiles {

    const int k;
    const std::string flowersInfoToClassify;
    const std::string classifiedFlowers;

public:

    CreateClassifiedFiles(int k, std::string flowersInfoToClassify, std::string classifiedFlowers)
            : k(k), flowersInfoToClassify(std::move(flowersInfoToClassify)),
              classifiedFlowers(std::move(classifiedFlowers)) {}

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    std::vector<std::string> createClassified() const;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_CREATECLASSIFIEDFILES_H
