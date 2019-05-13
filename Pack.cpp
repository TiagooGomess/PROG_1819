
#include "Date.h"
#include "Pack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Pack::Pack(int id, vector<string> places, Date beginning_date, Date end_date, double price_per_person, unsigned int max_num_people, unsigned int already_sold){
    this->id = id;
    this->places = places;
    this->beginning_date = beginning_date;
    this->end_date = end_date;
    this->price_per_person = price_per_person;
    this->max_num_people = max_num_people;
    this->already_sold = already_sold;
}

int Pack::getId() const{
    return this->id;
}

vector<string> Pack::getPlaces() const{
    return this->places;
}

Date Pack::getBeginningDate() const{
    return this->beginning_date;
}

Date Pack::getEndDate() const{
    return this->end_date;
}

double Pack::getPricePerPerson() const{
    return this->price_per_person;
}

unsigned int Pack::getMaxNumPeople() const{
    return this->max_num_people;
}

unsigned int Pack::getAlreadySold() const{
    return this->already_sold;
}

void Pack::setId(int id){
    this->id = id;
}

void Pack::setPlaces(vector<string> places){
    this->places = places;
}

void Pack::setBeginningDate(Date beginning_date){
    this->beginning_date = beginning_date;
}

void Pack::setEndDate(Date end_date){
    this->end_date = end_date;
}

void Pack::setPricePerPerson(double price_per_person){
    this->price_per_person = price_per_person;
}

void Pack::setMaxNumPeople(unsigned int max_num_people){
    this->max_num_people = max_num_people;
}

void Pack::setAlreadySold(unsigned int already_sold){
    this->already_sold = already_sold;
}

ostream& operator<<(ostream& out, const Pack & pack){
    out << pack.id << "  /  ";
    string temp = "";
    for (size_t i = 0; i < pack.places.size(); i++)
        temp += pack.places.at(i) + ", ";
    temp = temp.substr(0, temp.size()-2);
    out << temp << "  /  " << pack.beginning_date << "  /  " << pack.end_date << "  /  " << to_string(pack.price_per_person) << "  /  " << to_string(pack.max_num_people) << "  ";
    return out;
}