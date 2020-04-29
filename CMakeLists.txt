cmake_minimum_required(VERSION 3.0)
project(Projet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
#programme principal

add_executable(foot
        Equipe/Equipe.cpp
        Equipe/Joueur.cpp
        Infra/Parser.cpp
        Managers/EquipesManager.cpp
        Managers/JoueursManager.cpp
        Ligue/Buteur.cpp
        Ligue/Journee.cpp
        Ligue/Ligue.cpp
        Ligue/Match.cpp
        main.cpp)
target_link_libraries(foot)



