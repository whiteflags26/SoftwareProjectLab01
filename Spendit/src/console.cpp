#include "console.h"

std::string Console::ReadLine()
{
    char buffer[1000];
    fgets(buffer, 1000, stdin);
    std::string content(buffer);
    content.pop_back(); 
    return content;
}

void Console::WriteLine(std::string content)
{
    content.push_back('\n');
    fputs(content.c_str(), stdout);
}