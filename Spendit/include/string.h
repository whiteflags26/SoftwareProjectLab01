#pragma once
#include <algorithm>
#include <iostream>

class String {
private:
    char* data;
    size_t length;

public:
    String();
    String(const char* str);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String operator+(const String& other) const;
    char operator[](size_t index) const;

    size_t size() const;
    const char* c_str() const;
    String substr(size_t pos, size_t count) const;
    void pop();
};
