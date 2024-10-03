#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Background.hpp"
#include "pvz/Framework/TextBase.hpp"
#include "pvz/GameObject/PlantingSpot.hpp"
#include "pvz/GameObject/Seed.hpp"
#include "pvz/GameObject/Zombies/Regular.hpp"
#include "pvz/GameObject/Zombies/BucketHead.hpp"
#include "pvz/GameObject/Zombies/PoleVaulting.hpp"
#include "pvz/GameObject/Sun.hpp"
#include "pvz/GameObject/Shovel.hpp"
#include "pvz/utils.hpp"
#include "pvz/GameObject/Cooldown.hpp"
#include "pvz/GameObject/Bullets/Bullet.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  // YOUR CODE HERE
  m_sun = 50;
  m_wave = 0;
  m_plantType = GameObject::PlantType::NONE;
  game_duration = 0;
  isShovel = false;
  nextWaveTick = 1200;

  // Create text display for wave and sun.
  m_sunText = std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, std::to_string(m_sun));
  m_waveText = std::make_shared<TextBase>(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 30, "Wave:" + std::to_string(m_wave));

  // Create background, seeds, and shovel.
  auto background = std::make_shared<Background>(shared_from_this());
  auto sunflowerseed = std::make_shared<Seed>(IMGID_SEED_SUNFLOWER, 130, WINDOW_HEIGHT - 40, 50, 240, shared_from_this());
  auto peashooterseed = std::make_shared<Seed>(IMGID_SEED_PEASHOOTER, 190, WINDOW_HEIGHT - 40, 100, 240, shared_from_this());
  auto wallnutseed = std::make_shared<Seed>(IMGID_SEED_WALLNUT, 250, WINDOW_HEIGHT - 40, 50, 900, shared_from_this());
  auto cherrybombseed = std::make_shared<Seed>(IMGID_SEED_CHERRY_BOMB, 310, WINDOW_HEIGHT - 40, 150, 1200, shared_from_this());
  auto repeaterseed = std::make_shared<Seed>(IMGID_SEED_REPEATER, 370, WINDOW_HEIGHT - 40, 200, 240, shared_from_this());
  auto shovel = std::make_shared<Shovel>(shared_from_this());

  gameObjects.push_back(background);
  gameObjects.push_back(sunflowerseed);
  gameObjects.push_back(peashooterseed);
  gameObjects.push_back(wallnutseed);
  gameObjects.push_back(cherrybombseed);
  gameObjects.push_back(shovel);
  gameObjects.push_back(repeaterseed);

  // Create 45 planting spots.
  for (int row = 0; row < GAME_ROWS; row++)
  {
    for (int col = 0; col < GAME_COLS; col++)
    {
      int x = FIRST_COL_CENTER + col * LAWN_GRID_WIDTH;
      int y = FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT;
      auto spot = std::make_shared<PlantingSpot>(x, y, shared_from_this());
      gameObjects.push_back(spot);
    }
  }
}

