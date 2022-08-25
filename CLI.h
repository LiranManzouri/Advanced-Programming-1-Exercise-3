//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H


#include <Command/Command.h>
#include <Command/UploadCommand.h>
#include <Command/AlgoSettingsCommand.h>

class CLI {
    Command *commands[2] = {new UploadCommand(), new AlgoSettingsCommand()};
    void printMenu();

public:
    void start();
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLI_H
