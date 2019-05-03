
#include "Address.h"
#include "aux_funcs.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Address::Address(){
};

Address::Address(string address){
    vector<string> address_fields = separate_string(address, '/');
    this->street = address_fields.at(0);
    this->door_number = stoi(address_fields.at(1));
    this->floor = address_fields.at(2);
    this->zip_code = address_fields.at(3);
    this->city = address_fields.at(4);
}

Address::Address(string street, unsigned int door_number, string floor, string zip_code, string city){
    this->street = street;
    this->door_number = door_number;
    this->floor = floor;
    this->zip_code = zip_code;
    this->city = city;
}

string Address::getStreet() const{
    return this->street;
}

unsigned int Address::getDoorNumber() const{
    return this->door_number;
}

string Address::getFloor() const{
    return this->floor;
}

string Address::getZipCode() const{
    return this->zip_code;
}

string Address::getCity() const{
    return this->city;
}

void Address::setStreet(string str){
    trim(str);
    this->street = str;
}

void Address::setDoorNumber(unsigned int door_num){
    this->door_number = door_num;
}

void Address::setFloor(string floor){
    trim(floor);
    this->floor = floor;
}

void Address::setZipCode(string zip_code){
    trim(zip_code);
    this->zip_code = zip_code;
}

void Address::setCity(string city){
    trim(city);
    this->city = city;
}

bool Address::isValid() const{
    if (getStreet() != "" && getFloor() != "" && isValidZipCode(getZipCode()) && getCity() != "")
        return true;
    return false;
}

bool Address::isValidZipCode(string zip) const{
    for(size_t i = 0; i < 4; i++){
        if(!isdigit(zip[i]))
            return false;
    }
    if (zip[4] != '-')
        return false;
    for (size_t j = 5; j < zip.size(); j++){
        if(!isdigit(zip[j]))
        return false;
    }
    return true;
}

ostream& operator<<(ostream& out, const Address & address){
    out << address.street << "  /  " << address.door_number << "  /  " << address.floor << "  /  " << address.zip_code << "  /  " << address.city << "  ";
}