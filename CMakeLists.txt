cmake_minimum_required(VERSION 3.0)
project(Projet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic-errors")
#programme principal

add_executable(foot
        Equipe/Team.cpp
        Equipe/Player.cpp
        Infra/Parser.cpp
        Managers/TeamManager.cpp
        Managers/PlayerManager.cpp
        Ligue/Scorer.cpp
        Ligue/Day.cpp
        Ligue/League.cpp
        Ligue/Match.cpp
        main.cpp)
target_link_libraries(foot)



