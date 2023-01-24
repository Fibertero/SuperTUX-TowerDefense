#include"enemy.hpp"


Enemy::Enemy(Vector2 position, float speed, int health, int type, bool active) : position(position), speed(speed), health(health), type(type), active(active) {
    hitbox = { position.x, position.y, 20, 20 };
}

void Enemy::Update(){
    // code to update the enemy's position and state, such as moving it towards the end of the path
    position.x -= speed;
    hitbox.x = position.x;
    hitbox.y = position.y;
}

void Enemy::Draw(){
    // code to draw the enemy on the screen using Raylib's drawing functions
    DrawRectangleRec(hitbox, RED);
}