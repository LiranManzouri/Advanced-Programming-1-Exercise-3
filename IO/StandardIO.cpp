//
// Created by liran on 25/08/2022.
//

#include <iostream>

#include "StandardIO.h"

using namespace std;

void StandardIO::write(std::string message) {
    cout << message;
}

std::string StandardIO::read() {
//    cin.ignore();
    string input;
    getline(cin, input);
    return input;
}
