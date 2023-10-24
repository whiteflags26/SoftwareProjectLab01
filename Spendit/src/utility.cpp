#include "utility.h"

List<String> Utility::split(String &str, char delimiter){
    List<String> result; 
    char word[(int)str.size()];
    for(int i = 0, j = 0; i < str.size(); i++){
        if(str[i] == delimiter || i+1 == str.size()){
            word[j] = '\0';
            result.push(word);
            j = 0;
        }else{
            word[j++] = str[i];
        }
    }

    return result;
}