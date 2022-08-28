//#include "Server.h"
#include "ServerFront.h"
#include "../CLI.h"
#include "../CreateClassifiedFiles.h"
#include <iostream>
#include <cstring>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <csignal>

using namespace std;

void clientHandler(int client_sock) {
    SocketIO socketIo(client_sock);
    CLI cli(&socketIo);
    cli.start();
    close(client_sock);
}

void alarmHandler(int signum) {
}

/*
 * Main for the server, to communicate with the clients.
 * The server gets a path to unclassified flowers from a client and
 * classify them, after that, the server sends it back to the client.
 */
int main(int argc, char const *argv[]) {
    // Responsible for the communication.
//    ServerFront front;

    // Port to use.
    const int server_port = 5555;
    // Creates the socket and checks it created successfully.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in SERVER" << endl;
        exit(1);
    }
    // Initializes the info about the socket.
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    // Binding the socket and checks it bind successfully.
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error binding socket in SERVER" << endl;
        exit(1);
    }

    vector<thread> clientThreads;

    // Waits for a client.
    if (listen(sock, 3) < 0) {
        cout << "Error listening to a socket in SERVER" << endl;
        exit(1);
    }
    int i = 0;

    // Runs until it being said to stop.
    while (true) {
        struct sigaction sa{};
        sa.sa_handler = alarmHandler;
        sigemptyset(&sa.sa_mask);
        if (sigaction(SIGALRM, &sa, nullptr) == -1) {
            break;
        }
        // Accepts the client and checks it went successfully.
        struct sockaddr_in client_sin{};
        unsigned int addr_len = sizeof(client_sin);
        alarm(90);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        alarm(0);
        if (client_sock < 0) {
            if (errno == EINTR) {
            cout << "Timout!" << endl;
            close(sock);
            break;
        } else {
            cout << "bruh" << endl;
            return 0;
        }
        }
//        if (client_sock < 0) {
//            cout << "Error accepting client in SERVER" << endl;
//            // exit(1);
//            break;
//        }
        thread newClientThread(clientHandler, client_sock);
        clientThreads.push_back(move(newClientThread));
        i++;
        // newClientThread.join();
        // alarm(0);
    }
    for (auto &t: clientThreads) {
        t.join();
    }
}
