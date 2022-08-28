// //
// // Created by liran on 25/08/2022.
// //

// #include "CLI.h"
// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <netinet/in.h>
// #include <cstring>

// using namespace std;
// //mutex m;

// //void startCommunicationWithClient(int serverSocket) {
// //    CLI cli(serverSocket);
// //    cli.start();
// //}

// int createServerSocket() {
//     // Prints "SERVER" with bold and underline, in the middle of the terminal.
//     for (int i = 0; i < 37; i++) {
//         cout << " ";
//     }
//     cout << "\033[4m\e[1mSERVER\e[0m\033[0m" << endl;
//     cout << "==> Waiting for client..." << endl;
//     // Port to use.
//     const int server_port = 5555;
//     // Creates the socket and checks it created successfully.
//     int sock = socket(AF_INET, SOCK_STREAM, 0);
//     if (sock < 0) {
//         cout << "Error creating socket in SERVER" << endl;
//         exit(1);
//     }
//     // Initializes the info about the socket.
//     struct sockaddr_in sin{};
//     memset(&sin, 0, sizeof(sin));
//     sin.sin_family = AF_INET;
//     sin.sin_addr.s_addr = INADDR_ANY;
//     sin.sin_port = htons(server_port);

//     // Binding the socket and checks it bind successfully.
//     if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
//         cout << "Error binding socket in SERVER" << endl;
//         exit(1);
//     }
//     return sock;
// }

// int main(int argc, char const *argv[]) {
// //     CLI cli;
// //      Responsible for the communication.
// //     int serverSocket = createServerSocket();
// //     thread threads[6];
// //     threads[0] = thread(startCommunicationWithClient, serverSocket);
// //     int i = 2;
// //     // Runs until it being said to stop.
// //     bool listening = true;
// //     while (i <= 6) {
// //         threads[i - 1] = thread(startCommunicationWithClient, serverSocket);
// //         i++;
// //     }
// //     for (auto &thread: threads) {
// //         thread.join();
// //     }
// // //    cli.start();

//     CLI cli;
//     cli.start();
//     return 0;
// }