
#pragma once

#include <string>

using namespace std;

class Address
{
    public:
        Address(string address);
        Address(string street, unsigned int door_number, string floor, string zip_code, string city);
        string getStreet() const;
        unsigned int getDoorNumber() const;
        string getFloor() const;
        string getZipCode() const;
        string getCity() const;
        void setStreet(string street);
        void setDoorNumber(unsigned int door_num);
        void setFloor(string floor);
        void setZipCode(string zip_code);
        void setCity(string city);
        void show() const;
        bool isValid() const;

    private:
        string street;
        unsigned int door_number;
        string floor;
        string zip_code;
        string city;
        bool isValidZipCode(string zip_code) const;
};