//
// Created by liran on 02/09/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_STRINGTO_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_STRINGTO_H


#include <string>

// Class to check if a string can be converted to positive integer or to double.
class StringTo {
public:
    static bool Int(const std::string &str);

    static bool Double(const std::string &str);
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_STRINGTO_H
