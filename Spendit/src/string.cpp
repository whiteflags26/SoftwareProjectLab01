#include "string.h"
#define MAX_INT 2147483647

String::String(){
    data = nullptr;
    length = 0;
  }

String::String(const char* str){
    int len = 0;
    while(str[len] != '\0') len++;

    length = len;
    data = new char[length + 1];

    for(int i = 0; i < length; i++) data[i] = str[i];

    data[length] = '\0';
}

String::String(const String& other){
    *this = other;
}

String::~String(){
    delete[] data;
}

String& String::operator=(const String& other){
    if (this == &other) return *this;

    if(length != 0) delete[] data;
    length = other.length;
    data = new char[length + 1];

    for(int i = 0; i < length; i++) data[i] = other.data[i];
    data[length] = '\0';

    return *this;
}

String String::operator+(const String& other) const{
    String result;
    result.length = length + other.length;
    result.data = new char[result.length + 1];

    for(int i = 0; i < length; i++) result.data[i] = data[i];

    for(int i = 0; i < other.length; i++) result.data[i + length] = other.data[i];
    result.data[result.length] = '\0';

    return result;
}

char String::operator[](int index) const {
    if(index < length) return data[index];
  
    return '\0';
}

bool String::operator==(const String& other) const {
    if (length != other.length) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

int String::size() const {
    return length;
}

const char* String::c_str() const {
    return data;
}

String String::substr(int pos, int count) const {
    if(pos >= length) return String(); 

    if(count > length - pos) count = length - pos;

    String sub;
    sub.length = count;
    sub.data = new char[count + 1];

    for(int i = 0; i < count; i++) sub.data[i] = data[pos + i];
    sub.data[count] = '\0';

    return sub;
}

void String::pop(){
    if (length > 0) {
        length--;
        data[length] = '\0';
    } else {
        throw "Already empty list!";
    }
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

double String::to_double() const {
    double result = 0.0;
    bool isNegative = false;
    int i = 0;

    if (length > 0 && data[0] == '-') {
        isNegative = true;
        ++i;
    }

    while (i < length && is_digit(data[i])) {
        result = result * 10.0 + (data[i] - '0');
        ++i;
    }

    if (i < length && data[i] == '.') {
        ++i;
        double decimalPlace = 0.1;
        while (i < length && is_digit(data[i])) {
            result += (data[i] - '0') * decimalPlace;
            decimalPlace *= 0.1;
            ++i;
        }
    }

    if (isNegative) {
        result = -result;
    }

    return result;
}

int String::to_int() const {
    int result = 0;
    bool isNegative = false;
    int i = 0;

    if (length > 0 && data[0] == '-') {
        isNegative = true;
        ++i;
    }

    while (i < length && is_digit(data[i])) {
        int digit = data[i] - '0';
        if (result > MAX_INT / 10 || (result == MAX_INT / 10 && digit > MAX_INT % 10)) {
            // Overflow occurred
            throw "Integer overflow!";
        }
        result = result * 10 + digit;
        ++i;
    }

    if (isNegative) {
        result = -result;
    }

    return result;
}
