#ifndef ENEMY_H
#define ENEMY_H
#include"raylib.h"
#include"mapSelect.hpp"
#include<vector>
#define MAX_NUMBER_ENEMIES 1000

class Enemy {
    public:
    Vector2 position;
    float speed;
    int health;
    Rectangle hitbox;
    bool active;
    Color lastColor;

    Enemy(Vector2 position, float speed, int health, bool active);

    void Update(std::vector<Enemy>& enemies, Map& currentMap);

    void Draw();
};

#endif