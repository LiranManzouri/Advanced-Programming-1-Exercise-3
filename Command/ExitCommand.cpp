//
// Created by liran on 01/09/2022.
//

#include "ExitCommand.h"

// Class for the seventh command which exits the program.
void ExitCommand::execute() {
    dio->write("[Exit]");
}
