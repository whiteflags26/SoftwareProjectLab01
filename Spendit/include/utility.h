#pragma once
#include "string.h"
#include "list.h"

class Utility
{
  public:
      static List<String> split(String &str, char delimiter);
};

