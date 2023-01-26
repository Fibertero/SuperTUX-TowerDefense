#include"raylib.h"
#include<unordered_map>
#include<string>
#include<vector>

namespace Fonts{
    void Init();
    void Load(std::string name, std::string path);
    Font& Get(std::string name);
    void ShutDown();
}