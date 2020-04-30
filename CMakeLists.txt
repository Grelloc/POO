cmake_minimum_required(VERSION 3.0)
project(Projet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic-errors")
#programme principal

add_executable(foot
        Team/Team.cpp
        Team/Player.cpp
        Infra/Parser.cpp
        Managers/TeamManager.cpp
        Managers/PlayerManager.cpp
        League/Scorer.cpp
        League/Day.cpp
        League/League.cpp
        League/Match.cpp
        main.cpp)
target_link_libraries(foot)



