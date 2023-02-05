#include"raylib.h"
#include"player.hpp"

class Castle{
public:
    int health;
    int upgradeCost;
public:
    Castle(int _health, int _upgradeCost);
    void Upgrade(PlayerData& playerData);
};
