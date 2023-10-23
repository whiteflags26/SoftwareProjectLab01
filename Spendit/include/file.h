#pragma once
#include <vector>
#include <string>

class FileHandler
{
    public:
        std::vector<std::string> Read(std::string filepath);
        void Write(std::string filepath, std::string content);
        void WriteLine(std::string filepath, std::string content);
};