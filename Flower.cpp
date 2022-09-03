//
// Created by liran on 19/07/2022.
//

#include "Flower.h"
#include "iostream"

using namespace std;

// Getter to the flower type.
string Flower::getFlowerType() const {
    return m_flowerType;
}

// Get the num of attributes.
unsigned long Flower::numOfAttributes() const {
    return m_flowerAttributes.size();
}

// Getter to an attribute.
double Flower::getAttribute(unsigned long i) const {
    return m_flowerAttributes.at(i);
}

// Adding attributes.
void Flower::addAttribute(double i) {
    m_flowerAttributes.push_back(i);
}