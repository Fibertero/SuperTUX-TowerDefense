#include"raylib.h"
#include"player.hpp"
#include"textures.hpp"

class Castle{
public:
    int health;
    int upgradeCost;
    Rectangle hitBox;
public:
    Castle(int _health, int _upgradeCost, Rectangle _hitBox);
    void Upgrade(PlayerData& playerData);
    void Draw();
};

