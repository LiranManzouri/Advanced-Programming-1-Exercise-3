//
// Created by liran on 25/08/2022.
//

#include "SocketIO.h"
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <mutex>

using namespace std;

std::string SocketIO::read() {
    // string message;
    const int data_len = 8192;
    char buffer[8192] = {0};
    // receives and checks that the connection is still fine and the info received successfully.
    long read_bytes = recv(clientSock, &buffer, data_len, 0);
    /*if (read_bytes == 0) {
        cout << "Closed connection in SERVER" << endl;
    } else */if (read_bytes < 0) {
        cerr << "Error reading in SERVER" << endl;
        exit(1);
    }/* else {
        while (buffer != '\0') {
            cout << "buf = " << buffer;
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
    */

    // Returns the received message.
    return buffer;
}

void SocketIO::write(std::string message) {
    // Sends and checks that it sent successfully.
    long sent_bytes = send(clientSock, message.c_str(), message.length(), 0);
    if (sent_bytes < 0) {
        cerr << "Error sending to client in SERVER" << endl;
        exit(1);
    }
}
