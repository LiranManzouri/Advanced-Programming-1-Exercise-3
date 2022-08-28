#include "ClientFront.h"
#include "../ReadFlowers.h"
#include "../ClassifyFlower.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include "../GetUnclassifiedFileData.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <mutex>

using namespace std;
// mutex m;

string read(int sock) {
    const int data_len = 4096;
    char buffer[4096] = {0};
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

void write(int sock, string message) {
    // cout << "message is = <" << message << ">" << endl;
    // getline(cin, message);
    // Sends and checks that it sent successfully.
    long sent_bytes = send(sock, message.c_str(), message.length(), 0);
    if (sent_bytes < 0) {
        cout << "Error sending to server in CLIENT" << endl;
        exit(1);
    }
}

/*
 * Main for the client, to communicate with the server.
 * The client sends a path to unclassified flowers to the server and get their classify,
 * after that, the client writes the classifiers to the output file.
 */
int main(int argc, char const *argv[]) {
    const int port_no = 5555;
    // Creates the socket and checks it created successfully.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in CLIENT" << endl;
        exit(1);
    }
    // Initializes the info about the socket.
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port_no);
    // Connecting the socket to the server.
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error connecting to server in CLIENT" << endl;
        exit(1);
    }
    while (true) {
        string messageFromServer = read(sock);
        if (messageFromServer == "close") {
            write(sock, "close");
            break;
        }
        string messageToServer;
        // cout << endl << endl << "message from server = {" << messageFromServer << "}" << endl << endl;
        // cout << "message: <" << messageFromServer << ">";
        if (messageFromServer.rfind("[File]:", 0) == 0) {
            cout << messageFromServer.erase(0, 7);
            string path;
            getline(cin, path);
            // cout << path << endl;
            GetUnclassifiedFileData getFileData(path);
            messageToServer = getFileData.getData();
            write(sock, messageToServer);
            // cout << messageToServer << endl;
        } else if (messageFromServer.rfind("[Print]:", 0) == 0) {
            cout << messageFromServer.erase(0, 8);
            write(sock, "Done");
            // cout << messageFromServer;
        } else if (messageFromServer.rfind("[Create File]:", 0) == 0) {
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
            //    cout << outputPath << endl;
            ofstream outputFile;
            cout << "path: <" << path << ">" << endl;
            outputFile.open(path);
            while (!outputFile.is_open()) {
                cout << "Wrong path! Try again:" << endl;
                getline(cin, path);
            }
            write(sock, "Done");
            messageFromServer = read(sock);
            outputFile << messageFromServer;
            write(sock, "Done");
        } else {
            if (!(messageFromServer == "[Waiting for enter]")) {
                cout << messageFromServer;
            }
            getline(cin, messageToServer);
            if(messageToServer.empty()) {
                messageToServer = "[Enter]";
            }
            // cout << "is enter got? {" << messageToServer << "}" << endl;
            write(sock, messageToServer);
        }
        // messageToServer.append("\0");
    }



}