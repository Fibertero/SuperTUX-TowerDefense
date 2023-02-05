#include"enemy.hpp"
#include<iostream>

Enemy::Enemy(Vector2 position, float speed, int health, bool active) : position(position), speed(speed), health(health), active(active) {
    hitbox = { position.x, position.y, 20, 20 };
}
void Enemy::Update(std::vector<Enemy>& enemies, Map& currentMap){
    // code to update the enemy's position and state, such as moving it towards the end of the path
    for (Enemy& enemy : enemies){
        if (!enemy.active) continue;

        Color enemyPixel = GetImageColor(currentMap.enemyPathImage,
            (int)enemy.position.x,
            (int)enemy.position.y);

        enemy.hitbox.x = enemy.position.x;
        enemy.hitbox.y = enemy.position.y;
        //std::cout << static_cast<int>(enemyPixel.r) << "," << static_cast<int>(enemyPixel.g) << "," << static_cast<int>(enemyPixel.b) << '\n';
        //Check if is the pixel YELLOW
        if(enemyPixel.r == 255)
        {
            enemy.lastColor = YELLOW;
            enemy.position.x += enemy.speed;
        }
        //Check if is the pixel GREEN
        else if (enemyPixel.g == 255)
        {
            enemy.lastColor = GREEN;
            enemy.position.y += enemy.speed;
        }
        //Check if is the pixel BLUE
        else if(enemyPixel.b == 255)
        {
            enemy.lastColor = BLUE;
            enemy.position.x -= enemy.speed;
        }

        else{
            //Check if the last color was blue
            if(enemy.lastColor.r == YELLOW.r){
                enemy.position.x += 1;
            }
            //Check if the last color was blue
            else if(enemy.lastColor.g == GREEN.g){
                enemy.position.y += 1;
            }
            //Check if the last color was blue
            else if(enemy.lastColor.r == BLUE.r){
                enemy.position.x -= 1;
            }
            //If player reachs the screen limit
            if(enemy.position.x > GetScreenWidth() || enemy.position.x < 0 || enemy.position.y < 0 || enemy.position.y > GetScreenHeight()){
                enemy.active = false;
            }
        }
    }
}

void Enemy::Draw(){
    // code to draw the enemy on the screen using Raylib's drawing functions
    DrawRectangleRec(hitbox, RED);
}