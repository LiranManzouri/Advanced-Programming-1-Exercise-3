#include "../ClassifyFlower.h"
#include "../GetUnclassifiedFileData.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

// Read the message from the server.
string read(int sock) {
    const int data_len = 16384;
    char buffer[16384] = {0};
    // receives and checks that the connection is still fine and the info received successfully.
    long read_bytes = recv(sock, buffer, data_len, 0);
    if (read_bytes == 0) {
        cout << "Closed connection in CLIENT" << endl;
    } else if (read_bytes < 0) {
        cout << "Error reading in CLIENT" << endl;
        exit(1);
    }
    return buffer;
}

// Write a message to the server.
void write(int sock, const string &message) {
    // Sends and checks that it sent successfully.
    long sent_bytes = send(sock, message.c_str(), message.length(), 0);
    if (sent_bytes < 0) {
        cout << "Error sending to server in CLIENT" << endl;
        exit(1);
    }
}

/*
 * Main for the client, to communicate with the server.
 */
int main(int argc, char const *argv[]) {
    const int port_no = 5555;
    // Creates the socket and checks it created successfully.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in CLIENT" << endl;
        exit(1);
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port_no);
    // Connecting the socket to the server.
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error connecting to server!" << endl;
        exit(1);
    }
    // Non-stop communication, until the client select the exit command.
    while (true) {
        // Read the message from the server.
        string messageFromServer = read(sock);
        // Exit command - breaks.
        if (messageFromServer == "[Exit]") {
            break;
        }
        string messageToServer;
        // Reading a file - command 1.
        if (messageFromServer.rfind("[File]:", 0) == 0) {
            // Prints the message from the server.
            cout << messageFromServer.erase(0, 7);
            // Gets the path.
            string path;
            getline(cin, path);
            // Gets the data from the file in the given path.
            GetUnclassifiedFileData getFileData(path);
            messageToServer = getFileData.getData();
            // Sends the data to the server.
            write(sock, messageToServer);
            // If the server only wants to send something to print in the client side without getting something back.
        } else if (messageFromServer.rfind("[Print]:", 0) == 0) {
            cout << messageFromServer.erase(0, 8);
            write(sock, "Done");
            // Creates new file to save the results - command 5.
        } else if (messageFromServer.rfind("[Create File]:", 0) == 0) {
            // Gets the local path.
            cout << messageFromServer.erase(0, 14);
            string path;
            getline(cin, path);
            if (path[0] == '\"') {
                path.erase(0, 1);
            }
            if (path[path.length() - 1] == '\"') {
                path.pop_back();
            }
            path.append("/results.txt");
            ofstream outputFile;
            outputFile.open(path);
            // Gets a path until it's a valid path.
            while (!outputFile.is_open()) {
                cout << "Wrong path! Try again:" << endl;
                getline(cin, path);
                if (path[0] == '\"') {
                    path.erase(0, 1);
                }
                if (path[path.length() - 1] == '\"') {
                    path.pop_back();
                }
            }
            write(sock, "Done");
            // Prints the results in the file.
            messageFromServer = read(sock);
            outputFile << messageFromServer;
            write(sock, "Done");
            // Prints and waits for input without something specific to do.
        } else {
            if (!(messageFromServer == "[Waiting for enter]")) {
                cout << messageFromServer;
            }
            getline(cin, messageToServer);
            if (messageToServer.empty()) {
                messageToServer = "[Enter]";
            }
            write(sock, messageToServer);
        }
    }
}