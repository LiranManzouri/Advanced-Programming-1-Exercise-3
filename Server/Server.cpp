// #include "Server.h"
#include "ServerFront.h"
#include <iostream>
#include <cstring>
#include "../CreateClassifiedFiles.h"
#include <thread>

using namespace std;

//all client functionality here
void handleClient(int client_sock){
    char message[4096] = {0};
    cout << "new thread" << endl;
}

// bool checkIfClosedAndHandleIt(char message[4096], ServerFront &front, int &i) {
//     if (strcmp(message, "closed") == 0) {
//         // Closes the server as well, or waiting for another client.
//         string option;
//         cout << "Please choose an option:\n\t==> 1. Wait for another client.\n\t==> 2. Close the server."
//              << endl;
//         do {
//             // Gets the decision.
//             cin >> option;
//             // Waits for new client.
//             if (option == "1") {
//                 cout << "==> Waiting for client..." << endl;
//                 // Closes the client socket.
//                 front.closeClientSock();
//                 // Gets new client.
//                 front.getNewClient(i);
//                 // Just added a new client.
//                 i++;
//                 // Closes the client socket.
//             } else if (option != "2") {
//                 cout << "==> Wrong key! Please choose 1 or 2 according to your wish!" << endl;
//             }
//             // Gets the decision until it's valid.
//         } while (option != "1" && option != "2");
//         // Leaves the communication.
//         if (option == "2") {
//             return true;
//         }
//         // option == 1.
//     }
//     // Continue communicating.
//     return false;
// }

/*
 * Main for the server, to communicate with the clients.
 * The server gets a path to unclassified flowers from a client and
 * classify them, after that, the server sends it back to the client.
 */
int main(int argc, char const *argv[]) {
    // Responsible for the communication.
    ServerFront front;


    //for some resone if the first client is connected inside the loop the server
    //has an error binding its own socket when it starts?? very wierd
    int firstClient = front.getNewClient();
    thread firstClientThread(handleClient, firstClient);

    vector<thread> openThreads;

    // openThreads.emplace_back([&](){handleClient(firstClient);});

    while(true){ //later add a stop in it
        int client_sock = front.getNewClient();;
        // thread clientThread(handleClient, client_sock);
        openThreads.emplace_back([&](){handleClient(client_sock);});
    }
    for (auto& t: openThreads){
        t.join();
    }
    firstClientThread.join();

    // int i = 2;
    // // Runs until it being said to stop.
    // while (true) {
    //     // Gets the path to the unclassified flowers.
    //     strcpy(message, front.receiveMessage());
    //     // If the message is closed, it means the client closed the socket.
    //     bool isClosed = checkIfClosedAndHandleIt(message, front, i);
    //     if (isClosed) {
    //         break;
    //     } else if (strcmp(message, "closed") == 0) {
    //         continue;
    //     }
    //     // Classify the unclassified flowers in the given path.
    //     CreateClassifiedFiles createClassifiedFiles(7, message);
    //     vector<string> flowerTypes = createClassifiedFiles.createClassified();
    //     char flowerTypesAsChar[4096] = {0};
    //     int l = 0;
    //     // Writes the classifiers types to the char array, seperated by '\n'.
    //     for (auto & flowerType : flowerTypes) {
    //         for (char k: flowerType) {
    //             flowerTypesAsChar[l] = k;
    //             l++;
    //         }
    //         flowerTypesAsChar[l] = '\n';
    //         l++;
    //     }
    //     flowerTypesAsChar[l] = '\0';
    //     // Sends the classified to the client.
    //     cout << "==> Classified! Sending back to you..." << endl;
    //     front.sendMessage(flowerTypesAsChar);
    // }
}