//#include "ClientFront.h"
//#include "../ReadFlowers.h"
//#include "../ClassifyFlower.h"
//#include <iostream>
//#include <cstring>
//#include <fstream>
//#include "../GetUnclassifiedFileData.h"
//#include "../CLI.h"
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <thread>
//
//using namespace std;
//
//void read(int sock, char *buffer, int data_len) {
//    // Cleans the buffer.
//    for (int i = 0; i < data_len; i++) {
//        buffer[i] = '\0';
//    }
//
//    // receives and checks that the connection is still fine and the info received successfully.
//    long read_bytes = recv(sock, buffer, data_len, 0);
//    if (read_bytes == 0) {
//        cout << "Closed connection in CLIENT" << endl;
//    } else if (read_bytes < 0) {
//        cout << "Error reading in CLIENT" << endl;
//        exit(1);
//    }
//}
//
//void write(int sock, char *message) {
//    // Sends and checks that it sent successfully.
//    unsigned long my_data_len = strlen(message);
//    long sent_bytes = send(sock, message, my_data_len, 0);
//    if (sent_bytes < 0) {
//        cout << "Error sending to server in CLIENT" << endl;
//        exit(1);
//    }
//}
//
///*
// * Main for the client, to communicate with the server.
// * The client sends a path to unclassified flowers to the server and get their classify,
// * after that, the client writes the classifiers to the output file.
// */
//int main(int argc, char const *argv[]) {
//    const int port_no = 5555;
//    // Creates the socket and checks it created successfully.
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (sock < 0) {
//        cout << "Error creating socket in CLIENT" << endl;
//        exit(1);
//    }
//    // Initializes the info about the socket.
//    struct sockaddr_in sin{};
//    memset(&sin, 0, sizeof(sin));
//    sin.sin_family = AF_INET;
//    sin.sin_addr.s_addr = INADDR_ANY;
//    sin.sin_port = htons(port_no);
//    // Connecting the socket to the server.
//    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
//        cout << "Error connecting to server in CLIENT" << endl;
//        exit(1);
//    }
//
//    const int data_len = 4096;
//    char buffer[4096] = {0};
//
//    thread readThread(read, sock, buffer, data_len);
//    thread writeThread(write, sock, buffer);
//
//    while (strcmp(buffer, "close") != 0) {
//
//        readThread.join();
//        writeThread.join();
//
//    }
//
//
//}