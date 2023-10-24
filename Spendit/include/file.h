#pragma once
#include "string.h"
#include "list.h"

class FileHandler
{
    public:
        List<String> Read(const char *filepath);
        List<String> Read(String &filepath);
        
        void Write(const char *filepath, const char *content);
        void Write(String &filepath, const char *content);
        void Write(const char *filepath, String &content);
        void Write(String &filepath, String &content);

        void WriteLine(const char *filepath, const char *content);
        void WriteLine(String &filepath, const char *content);
        void WriteLine(const char *filepath, String &content);
        void WriteLine(String &filepath, String &content);
};