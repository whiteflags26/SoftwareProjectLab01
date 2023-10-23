#include "file.h"

std::vector<std::string> FileHandler::Read(std::string filepath)
{
    FILE *fp = fopen(filepath.c_str(), "r");
    if(fp == NULL)
    {
        throw "Error opening file";
    }
    std::vector<std::string> lines;
    char line[10000];
    while(fgets(line, 10000, fp))
    {
        lines.push_back(line);
        lines.back().pop_back();
    }
    fclose(fp);
    return lines;
}

void FileHandler::Write(std::string filepath, std::string content)
{
    content.push_back('\n');

    FILE *fp = fopen(filepath.c_str(), "w");
    if(fp == NULL)
    {
        throw "Error opening file";
    }
    if(fputs(content.c_str(), fp) == EOF)
    {
        throw "Error writing to file";
    }
    fclose(fp);
}

void FileHandler::WriteLine(std::string filepath, std::string content)
{
    content.push_back('\n');

    FILE *fp = fopen(filepath.c_str(), "a");
    if(fp == NULL)
    {
        throw "Error opening file";
    }
    if(fputs(content.c_str(), fp) == EOF)
    {
        throw "Error writing to file";
    }
    fclose(fp);
}