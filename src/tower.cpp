#include"tower.hpp"

Tower::Tower(Vector2 position, float range, int damage, float fireRate, int type, int level, int cost, int state) : position(position), range(range), damage(damage), fireRate(fireRate), type(type), level(level), cost(cost), state(state)
    {
        projectile = new Projectile((Vector2){position.x, position.y}, (Vector2){2,2}, 1, 100, 1, false);
        target = nullptr;
    }
    
void Tower::Draw(){
    DrawRectangle(position.x, position.y, 60, 60, WHITE);
}