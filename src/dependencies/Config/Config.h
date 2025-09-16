#pragma once
#include <string>
#include <vector>

namespace Config
{

    void Save(const std::string& name);


    void Load(const std::string& name);


    void Delete(const std::string& name);


    std::vector<std::string> GetConfigList();


    std::string GetConfigFolder();

    bool InitializeFolder();
}