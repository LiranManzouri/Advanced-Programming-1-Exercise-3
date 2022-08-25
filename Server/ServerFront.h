//
// Created by liran on 13/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_2_SERVERFRONT_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_2_SERVERFRONT_H

/**
 * Class that is in control of communicating between the clients
 * and the server, and represents the server in this communication.
 */
class ServerFront {
private:
    // Socket and client socket for communicating, data length
    // for the messages and buffer to save the received message.
    const int data_len = 4096;
    char buffer[4096] = {0};
    int sock = 0;


public:

    // Creates the socket.
    void StartServer();

    // Closes the socket.
    void CloseServer();

    // Sends message to a client.
    void sendMessage(char (&message)[4096], int client_sock) const;

    // Gets new client and returns the socket
    int getNewClient();

    // Receives message from the client.
    char *receiveMessage(int client_sock);
};

#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_SERVERFRONT_H