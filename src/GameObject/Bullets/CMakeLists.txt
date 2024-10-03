cmake_minimum_required(VERSION 3.16)

add_library(
  Bullets
  STATIC
  Bullet.cpp
  Pea.cpp
  Explosion.cpp
)


target_link_libraries(
  GameObject
  Framework
  GameWorld
)