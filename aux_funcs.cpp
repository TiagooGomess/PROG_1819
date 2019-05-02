#include "aux_funcs.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void trim(string &str){
    size_t pos = str.find_first_not_of(' ');
    str.erase(0, pos);
    pos = str.find_last_not_of(' ');
    if (string::npos != pos)
        str.erase(pos + 1);
}

vector<string> separate_string(string str, char separator){
    vector<string> str_fields;
    string temp = "";
    str += separator;

    for(size_t i = 0; i < str.size(); i++){
        if (str[i] == separator){
            trim(temp);
            str_fields.push_back(temp);
            temp = "";
        } else {
            temp += str[i];
        }
    }

    return str_fields;
}

vector<int> convert_vector_str_to_int(vector<string> v){
    vector<int> vec;
    string temp;
    for (size_t i = 0; i < v.size(); i++){
        temp = "";
        temp = v.at(i);
        trim(temp);
        vec.push_back(stoi(temp));
    }
    return vec;
}