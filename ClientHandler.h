//
// Created by liran on 27/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CLIENTHANDLER_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handle(int clientSocket) = 0;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLIENTHANDLER_H
