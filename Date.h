

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date{
 private:
  unsigned short int day;
  unsigned short int month;
  unsigned int year;

 public:
  Date();
  Date(string date);
  Date(unsigned short int day, unsigned short int month, unsigned int year);

  // Getters
  unsigned short int getDay() const;
  unsigned short int getMonth() const;
  unsigned int getYear() const;
  
  // Setters
  void setDay(unsigned short int day);
  void setMonth(unsigned short int month);
  void setYear(unsigned int year);

  
  friend ostream& operator<<(ostream& out, const Date & date);

};