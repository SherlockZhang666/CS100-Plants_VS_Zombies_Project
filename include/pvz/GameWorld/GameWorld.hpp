#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "pvz/Framework/WorldBase.hpp"

#include "pvz/GameObject/GameObject.hpp"

#include "pvz/Framework/TextBase.hpp"
#include "pvz/utils.hpp"

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  int get_sun() const;
  int get_wave() const;
  GameObject::PlantType get_world_plantType() const;
  bool get_isShovel() const;

  void set_sun(int delta_sun);
  void set_wave(int delta_wave);
  void set_sunText(int sun);
  void set_waveText(int wave);
  void set_world_plantType(GameObject::PlantType type);
  void set_isShovel(bool is_shovel);

  std::list<std::shared_ptr<GameObject>> &get_gameObjects();

private:
  std::list<std::shared_ptr<GameObject>> gameObjects;
  int m_wave;
  int m_sun;
  std::shared_ptr<TextBase> m_waveText;
  std::shared_ptr<TextBase> m_sunText;
  GameObject::PlantType m_plantType;
  int game_duration;
  bool isShovel;
  int nextWaveTick;
  int cur_wave_zombie_num;
};

#endif // !GAMEWORLD_HPP__
