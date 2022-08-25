//
// Created by liran on 25/08/2022.
//

#include "SocketIO.h"
#include <iostream>
#include <netinet/in.h>

using namespace std;

std::string SocketIO::read() {
    return {};
}

void SocketIO::write(std::string message) {
    // Sends and checks that it sent successfully.
    long sent_bytes = send(4, message.c_str(), message.length(), 0);
    if (sent_bytes < 0) {
        cout << "Error sending to client in SERVER" << endl;
        exit(1);
    }
}
