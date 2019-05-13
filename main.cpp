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
    //bool aodkso = agency.update_clients_file();
    //bool sdsadas = agency.update_packs_file();
    
	Date date("2/5/2020");

	cout << date;

	return 0;
}