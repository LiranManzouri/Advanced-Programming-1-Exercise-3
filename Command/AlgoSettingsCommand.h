//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_ALGOSETTINGSCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_ALGOSETTINGSCOMMAND_H


#include "Command.h"

class AlgoSettingsCommand : public Command {

public:
    AlgoSettingsCommand() : Command("algorithm settings") {}
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_ALGOSETTINGSCOMMAND_H
