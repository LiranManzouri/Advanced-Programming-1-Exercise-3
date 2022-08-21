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
    int client_sock = 0;
    const int data_len = 4096;
    char buffer[4096] = {0};
    int sock = 0;

    // Creates the socket and connecting the client to the server.
    void StartServer();

public:

    // Constructor.
    ServerFront() {
        StartServer();
    }

    // Destructor.
    ~ServerFront();

    // Sends message to a client.
    void sendMessage(char (&message)[4096]) const;

    // Gets new client.
    void getNewClient(int i);

    // Closes the client socket and stops the communication between the current client to the server.
    void closeClientSock() const;

    // Receives message from the client.
    char *receiveMessage();
};

#endif //ADVANCED_PROGRAMMING_1___EXERCISE_2_SERVERFRONT_H