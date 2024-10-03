#include "pvz/GameObject/Background.hpp"

Background::Background(pGameWorld world)
    : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION, world, GameObject::Type::Others) {}

bool Background::operator==(const GameObject &other)
{
    return GameObject::operator==(other);
};