//
// Created by liran on 01/09/2022.
//

#include "ExitCommand.h"

void ExitCommand::execute() {
    dio->write("[Exit]");
}
