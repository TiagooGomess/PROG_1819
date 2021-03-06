
#include "Date.h"
#include "Pack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Pack::Pack(){
    vector<string> v;
    Date date("2019/01/01");
    this->id = 0;
    this->places = v;
    this->beginning_date = date;
    this->end_date = date;
    this->price_per_person = 0.0;
    this->max_num_people = 0;
    this->already_sold = 0;
}

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
    out << "[Id]: " << pack.id << endl;
    string temp = "";
    for (size_t i = 0; i < pack.places.size(); i++)
        temp += pack.places.at(i) + ", ";
    temp = temp.substr(0, temp.size()-2);
    out << "[Locais a visitar]: " << temp << endl << "[Data de inicio]: " << pack.beginning_date << endl << "[Data de fim]: " << pack.end_date << endl << "[Preco por pessoa]: " << to_string(pack.price_per_person) << endl << "[Numero total de vagas]: " << to_string(pack.max_num_people) << endl << "[Numero de vagas ja ocupadas}: " << to_string(pack.already_sold) << endl;
    return out;
}