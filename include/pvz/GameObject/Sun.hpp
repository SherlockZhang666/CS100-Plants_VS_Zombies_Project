#include "pvz/GameObject/GameObject.hpp"

enum class SunSource
{
    Sky,
    Sunflower
};

class Sun : public GameObject
{
public:
    Sun(int x, int y, int droptime, SunSource source, pGameWorld world);
    SunSource get_source();
    void Update() override;
    void OnClick() override;

private:
    int droptime;
    SunSource source;
    int ground_ticks;
};