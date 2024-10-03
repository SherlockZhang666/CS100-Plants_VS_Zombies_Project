#include "pvz/GameObject/GameObject.hpp"

// Your everything begins from here.
GameObject::GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld world, Type type)
    : ObjectBase(imageID, x, y, layer, width, height, animID), m_world(world), m_plantType(PlantType::NONE), m_status(Status::ALIVE), m_type(type) {}

pGameWorld GameObject::get_world() const
{
    return m_world;
}

GameObject::PlantType GameObject::get_object_plantType() const { return m_plantType; }
void GameObject::set_object_plantType(PlantType type) { m_plantType = type; }

GameObject::Status GameObject::get_status() const { return m_status; }
void GameObject::set_status(Status status) { m_status = status; }

GameObject::Type GameObject::get_type() const { return m_type; }
void GameObject::set_type(Type type) { m_type = type; }