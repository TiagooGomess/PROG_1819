
#include "Date.h"
#include "aux_funcs.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

Date::Date(){
    this->year = 2000;
    this->month = 1;
    this->day = 1;
}

Date::Date(string date){
    vector<string> separated_date = separate_string(date, '/');
    vector<int> date_fields = convert_vector_str_to_int(separated_date);
    this->year = date_fields.at(2);
    this->month = date_fields.at(1);
    this->day = date_fields.at(0);
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
	out << setfill('0') << setw(2) << date.day << "/" << setfill('0') << setw(2) << date.month << "/" << setfill('0') << setw(4) << date.year;
}

bool operator<(const Date first_date, const Date second_date){
    if (first_date.year < second_date.year)
        return true;
    else if (first_date.year > second_date.year)
        return false;
    else {
        if (first_date.month < second_date.month)
            return true;
        else if (first_date.month > second_date.month)
            return false;
        else {
            if (first_date.day < second_date.day)
                return true;
            else if (first_date.day >= second_date.day)
                return false;
        }
    }
}

unsigned int Date::numDays(unsigned int m, unsigned int y) const{
    if (is_leap_year(y) && month == 2)
        return 29;
    else if (!is_leap_year(y) && month == 2)
        return 28;
    else {
        switch (m){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
                break;
            case 4: case 6: case 9: case 11:
                return 30;
                break; 
        }
    }
}

bool Date::isValid() const{
    unsigned int num_of_days = numDays(this->month, this->year);
    if (this->month > 0 && this->month < 13 && this->day > 0 && this->day <= num_of_days)
        return true;
    return false;
}