
#include "Client.h"
#include "Address.h"
#include "aux_funcs.h"
#include <string>
#include <vector>

Client::Client(string name, string nif, unsigned int num_people, string address, string bought_packs, unsigned int total_buys){
    Address add(address);
    this->name = name;
    this->nif = nif;
    this->num_people = num_people;
    this->address = add;
    vector<string> packs_ids = separate_string(bought_packs, ';');
    vector<int> ids_vector = convert_vector_str_to_int(packs_ids);
    this->bought_packs = ids_vector;
    this->total_buys = total_buys;
}