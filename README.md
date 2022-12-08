# Advanced Programming 1 - Exercise 3

In order to run the project, you will need to save an empty "bin" directory in the directory you are in at the time you
run the project. Next, you'll need to open 2 terminals, in each you'll need to move into the directory where the code
files + the bin directory are in. One terminal for the server, which the compile command and the run command in it are:
Compile command - "g++ -std=c++11 Server/\*.cpp Server/\*.h Command/\*.cpp Command/\*.h IO/\*.cpp IO/\*.h
Converts/\*.cpp Converts/\*.h \*.cpp \*.h -o bin/Server.out -pthread". Run Command - "./bin/Server.out". The second
terminal is for the client, which the compile command and the run command in it are:
Compile command - "g++ -std=c++11 Client/\*.cpp Client/\*.h Converts/\*.cpp Converts/\*.h *.cpp *.h -o bin/Client.out".
Run command - "./bin/Client.out". We chose the port to be 5555, the buffer/messages size to be 16384 and the timeout to
be 90 seconds. For running the program you'll have to run the server first and then the client. For running multiple
clients, you'll have to compile the client only once and in the other terminals you'll just have to get into the
directory where the code files and the bin directory are in, and just run again by: "./bin/Client.out".

# The Program

The program has a server side and a client side, the server gets new clients, and each client that connects, gets a menu
from the server with several commands. The client choosing his desired command and the server is doing this command,
then sending the results back to the client, and saves it for the next commands. If the server isn't getting new client
in 90 seconds, he stops listening and stops the program after the current clients which already connected are exiting
the program. Each client has its own parameters and information. The program is able to get 2 files, which each has
flowers in its lines, where in the line there are flower attributes seperated by ',' and the last attribute can save the
type. One file is classified (The flowers types are given in the file) and the other unclassified (The flowers types are
unknown, each line saves only attributes without the type). The program can classify the unclassified file by the
classified file. it can print the classification results, download them to a local file in the client's computer, and
calculate the percentage of classification success for each flower type.

# Implementation

In this project, the server waits for connection in an infinity loop. When a client connects, the server opens a new
thread for the client, which calls the CLI::start() function and runs the client side. The communication in the server
side is done by the abstract class DefaultIO, and in this program we are using SocketIO. In the client side there are 2
functions which responsible for the communication back with the server. Each SocketIO gets the client socket, so it will
know which client asked for the information and where the returned message should go to. The client knows when to
open/close/create files, when should he insert input to the command line, when he needs just to print, or when he needs
to exit, by sending an opening identifier from the server with the message. For example, if the server wants to send the
client "hello" and wants it only to be printed and not anything else, the server will send: "[Print]:hello". The client
in his side will see the identifier and will act accordingly.
