#include "pvz/GameObject/Zombies/Zombie.hpp"

class Bullet : public GameObject
{
public:
    enum class BulletType
    {
        Pea,
        Explosion
    };

    Bullet(ImageID ID, int x, int y, int width, int height, pGameWorld world, BulletType bullettype);
    void Update() override;
    void OnClick() override;
    BulletType get_bullet_type() const;
    void Collide_Zombie(Zombie *other);

private:
    BulletType bullet_type;
};