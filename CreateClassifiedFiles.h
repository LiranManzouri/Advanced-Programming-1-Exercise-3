//
// Created by liran on 30/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATECLASSIFIEDFILES_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATECLASSIFIEDFILES_H

#include <string>
#include <utility>
#include <vector>

class CreateClassifiedFiles {
    // Classifies by the values below.
    const int m_k;
    const std::string m_distanceMetric;
    const std::string m_flowersInfoToClassify;
    const std::string m_classifiedFlowers;
    const std::vector<std::string> *m_types;

public:
    // Constructor.
    CreateClassifiedFiles(int k, std::string distanceMetric, std::string flowersInfoToClassify,
                          std::string classifiedFlowers, std::vector<std::string> *types)
            : m_k(k), m_distanceMetric(std::move(distanceMetric)),
              m_flowersInfoToClassify(std::move(flowersInfoToClassify)),
              m_classifiedFlowers(std::move(classifiedFlowers)) {
        m_types = types;
    }

    // creates the output files for the classifier to write in
    // and write the classified info to the files
    std::vector<std::string> createClassified() const;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CREATECLASSIFIEDFILES_H
