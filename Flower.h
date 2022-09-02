//
// Created by liran on 19/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_FLOWER_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_FLOWER_H


#include <string>
#include <utility>
#include <vector>

class Flower {
    std::string m_flowerType;
    std::vector<double> m_flowerAttributes;
public:

    // constructor for the flower class
    Flower(std::string flowerType, std::vector<double> flowerAttributes)
            : m_flowerAttributes(std::move(flowerAttributes)), m_flowerType(move(flowerType)) {}

    Flower() = default;

    Flower(const Flower &flower) = default;

    ~Flower() = default;

    //getters
    std::string getFlowerType() const;

    double getAttribute(unsigned long i) const;

    unsigned long numOfAttributes() const;

    Flower &operator=(const Flower &flower) {
        if (this == &flower) {
            return *this;
        }
        m_flowerType = flower.m_flowerType;
        m_flowerAttributes = flower.m_flowerAttributes;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Flower &flower);

#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_FLOWER_H
