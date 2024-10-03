#include "pvz/GameObject/GameObject.hpp"

class Seed : public GameObject
{
public:
    Seed(ImageID ID, int x, int y, int price, int cool_duration, pGameWorld world);
    void Update() override;
    void OnClick() override;
    int get_cooltick() const;
    void set_cooltick(int tick);

private:
    int price;
    int cool_duration;
    int cool_tick;
};