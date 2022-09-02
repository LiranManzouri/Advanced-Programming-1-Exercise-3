//
// Created by liran on 19/07/2022.
//

#include "Flower.h"
#include "iostream"

using namespace std;

string Flower::getFlowerType() const {
    return m_flowerType;
}

unsigned long Flower::numOfAttributes() const {
    return m_flowerAttributes.size();
}

double Flower::getAttribute(unsigned long i) const {
    return m_flowerAttributes.at(i);
}

ostream &operator<<(ostream &os, const Flower &flower) {
    if (flower.getFlowerType().empty()) {
        for (int i = 0; i < flower.numOfAttributes() - 1; i++) {
            os << flower.getAttribute(i) << " ";
        }
        os << flower.getAttribute(flower.numOfAttributes() - 1);
    } else {
        os << flower.getFlowerType();
        for (int i = 0; i < flower.numOfAttributes() - 1; i++) {
            os << "" << flower.getAttribute(i);
        }
    }
    return os;
}