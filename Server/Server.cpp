// #include "Server.h"
#include "ServerFront.h"
#include <iostream>
#include <cstring>
#include "../CreateClassifiedFiles.h"
#include <thread>

using namespace std;

//all client functionality here
void handleClient(int client_sock, ServerFront front){
    char message[4096] = {0};
    cout << "new thread" << endl;
    cout << front.receiveMessage(client_sock) << endl;
    strcpy(message, "clientTest");
    front.sendMessage(message, client_sock);
    cout << "closing thread" << endl;
}

/*
 * Main for the server, to communicate with the clients.
 * The server gets a path to unclassified flowers from a client and
 * classify them, after that, the server sends it back to the client.
 */
int main(int argc, char const *argv[]) {
    // Responsible for the communication.
    ServerFront front;
    front.StartServer();

    //for some resone if the first client is connected inside the loop the server
    //has an error binding its own socket when it starts?? very wierd
    int firstClient = front.getNewClient();
    thread firstClientThread(handleClient, firstClient, front);

    vector<thread> openThreads;

    // openThreads.emplace_back([&](){handleClient(firstClient);});

    while(true){ //later add a stop in it
        int client_sock = front.getNewClient();;
        // thread clientThread(handleClient, client_sock);
        openThreads.emplace_back([&](){handleClient(client_sock, front);});
    }
    //waits for all the threads to close
    for (auto& t: openThreads){
        t.join();
    }
    firstClientThread.join();

    //closes the server
    front.CloseServer();
}