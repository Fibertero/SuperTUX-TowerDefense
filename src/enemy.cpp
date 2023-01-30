#include"enemy.hpp"
#include<iostream>

Enemy::Enemy(Vector2 position, float speed, int health, bool active) : position(position), speed(speed), health(health), active(active) {
    hitbox = { position.x, position.y, 20, 20 };
}

std::vector<Enemy> InitEnemies(){
    std::vector<Enemy> enemies;
    for(int i; i<100; i++){
        auto enemy = Enemy((Vector2){0,0}, 1, 50, true);
        enemies.push_back(enemy);
    }
    return enemies;
}

void Enemy::Update(std::vector<Enemy> enemies, Map currentMap){
    // code to update the enemy's position and state, such as moving it towards the end of the path
    for (int i = 0; i < enemies.size(); i++){
        if (!enemies[i].active) continue;

        Color enemyPixel = GetImageColor(currentMap.enemyPathImage,
            (int)enemies[i].position.x,
            (int)enemies[i].position.y);
        std::cout << static_cast<int>(enemyPixel.r) << "," << static_cast<int>(enemyPixel.g) << "," << static_cast<int>(enemyPixel.b) << '\n';
        if (enemyPixel.r == 255 || enemyPixel.r == 254)
        {
            std::cout << "true" << '\n';
            Vector2 nextPos = { enemies[i].position.x + enemies[i].speed,
                                    enemies[i].position.y + enemies[i].speed };
            Color nextPixel = GetImageColor(currentMap.enemyPathImage, (int)nextPos.x, (int)nextPos.y);

            if (nextPixel.r == 0)
            {
                enemies[i].active = false;
            }
            else
            {
                enemies[i].position = nextPos;
            }
                
        }
        else{
            std::cout << "red don't detected" << '\n';
        }
    }
}

void Enemy::Draw(){
    // code to draw the enemy on the screen using Raylib's drawing functions
    DrawRectangleRec(hitbox, WHITE);
}