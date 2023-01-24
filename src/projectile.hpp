#include"raylib.h"
#include"enemy.hpp"

class Projectile {
    public:
    Vector2 position;
    Vector2 velocity;
    float damage;
    int type;
    float speed;
    bool active;

    Projectile(Vector2 position, Vector2 velocity, float damage, int type, float speed, bool active);

    void Update();

    void Draw();

    void CheckCollision(Enemy* enemy);
};