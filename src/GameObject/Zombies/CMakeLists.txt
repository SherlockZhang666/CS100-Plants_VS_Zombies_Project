cmake_minimum_required(VERSION 3.16)

add_library(
  Zombies
  STATIC
  Zombie.cpp
  Regular.cpp 
  BucketHead.cpp 
  PoleVaulting.cpp
)


target_link_libraries(
  GameObject
  Framework
  GameWorld
)