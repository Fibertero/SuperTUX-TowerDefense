#include"projectile.hpp"

Projectile::Projectile(Vector2 position, Vector2 velocity, float damage, int type, float speed, bool active) : position(position), velocity(velocity), damage(damage), type(type), speed(speed), active(active) {}

void Projectile::Update(){
    // code to update the projectile's position and state, such as moving it in the direction of its velocity
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}

void Projectile::Draw(){
    // code to draw the projectile on the screen using Raylib's drawing functions
    DrawCircleV(position, 3, GREEN);
}

void Projectile::CheckCollision(Enemy* enemy){
    // code to check for collision with an enemy and deal damage if a collision occurs
    if (CheckCollisionCircleRec(position, 3, enemy->hitbox)) {
        enemy->health -= damage;
        active = false;
    }
};