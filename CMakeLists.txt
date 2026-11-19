cmake_minimum_required(VERSION 3.10.0)
project(morpion_cpp VERSION 0.1.0 LANGUAGES C CXX)

add_executable(morpion_cpp
    SourceFiles/main.cpp
    SourceFiles/Grille.cpp
    SourceFiles/Joueur.cpp
    SourceFiles/Partie.cpp
)
include(CTest)
enable_testing()

include_directories("./HeadersFiles")