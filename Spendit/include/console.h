#pragma once
#include "string.h"
#include <cstdio>

class Console
{
    public:
        static String ReadLine();
        static void WriteLine(const char *content);
        static void WriteLine(String &content);
};