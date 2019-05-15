
#pragma once

#include <vector>
#include <string>

using namespace std;

void trim(string &str);

vector<string> separate_string(string str, char separator);

vector<int> convert_vector_str_to_int(vector<string> v);

vector<string> parse_places(string all_places);

vector<int> separate_string_int(string str);

bool is_in(int t, vector<int> v);
