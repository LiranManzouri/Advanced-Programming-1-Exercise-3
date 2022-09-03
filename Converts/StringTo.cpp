//
// Created by liran on 02/09/2022.
//

#include "StringTo.h"

using namespace std;

// Checks if a string can be converted to a positive integer number.
bool StringTo::Int(const string &str) {
    bool isANumber = true;
    // Checks if each number is a digit.
    for (auto &ch: str) {
        // One char isn't a digit means the whole string is not a positive integer number.
        if (!isdigit(ch)) {
            isANumber = false;
            break;
        }
    }
    return isANumber;
}

// Checks if a string can be converted to a double integer (decimal number).
bool StringTo::Double(const string &str) {
    char *end;
    strtod(str.c_str(), &end);
    if (end == str.c_str() || *end != '\0') {
        return false;
    }
    return true;
}
