#include "aux_funcs.h"
#include "Client.h"
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Agency.h"

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

vector<string> parse_places(string all_places) {
	// Creates a vector of strings representing places from an original string containing all of them separated by commas
	vector<string> places;
	all_places += ',';
	string temp = "";
	for (unsigned int i = 0; i < all_places.size(); i++) {
		if (all_places[i] == '-' || all_places[i] == ',') {
			trim(temp);
			places.push_back(temp);
			temp = "";
		}
		else {
			temp += all_places[i];
		}
	}
	return places;
}

vector<int> separate_string_int(string str){
    stringstream s(str);
    int id;
    vector<int> int_vec;
    while(s >> id){
        int_vec.push_back(id);
        s.clear();
        s.ignore(1000, ' ');
    }
    return int_vec;
}

bool is_in(int t, vector<int> v){
    for (size_t i = 0; i < v.size(); i++){
        if (v.at(i) == t)
            return true;
    }
    return false;
}

bool compare_packs(Pack pack1, Pack pack2){
    return pack1.getAlreadySold() > pack2.getAlreadySold();
}

string get_first_not_in(vector<string> places, vector<spe_pair> target_places){
    bool equal = false;
    for (size_t i = 0; i < target_places.size(); i++){
        for (string place: places){
            if (target_places.at(i).first == place)
                equal = true;
        }
        if (!equal)
            return target_places.at(i).first;
        equal = false;
    }
    return "None";
}

bool is_valid(string NIF){
    if (NIF.size() != 9)
        return false;
    for (size_t i = 0; i < NIF.size(); i++){
        if(!isdigit(NIF[i]))
            return false;
    }
    return true;
}

bool is_leap_year(unsigned int year){
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    return false;
}