//
// Created by liran on 25/08/2022.
//

#include "StandardIO.h"

#include <iostream>

using namespace std;

void StandardIO::write(std::string message) {
    cout << message;
}

std::string StandardIO::read() {
    string input;
    getline(cin, input);
    return input;
}
