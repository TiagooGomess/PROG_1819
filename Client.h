
#pragma once

#include "Address.h"
#include <string>
#include <vector>


using namespace std;

class Client{
    public:
        Client(string name, string nif, unsigned int num_people, string address, string bought_packs, unsigned int total_buys);


    private:
        string name;
        string nif;
        unsigned int num_people;
        Address address;
        vector<int> bought_packs;
        unsigned int total_buys;
};