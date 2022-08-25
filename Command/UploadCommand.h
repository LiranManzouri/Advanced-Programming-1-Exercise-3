//
// Created by liran on 24/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H

#include "Command.h"

class UploadCommand : public Command {
public:
    UploadCommand() : Command("upload un unclassified csv data file"){}
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_UPLOADCOMMAND_H
