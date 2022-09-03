//
// Created by liran on 19/07/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_FLOWER_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_FLOWER_H


#include <string>
#include <utility>
#include <vector>

// Class to represent a flower.
class Flower {
    // Flower has type and attributes.
    std::string m_flowerType;
    std::vector<double> m_flowerAttributes;
public:
    // Constructor.
    Flower(std::string flowerType, std::vector<double> flowerAttributes)
            : m_flowerAttributes(std::move(flowerAttributes)), m_flowerType(move(flowerType)) {}

    // Default Constructor.
    Flower() = default;

    // Default copy constructor.
    Flower(const Flower &flower) = default;

    // Operator= implementation for flowers.
    Flower &operator=(const Flower &flower) {
        if (this == &flower) {
            return *this;
        }
        // Copies the type and the attributes.
        m_flowerType = flower.m_flowerType;
        m_flowerAttributes = flower.m_flowerAttributes;
        return *this;
    }

    // Default Destructor.
    ~Flower() = default;

    // Getters to the flower type and to an attribute.
    std::string getFlowerType() const;

    double getAttribute(unsigned long i) const;

    // Returns the num of attributes.
    unsigned long numOfAttributes() const;
};

#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_FLOWER_H
