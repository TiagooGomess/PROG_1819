
#pragma once

#include <vector>
#include <string>
#include "Pack.h"
#include "Agency.h"

using namespace std;

typedef std::pair<string, int> spe_pair;

void trim(string &str);

vector<string> separate_string(string str, char separator);

vector<int> convert_vector_str_to_int(vector<string> v);

vector<string> parse_places(string all_places);

vector<int> separate_string_int(string str);

bool is_in(int t, vector<int> v);

bool compare_packs(Pack pack1, Pack pack2);

string get_first_not_in(vector<string> places, vector<spe_pair> target_places);

bool is_valid(string NIF);

bool is_leap_year(unsigned int year);

bool is_valid_address(string add);