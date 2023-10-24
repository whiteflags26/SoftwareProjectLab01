#include "string.h"

String::String(){
    data = nullptr;
    length = 0;
  }

String::String(const char* str){
    size_t len = 0;
    while(str[len] != '\0') len++;

    length = len;
    data = new char[length + 1];

    for(size_t i = 0; i < length; i++) data[i] = str[i];

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

    for(size_t i = 0; i < length; i++) data[i] = other.data[i];
    data[length] = '\0';

    return *this;
}

String String::operator+(const String& other) const{
    String result;
    result.length = length + other.length;
    result.data = new char[result.length + 1];

    for(size_t i = 0; i < length; i++) result.data[i] = data[i];

    for(size_t i = 0; i < other.length; i++) result.data[i + length] = other.data[i];
    result.data[result.length] = '\0';

    return result;
}

char String::operator[](size_t index) const {
    if(index < length) return data[index];
  
    return '\0';
}

size_t String::size() const {
    return length;
}

const char* String::c_str() const {
    return data;
}

String String::substr(size_t pos, size_t count) const {
    if(pos >= length) return String(); 

    if(count > length - pos) count = length - pos;

    String sub;
    sub.length = count;
    sub.data = new char[count + 1];

    for(size_t i = 0; i < count; i++) sub.data[i] = data[pos + i];
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
