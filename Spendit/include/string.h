#pragma once

class String {
private:
    char* data;
    int length;

public:
    String();
    String(const char* str);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String operator+(const String& other) const;
    char operator[](int index) const;
    bool operator==(const String& other) const;

    int size() const;
    const char* c_str() const;
    String substr(int pos, int count) const;
    void pop();
    
    double to_double() const;
    int to_int() const;
};
