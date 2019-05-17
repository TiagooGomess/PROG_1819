

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
  unsigned int numDays(unsigned int m, unsigned int y) const;

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
  friend bool operator<(const Date first_date, const Date second_date);
  bool isValid() const;

};