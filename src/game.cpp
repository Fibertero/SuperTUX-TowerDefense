#include"game.hpp"
#include<iostream>


void Game::Init(int numberEnemies){
    for(int i{}; i<numberEnemies; i++){
        enemies.push_back((Enemy){(Vector2){GetScreenWidth()/2, 20}, 0.02, 10, false});
    }
}

void Game::Draw(Castle castle){
    for (Enemy& enemy : enemies) {
        enemy.Draw();
    }
    castle.Draw();
    DrawText(std::to_string(currentRound).c_str(), GetScreenWidth()-30, GetScreenHeight()-30, 30, BLACK);
}

void Game::Update(std::vector<Enemy>& enemies, Map& currentMap, GlobalMessage& globalMessage){
    for (Enemy& enemy : enemies) {
        enemy.Update(enemies, currentMap);
    }
    //Check if are the enemies died and pass to the next round
    if(CheckEnemiesState(enemies)) NextRound(globalMessage);
}

void Game::NextRound(GlobalMessage& globalMessage){
    globalMessage.SetInfo("Subindo para o próximo round...", WARNING_MESSAGE);
    for(auto& enemy: enemies){
        enemy.active = true;
    }
    //Multiply the enemies
    for(int i{}; i<enemies.size()/6; i++){
        enemies.push_back((Enemy){(Vector2){GetScreenWidth()/2, 20}, 0.05, 10, false});
    }
    currentRound += 1;
}

// true = all enemies is dead; False = enemies isn't dead
bool Game::CheckEnemiesState(std::vector<Enemy>& enemies){
    for(auto& enemy : enemies){
        if(enemy.active == true) return false;
    }
    return true;
}

void Game::SpawnEnemy(){
    enemies[currentEnemySpawn].active = true;
    currentEnemySpawn += 1;
    std::cout << "ativando-te" << '\n';
}

//Tower store
/*

*/

Game::Game(std::vector<Enemy>& _enemies) : enemies(_enemies){
    currentRound = 1;
    currentEnemySpawn = 0;
}