#include "ClientFront.h"
#include "../ReadFlowers.h"
#include "../ClassifyFlower.h"
#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

/*
 * Main for the client, to communicate with the server.
 * The client sends a path to unclassified flowers to the server and get their classify,
 * after that, the client writes the classifiers to the output file.
 */
int main(int argc, char const *argv[]) {
    // Responsible for the communication.
    ClientFront front;
    // Saves the message.
    char message[4096] = "\0";
    strcpy(message, "test");
    front.sendMessage(message);
    cout << front.receiveMessage() << endl;

    // // Stops the communication after getting the close message.
    // while (strcmp(message, "close") != 0) {
    //     // Asks for the paths.
    //     cout << "==> Enter the unclassified path and the desired output path:" << endl;
    //     cout << "    NOTE: for closing the client socket and stop the communication" << endl
    //          << "    send here \"close\"." << endl;
    //     cin.getline(message, 4096);
    //     // Stops after "close".
    //     if (strcmp(message, "close") == 0) {
    //         break;
    //     }
    //     // Saves the paths.
    //     char unclassifiedPath[4096] = {0};
    //     char outputClassifiedPath[4096] = {0};

    //     // Gets the paths.
    //     int i = 0, k = 0;
    //     while (message[i] != ' ' && message[i] != '\0') {
    //         unclassifiedPath[k] = message[i];
    //         i++, k++;
    //     }
    //     unclassifiedPath[k] = '\0';
    //     i++;
    //     k = 0;
    //     while (message[i] != '\0') {
    //         outputClassifiedPath[k] = message[i];
    //         i++, k++;
    //     }
    //     outputClassifiedPath[k] = '\0';

    //     strcpy(message, "\0");

    //     ReadFlowers unclassifiedReader = ReadFlowers(unclassifiedPath);
    //     unclassifiedReader.readAndSaveFlowers();
    //     int numOfUnclassifiedFlowers = unclassifiedReader.getNumOfFlowers();
    //     if (numOfUnclassifiedFlowers == -1) {
    //         cerr << "Error: file couldn't be opened, Rewrite the file path!" << endl;
    //         continue;
    //     }

    //     vector<string> flowerTypesByOrder;
    //     flowerTypesByOrder.reserve(numOfUnclassifiedFlowers);
    //     Flower *unclassifiedFlowers = unclassifiedReader.getFlowers();
    //     //writes the classified info to the array.
    //     for (int j = 0; j < numOfUnclassifiedFlowers; j++) {
    //         const Flower unclassifiedFlower = unclassifiedFlowers[j];
    //         flowerTypesByOrder.push_back(to_string(unclassifiedFlower.getCalyxLeavesLength()) + ","
    //                                      + to_string(unclassifiedFlower.getCalyxLeavesWidth()) + ","
    //                                      + to_string(unclassifiedFlower.getPetalLength()) + ","
    //                                      + to_string(unclassifiedFlower.getPetalWidth()) + "\n");
    //         const char *send = flowerTypesByOrder.at(j).c_str();
    //         strcat(message, send);
    //     }
    //     // Send the unclassified path to the server.
    //     front.sendMessage(message);

    //     // Gets the types of the flowers after the server classified them.
    //     char messageReceived[4096] = {0};
    //     strcpy(messageReceived, front.receiveMessage());

    //     if (strcmp(messageReceived, "Rewrite the file path!") == 0) {
    //         cout << messageReceived << endl;
    //         continue;
    //     }

    //     // Opens the output file.
    //     ofstream outputClassified;
    //     outputClassified.open(outputClassifiedPath);
    //     if (!outputClassified.is_open()) {
    //         cerr << "Error: file couldn't be opened!" << endl;
    //         exit(1);
    //     }

    //     // Writes the classifiers to the output file.
    //     outputClassified << messageReceived << endl;

    //     outputClassified.close();
    //     // Notifies that everything went successful.
    //     cout << "==> Output file created successfully!\n" << endl;
    // }
}