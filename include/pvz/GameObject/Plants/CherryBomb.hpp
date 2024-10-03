#include "pvz/GameObject/Plants/Plant.hpp"

class CherryBomb : public Plant
{
public:
    using Plant::Plant;
    void Update() override;

private:
    int plant_duration = 0;
};