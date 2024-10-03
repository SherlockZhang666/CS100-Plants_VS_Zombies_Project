cmake_minimum_required(VERSION 3.16)

add_library(
  GameObject
  STATIC
  GameObject.cpp
  Background.cpp
  PlantingSpot.cpp

  Seed.cpp
  Cooldown.cpp
  Sun.cpp
  Shovel.cpp
  
)

add_subdirectory(Bullets)
add_subdirectory(Plants)
add_subdirectory(Zombies)

target_link_libraries(
  GameObject
  Framework
  GameWorld
  Bullets
  Plants 
  Zombies
)
