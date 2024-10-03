#include "pvz/GameObject/Plants/Plant.hpp"

class Wallnut : public Plant
{
public:
    using Plant::Plant;
    void Update() override;
};