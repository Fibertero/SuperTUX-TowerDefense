#ifndef ENEMY_H
#define ENEMY_H
#include"raylib.h"

class Enemy {
    public:
    Vector2 position;
    float speed;
    int health;
    int type;
    Rectangle hitbox;
    bool active;

    Enemy(Vector2 position, float speed, int health, int type, bool active);

    void Update();

    void Draw();
};

#endif