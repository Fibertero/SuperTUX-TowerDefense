#include"castle.hpp"

void Castle::Upgrade(PlayerData& playerData){
    if(playerData.points > upgradeCost){
        playerData.points -= upgradeCost;
        health*=2;
        upgradeCost *= 2;
    }
}

Castle::Castle(int _health, int _upgradeCost):
    health(_health), upgradeCost(_upgradeCost){

    }
