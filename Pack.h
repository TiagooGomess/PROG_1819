#pragma once

#include "Date.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pack{
 private:
  int id;
  vector<string> places;
  Date beginning_date;
  Date end_date;
  double price_per_person;
  unsigned int max_num_people;
  
 public:
  Pack(int id, vector<string> places, Date beginning_date, Date end_date, double price_per_person, unsigned int max_num_people);

  // Getters
  int getId() const;
  vector<string> getPlaces() const;
  Date getBeginningDate() const;
  Date getEndDate() const;
  double getPricePerPerson() const;
  unsigned int getMaxNumPeople() const;

  // Setters
  void setId(int id);  // to set negatve if "deprecated"
  void setPlaces(vector<string> places);
  void setBeginningDate(Date beginning_date);
  void setEndDate(Date end_date);
  void setPricePerPerson(double price_per_person);
  void setMaxNumPeople(unsigned int max_num_people);


  friend ostream& operator<<(ostream& out, const Pack & pack);
};