LevelStatus GameWorld::Update()
{
  // YOUR CODE HERE
  // Sun from the sky.
  if (game_duration == 180 || (game_duration != 0 && game_duration % 300 == 0))
  {
    auto sun = std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, randInt(63, 263), SunSource::Sky, shared_from_this());
    gameObjects.push_back(sun);
  }
  game_duration++;

  // Create new zombies.
  if (game_duration == nextWaveTick)
  {
    m_wave++;
    nextWaveTick += std::max(150, 600 - 20 * m_wave);
    cur_wave_zombie_num = (15 + m_wave) / 10;
    for (int i = 0; i < cur_wave_zombie_num; i++)
    {
      // Create different kinds of zombies randomly.
      int x = randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1);
      int y = FIRST_ROW_CENTER + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT;

      int P1 = 20;
      int P2 = 2 * std::max(m_wave - 8, 0);
      int P3 = 3 * std::max(m_wave - 15, 0);
      int total = P1 + P2 + P3;
      int r = randInt(0, total - 1);
      if (r < P1)
      {
        auto zombie = std::make_shared<Regular>(x, y, shared_from_this());
        gameObjects.push_back(zombie);
      }
      else if (r < P1 + P2)
      {
        auto zombie = std::make_shared<BucketHead>(x, y, shared_from_this());
        gameObjects.push_back(zombie);
      }
      else
      {
        auto zombie = std::make_shared<PoleVaulting>(x, y, shared_from_this());
        gameObjects.push_back(zombie);
      }
    }
  }

  // Update all game objects.
  for (auto &obj : gameObjects)
  {
    obj->Update();
  }

  // Handle collisions.
  for (auto &obj1 : gameObjects)
  {
    if (obj1->get_type() == GameObject::Type::Zombie)
    {
      for (auto &obj2 : gameObjects)
      {
        if (obj2->get_type() == GameObject::Type::Plant)
        {
          std::static_pointer_cast<Zombie>(obj1)->Collide_Plant(std::static_pointer_cast<Plant>(obj2).get());
        }
        else if (obj2->get_type() == GameObject::Type::Bullet)
        {
          std::static_pointer_cast<Bullet>(obj2)->Collide_Zombie(std::static_pointer_cast<Zombie>(obj1).get());
        }
      }
    }
  }

  // Clear dead game objects (Find the game objects marked as DEAD, and then delete them from gameObjects)
  auto it = gameObjects.begin();
  while (it != gameObjects.end())
  {
    if ((*it)->get_status() == GameObject::Status::DEAD)
    {
      it = gameObjects.erase(it);
    }
    else
    {
      it++;
    }
  }

  // Decide whether the game is over.
  for (auto &obj : gameObjects)
  {
    if (obj->get_type() == GameObject::Type::Zombie && obj->GetX() < 0)
    {
      return LevelStatus::LOSING;
    }
  }

  // Check if the plant is dead but the zombie is still eating.
  for (auto &obj1 : gameObjects)
  {
    bool isCollide = false;
    if (obj1->get_type() == GameObject::Type::Zombie)
    {
      for (auto &obj2 : gameObjects)
      {
        if (obj2->get_type() == GameObject::Type::Plant && abs(obj1->GetX() - obj2->GetX()) <= (obj2->GetWidth() / 2) && abs(obj1->GetY() - obj2->GetY()) <= obj2->GetHeight() / 3)
        {
          isCollide = true;
          break;
        }
      }
      if (!isCollide && std::static_pointer_cast<Zombie>(obj1)->get_zbstatus() == Zombie::ZB_status::Eat)
      {
        std::static_pointer_cast<Zombie>(obj1)->set_zbstatus(Zombie::ZB_status::Walk);
        std::static_pointer_cast<Zombie>(obj1)->PlayAnimation(ANIMID_WALK_ANIM);
      }
    }
  }

  // Update texts.
  set_sunText(m_sun);
  set_waveText(m_wave);

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  // YOUR CODE HERE
  // Clear all containers.
  gameObjects.clear();
}

int GameWorld::get_sun() const { return m_sun; }
int GameWorld::get_wave() const { return m_wave; }
GameObject::PlantType GameWorld::get_world_plantType() const { return m_plantType; }
bool GameWorld::get_isShovel() const { return isShovel; }

void GameWorld::set_sun(int delta_sun)
{
  m_sun += delta_sun;
}
void GameWorld::set_wave(int delta_wave) { m_wave += delta_wave; }

void GameWorld::set_sunText(int sun)
{
  m_sunText->SetText(std::to_string(sun));
}

void GameWorld::set_waveText(int wave)
{
  m_waveText->SetText("Wave:" + std::to_string(wave));
}

void GameWorld::set_world_plantType(GameObject::PlantType type) { m_plantType = type; }
void GameWorld::set_isShovel(bool is_shovel) { isShovel = is_shovel; }

std::list<std::shared_ptr<GameObject>> &GameWorld::get_gameObjects()
{
  return gameObjects;
}