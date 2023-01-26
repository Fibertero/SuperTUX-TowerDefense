#include <unordered_map>
#include <string>
#include<vector>
#include "raylib.h"

namespace Audio
{
    extern std::unordered_map<std::string, Sound> sounds;

    void Init();
    void ShutDown();
    void Load(std::string name, std::string filepath);
    Sound GetSound(const std::string& soundName);
}