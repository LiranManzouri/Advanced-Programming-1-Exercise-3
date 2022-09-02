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

// The threads run this function.
void clientHandler(int client_sock) {
    SocketIO socketIo(client_sock);
    CLI cli(&socketIo);
    cli.start();
    close(client_sock);
}

void alarmHandler(int signum) {
}


// Main for the server, to communicate with the clients.
int main(int argc, char const *argv[]) {
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

    // Saves the threads.
    vector<thread> clientThreads;

    // Waits for a client.
    if (listen(sock, 3) < 0) {
        cout << "Error listening to a socket in SERVER" << endl;
        exit(1);
    }

    // Runs until timeout.
    while (true) {

        // Timeout handler.
        struct sigaction sa{};
        sa.sa_handler = alarmHandler;
        sigemptyset(&sa.sa_mask);
        if (sigaction(SIGALRM, &sa, nullptr) == -1) {
            break;
        }

        // Accepts the client and checks it went successfully.
        struct sockaddr_in client_sin{};
        unsigned int addr_len = sizeof(client_sin);
        // Waits 90 seconds until timeout.
        alarm(90);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        alarm(0);
        // Error.
        if (client_sock < 0) {
            // If the error was because of timeout.
            if (errno == EINTR) {
                close(sock);
                break;
            } else {
                return 0;
            }
        }

        // New thread for the client.
        thread newClientThread(clientHandler, client_sock);
        clientThreads.push_back(move(newClientThread));
    }
    // Joins the threads after a timeout.
    for (auto &t: clientThreads) {
        t.join();
    }
}
