//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATECLASSIFIEDFILES_H

#include <string>
#include <utility>
#include <vector>

class CreateClassifiedFiles {

    const int m_k;
    const std::string m_distanceMetric;
    const std::string m_flowersInfoToClassify;
    const std::string m_classifiedFlowers;

public:

    CreateClassifiedFiles(int k, std::string distanceMetric, std::string flowersInfoToClassify,
                          std::string classifiedFlowers)
            : m_k(k), m_distanceMetric(std::move(distanceMetric)), m_flowersInfoToClassify(std::move(flowersInfoToClassify)),
              m_classifiedFlowers(std::move(classifiedFlowers)) {}

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    std::vector<std::string> createClassified() const;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATECLASSIFIEDFILES_H
