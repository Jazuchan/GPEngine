cmake_minimum_required(VERSION 2.6)

project(GPENGINE)

add_executable(game
  source/game/main.cpp
)

add_library(GPTest
source/GPTest/Entity.cpp
)

target_link_libraries(game GPTest)