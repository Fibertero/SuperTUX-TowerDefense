#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <unordered_map>
#include "raylib.h"
#include<string>
#include<vector>
#include"dirent.h"

namespace Textures {

    void Init();
    void Load(std::string name, std::string filePath);
    Texture2D& Get(std::string name);
    void ShutDown();
}

#endif // TEXTURES_HPP