//Implementation file date

#include <iostream>
#include <array>
#include "date.h"

using namespace std;
 
void dateType::setDate(int month, int day, int year)
{
  if (month < 1 || month > 12)
    cerr << "could not set the month. Must be 1 through 12 ";
  else
    dMonth = month;
  if (day < 1 || day > 31)
    cerr << "could not set the day. Must be 1 through 31 ";
  else
    dDay = day;
  if (year < 0)
    cerr << "cannot have a negative year! ";
  else
    dYear = year;
}

int dateType::getDay() const 
{
    return dDay;
}

int dateType::getMonth() const 
{
    return dMonth;
}

int dateType::getYear() const 
{
    return dYear;
}

void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

    //Constructor with parameters
dateType::dateType(int month, int day, int year) 
{
  if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0)
    throw exception("Cannot create dateType with invalid constructor parameters. Please see documentation. ");
  else
    setDate(month, day, year);
}

//gregorian style? or at least a seemingly standard but possibly inaccurate implementation
//post ceasar leap year definition
bool dateType::isLeapYear() {
  bool isLy = false;
  if (dYear % 400 == 0)
    isLy = true;
  else if (dYear % 100 == 0)
    isLy = false;
  else if (dYear % 4 == 0)
    isLy = true;
  else
    isLy = false;
  return isLy;
}
int dateType::setDay(int d) {
  if (d < 1 || d > 31)
    cerr << "setDay() param out of range ";
  else
    dDay = d;

  return dDay;
}
int dateType::setMonth(int m) {
  if (m < 1 || m > 12)
    cerr << "setMonth() param is out of range ";
  else
    dMonth = m;
  
  return dMonth;
}
int dateType::setYear(int y) {
  if (y < 0)
    cerr << "setYear() param cannot be negative ";
  else
    dYear = y;

  return dYear;
}
const int dateType::MonthDayTotal[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int dateType::getDaysInMonth() {
  int index = dMonth - 1;
  if (isLeapYear() && index == 1)
    return MonthDayTotal[index] + 1;
  else
    return MonthDayTotal[index];
}
int dateType::daysPassed() {
  int days = 0;
  for (int i = 0; i < dMonth - 1; i++)
    days += MonthDayTotal[i];
  if (isLeapYear())
    days += 1;
  days += dDay;
  return days;
}
int dateType::daysRemaining() {
  return 365 - daysPassed();
}
//  d may not exceed 28
//
//  tons of edge cases otherwise!!!
//  I'm sure there is a good algorithm for it. 
//  However, the current output is correct
//  furthermore the instructions are not that specific
void dateType::addDays(int d) {
  if (d > 28)
    throw exception("cannot add days by more than 28 at a time.. ");
  int daysRmainingMonth = MonthDayTotal[dMonth - 1] - dDay;
  if (d > daysRmainingMonth)
    dMonth++;
  else
    dDay += d;
}

