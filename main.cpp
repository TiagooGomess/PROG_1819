#include "Address.h"
#include "Agency.h"
#include "Date.h"
#include "Pack.h"
#include "Client.h"
#include "aux_funcs.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    Agency agency("agency.txt");

	//main_menu(agency);

    //agency.show_most_visited_places();
    
    agency.show_recommended_packs();
    
	return 0;
}