#!usr/bin/bash

g++ Server/*.cpp Server/*.h *.cpp *.h -pthread -o bin/Server.out
g++ Client/*.cpp Client/*.h *.cpp *.h -o bin/Client.out

function terminal1(){
    bin/Server.out
}

function terminal2(){
    bin/Client.out
}

export -f terminal1
export -f terminal2

x-terminal-emulator -e bash -c 'terminal1; bash'
x-terminal-emulator -e bash -c 'terminal2; bash'
x-terminal-emulator -e bash -c 'terminal2; bash'
x-terminal-emulator -e bash -c 'terminal2; bash'
x-terminal-emulator -e bash -c 'terminal2; bash'