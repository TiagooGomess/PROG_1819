#include "Address.h"
#include "aux_funcs.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    Address address = Address("Rua dos Galos / 34 /  -  / 3456-789 / Filipinas");
    cout << address << endl;
    return 0;
}