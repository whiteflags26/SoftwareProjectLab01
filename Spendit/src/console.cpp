#include "console.h"

String Console::ReadLine()
{
    char buffer[1000];
    fgets(buffer, 1000, stdin);
    String content = buffer;
    content.pop();
    return content;
}

void Console::WriteLine(const char *content)
{
    fputs(content, stdout);
    fputs("\n", stdout);
}

void Console::WriteLine(String &content)
{
    fputs(content.c_str(), stdout);
    fputs("\n", stdout);
}