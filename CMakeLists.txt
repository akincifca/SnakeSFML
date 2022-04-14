cmake_minimum_required(VERSION 3.21)
project(snakegame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(snakegame
        main.cpp
        include/State.h
        include/StateMng.h
        src/StateMng.cpp
        src/AssetMng.cpp
        include/AssetMng.h
        src/Game.cpp
        include/Game.h
        src/MainMenu.cpp
        include/MainMenu.h
        )
target_link_libraries(snakegame sfml-graphics sfml-window sfml-system)
