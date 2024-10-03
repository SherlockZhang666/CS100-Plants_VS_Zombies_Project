#include "pvz/GameObject/GameObject.hpp"

class Cooldown : public GameObject
{
public:
    Cooldown(int x, int y, int duration, pGameWorld world);
    void Update() override;
    void OnClick() override;

private:
    int m_duration;
};