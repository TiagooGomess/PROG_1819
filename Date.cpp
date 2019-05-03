
#include "Date.h"
#include "aux_funcs.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Date::Date(){
    this->year = 2000;
    this->month = 1;
    this->day = 1;
}

Date::Date(string date){
    vector<string> separated_date = separate_string(date, '/');
    vector<int> date_fields = convert_vector_str_to_int(separated_date);
    this->year = date_fields.at(0);
    this->month = date_fields.at(1);
    this->day = date_fields.at(2);
}

Date::Date(unsigned short int day, unsigned short int month, unsigned int year){
    this->year = year;
    this->month = month;
    this->day = day;
}

unsigned short int Date::getDay() const{
    return this->day;
}

unsigned short int Date::getMonth() const{
    return this->month;
}

unsigned int Date::getYear() const{
    return this->year;
}

void Date::setDay(unsigned short int day){
    this->day = day;
}

void Date::setMonth(unsigned short int month){
    this->month = month;
}

void Date::setYear(unsigned int year){
    this->year = year;
}

ostream& operator<<(ostream& out, const Date & date){
    out << date.year << "/" << date.month << "/" << date.day;
}