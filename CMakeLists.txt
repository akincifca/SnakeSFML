cmake_minimum_required(VERSION 3.21)
project(snakegame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
set(HEADERS
        include/State.h
        include/StateMng.h
        include/AssetMng.h
        include/MainMenu.h
        include/Game.h
        include/GamePlay.h
        )
set(SOURCES
        main.cpp
        src/StateMng.cpp
        src/AssetMng.cpp
        src/Game.cpp
        src/MainMenu.cpp
        src/GamePlay.cpp
        )
add_executable(snakegame ${HEADERS} ${SOURCES})
target_link_libraries(snakegame sfml-graphics sfml-window sfml-system)
