#include "file.h"

List<String> FileHandler::Read(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    if(fp == NULL)
    {
        throw "Error opening file";
    }
    List<String> lines;
    char line[10000];
    while(fgets(line, 10000, fp))
    {
        lines.push(line);
        lines.back().pop();
    }
    fclose(fp);
    return lines;
}

List<String> FileHandler::Read(String &filepath)
{
    return FileHandler::Read(filepath.c_str());
}



void FileHandler::Write(const char *filepath, const char *content)
{
    FILE *fp = fopen(filepath, "w");
    if(fp == NULL)
    {
        throw "Error opening file";
    }
    if(fputs(content, fp) == EOF)
    {
        throw "Error writing to file";
    }
    fputs("\n", fp);
    fclose(fp);
}

void FileHandler::Write(String &filepath, const char *content)
{
    FileHandler::Write(filepath.c_str(), content);
}

void FileHandler::Write(const char *filepath, String &content)
{
    FileHandler::Write(filepath, content.c_str());
}

void FileHandler::Write(String &filepath, String &content)
{
    FileHandler::Write(filepath.c_str(), content.c_str());
}



void FileHandler::WriteLine(const char *filepath, const char *content)
{
    

    FILE *fp = fopen(filepath, "a");
    if(fp == NULL)
    {
        throw "Error opening file";
    }
    if(fputs(content, fp) == EOF)
    {
        throw "Error writing to file";
    }
    fputs("\n", fp);
    fclose(fp);
}

void FileHandler::WriteLine(const char *filepath, String &content)
{
    FileHandler::WriteLine(filepath, content.c_str());
}

void FileHandler::WriteLine(String &filepath, String &content)
{
    FileHandler::WriteLine(filepath.c_str(), content.c_str());
}