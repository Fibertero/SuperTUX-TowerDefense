#ifndef TOWER_H
#define TOWER_H
#include"raylib.h"
#include"projectile.hpp"

class Tower {
    public:
    Vector2 position;
    float range;
    int damage;
    float fireRate;
    Projectile* projectile;
    Enemy* target;
    int type;
    int level;
    int cost;
    int state;

    Tower(Vector2 position, float range, int damage, float fireRate, int type, int level, int cost, int state);

    void Update();

    void Draw();
};
#endif