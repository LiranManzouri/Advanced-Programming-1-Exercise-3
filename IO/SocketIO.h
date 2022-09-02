//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_SOCKETIO_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_SOCKETIO_H


#include "DefaultIO.h"

// Reading and writing using sockets.
class SocketIO : public DefaultIO {
    // The client sock which the socketIO will send to and read from.
    const int clientSock;
public:
    // Constructor.
    explicit SocketIO(int clientSock) : clientSock(clientSock) {}

    // Reading method.
    std::string read() override;

    // Writing method.
    void write(std::string message) override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_SOCKETIO_H
