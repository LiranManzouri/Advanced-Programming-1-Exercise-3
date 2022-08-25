cmake_minimum_required(VERSION 3.24)
project(Advanced_Programming_1___Exercise_3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(Client)
include_directories(Server)
include_directories(Command)

add_executable(Advanced_Programming_1___Exercise_3 Client/Client.cpp
        Client/Client.h
        Client/ClientFront.cpp
        Client/ClientFront.h
        Server/Server.cpp
        Server/Server.h
        Server/ServerFront.cpp
        Server/ServerFront.h
        Command/Command.cpp
        Command/Command.h
        Command/AlgoSettingsCommand.cpp
        Command/AlgoSettingsCommand.h
        Command/UploadCommand.cpp
        Command/UploadCommand.h
        Command/ClassifyCommand.cpp
        Command/ClassifyCommand.h
        Command/PrintClassifiedCommand.cpp
        Command/PrintClassifiedCommand.h
        Command/DownloadResultsCommand.cpp
        Command/DownloadResultsCommand.h
        SocketIO.cpp
        SocketIO.h
        CLI.cpp
        CLI.h
        tempMain.cpp
        tempMain.h
        GetUnclassifiedFileData.cpp
        GetUnclassifiedFileData.h
        ClassifyFlower.cpp
        ClassifyFlower.h
        CreateClassifiedFiles.cpp
        CreateClassifiedFiles.h
        CreateFlowerByLine.cpp
        CreateFlowerByLine.h
        DistanceCalculator.cpp
        DistanceCalculator.h
        Flower.cpp
        Flower.h
        KNN.cpp
        KNN.h
        ReadFlowers.cpp
        ReadFlowers.h)
