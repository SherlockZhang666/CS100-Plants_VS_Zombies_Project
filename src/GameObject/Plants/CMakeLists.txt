cmake_minimum_required(VERSION 3.16)

add_library(
  Plants
  STATIC
  Plant.cpp
  Sunflower.cpp
  Peashooter.cpp 
  Wallnut.cpp 
  CherryBomb.cpp
  Repeater.cpp
)


target_link_libraries(
  GameObject
  Framework
  GameWorld
)