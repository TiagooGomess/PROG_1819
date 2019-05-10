#include "Address.h"
#include "Agency.h"
#include "Date.h"
#include "Pack.h"
#include "Client.h"
#include "aux_funcs.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    Agency agency("agency.txt");
    cout << "Ola" << endl;
    vector<Client> clients_vector = agency.getClients();
    cout << clients_vector.size() << endl;
    for (size_t i = 0; i < clients_vector.size(); i++){
        cout << clients_vector.at(i) << endl;
    }
    return 0;
}