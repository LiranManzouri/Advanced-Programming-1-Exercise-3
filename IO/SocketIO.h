//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_SOCKETIO_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_SOCKETIO_H


#include "DefaultIO.h"

class SocketIO : public DefaultIO {
    const int clientSock;
public:
    explicit SocketIO(int clientSock) : clientSock(clientSock) {}

    std::string read() override;

    void write(std::string message) override;

    // func1: sendFromClientToServer(...);
    // func2: receiveInClientFromServer(...);
    // func3: sendFromServerToClient(...);
    // func4: receiveInServerFromClient(...);

};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_SOCKETIO_H
