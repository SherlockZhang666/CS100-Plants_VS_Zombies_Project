#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "pvz/Framework/ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject>
{
public:
  enum class PlantType
  {
    Sunflower,
    Peashooter,
    Wallnut,
    CherryBomb,
    Repeater,
    NONE
  };

  enum class Type
  {
    Plant,
    Zombie,
    Bullet,
    Others
  };

  enum class Status
  {
    ALIVE,
    DEAD
  };

  using std::enable_shared_from_this<GameObject>::shared_from_this;
  GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld world, Type type);
  pGameWorld get_world() const;
  void set_object_plantType(GameObject::PlantType type);
  GameObject::PlantType get_object_plantType() const;
  Status get_status() const;
  void set_status(Status status);
  Type get_type() const;
  void set_type(Type type);

private:
  pGameWorld m_world;
  PlantType m_plantType;
  Status m_status;
  Type m_type;
};

#endif // !GAMEOBJECT_HPP__
