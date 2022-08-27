//
// Created by liran on 25/08/2022.
//

#include "SocketIO.h"
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

std::string SocketIO::read() {
    string message;
    char buffer;
    // receives and checks that the connection is still fine and the info received successfully.
    long read_bytes = recv(clientSock, &buffer, sizeof(char), 0);
    if (read_bytes == 0) {
        cerr << "==> Closed connection with the client! " << endl;
    } else if (read_bytes < 0) {
        cerr << "Error reading in SERVER" << endl;
        exit(1);
    } else {
        while (buffer != '\n') {
            message.push_back(buffer);
            read_bytes = recv(clientSock, &buffer, sizeof(char), 0);
            if (read_bytes == 0) {
                cout << "==> Closed connection with the client! " << endl;
            } else if (read_bytes < 0) {
                cerr << "Error reading in SERVER" << endl;
                exit(1);
            } else {
                continue;
            }
        }
    }

    // Returns the received message.
    return message;
}

void SocketIO::write(std::string message) {
    // Sends and checks that it sent successfully.
    long sent_bytes = send(clientSock, message.c_str(), message.length(), 0);
    if (sent_bytes < 0) {
        cerr << "Error sending to client in SERVER" << endl;
        exit(1);
    }
}
