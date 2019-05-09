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
    cout << agency;
    return 0;
}