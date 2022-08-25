////#include "Server.h"
//#include "ServerFront.h"
//#include "CLI.h"
//#include "../CreateClassifiedFiles.h"
//#include <iostream>
//#include <cstring>
//#include <thread>
//
//using namespace std;
//
//void func() {
//    cout << "ok" << endl;
//}
//
///*
// * Main for the server, to communicate with the clients.
// * The server gets a path to unclassified flowers from a client and
// * classify them, after that, the server sends it back to the client.
// */
//int main(int argc, char const *argv[]) {
//    // Responsible for the communication.
//    ServerFront front;
//    // Saves the message.
//    char message[4096] = {0};
//    int i = 2;
//    // Runs until it being said to stop.
//    bool listening = true;
//    while(listening) {
//        CLI cli;
//        thread t1(cli.start());
//    }
//
//    // Gets the path to the unclassified flowers.
//    strcpy(message, front.receiveMessage());
//    // Classify the unclassified flowers in the given path.
//    CreateClassifiedFiles createClassifiedFiles(7, message);
//    vector<string> flowerTypes = createClassifiedFiles.createClassified();
//    char flowerTypesAsChar[4096] = {0};
//    int l = 0;
//    // Writes the classifiers types to the char array, seperated by '\n'.
//    for (auto &flowerType: flowerTypes) {
//        for (char k: flowerType) {
//            flowerTypesAsChar[l] = k;
//            l++;
//        }
//        flowerTypesAsChar[l] = '\n';
//        l++;
//    }
//    flowerTypesAsChar[l] = '\0';
//    // Sends the classified to the client.
//    cout << "==> Classified! Sending back to you..." << endl;
//    front.sendMessage(flowerTypesAsChar);
//}
