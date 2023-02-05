#include"castle.hpp"
#include<iostream>
#define RAYGUI_IMPLEMENTATION
#include"raygui.h"
#undef RAYGUI_IMPLEMENTATION

void Castle::Upgrade(PlayerData& playerData){
    if(playerData.points > upgradeCost){
        playerData.points -= upgradeCost;
        health*=2;
        upgradeCost *= 2;
    }
}

void Castle::Draw(){
    DrawTexture(Textures::Get("castle"), hitBox.x, hitBox.y, WHITE);
    DrawRectangle(hitBox.x, hitBox.y, hitBox.width, hitBox.height, ColorAlpha(GRAY, 0.5f));
    GuiPanel((Rectangle){hitBox.x, hitBox.y, hitBox.width, hitBox.height}, "Castle");
}

Castle::Castle(int _health, int _upgradeCost, Rectangle _hitBox):
    health(_health), upgradeCost(_upgradeCost), hitBox(_hitBox){
    }
