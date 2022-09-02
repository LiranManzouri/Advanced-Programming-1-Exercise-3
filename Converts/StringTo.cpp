//
// Created by liran on 02/09/2022.
//

#include "StringTo.h"

using namespace std;

bool StringTo::Int(const string &str) {
    bool isANumber = true;
    for (auto &ch: str) {
        if (!isdigit(ch)) {
            isANumber = false;
            break;
        }
    }
    return isANumber;
}

bool StringTo::Double(const string &str) {
    char *end;
    strtod(str.c_str(), &end);
    if (end == str.c_str() || *end != '\0') {
        return false;
    }
    return true;
}
