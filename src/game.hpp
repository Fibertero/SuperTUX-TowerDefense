#ifndef GAME_H
#define GAME_H
#include"enemy.hpp"
#include"menu.hpp"
#include"timer.hpp"
#include"castle.hpp"
#include"tower.hpp"

#include <vector>

class Game {
private:
    int currentRound;
    int currentEnemySpawn;
public:
    std::vector<Enemy> enemies;
    Timer timer;

    Game(std::vector<Enemy>& _enemies);

    void NextRound(GlobalMessage& globalMessage);

    void Update(std::vector<Enemy>& enemies, Map& currentMap, GlobalMessage& globalMessage);

    void Draw(Castle castle);

    void Init(int numberEnemies);

    void SpawnEnemy();

    bool CheckEnemiesState(std::vector<Enemy>& enemies);
};

#endif