#ifndef date_H
#define date_H

//************************************************************
// Author: D.S. Malik
// 
// class dateType
// This class specifies the members to implement a date.
//************************************************************
#include<array>

class dateType
{
public:
    void setDate(int month, int day, int year);
      //Function to set the date.
      //The member variables dMonth, dDay, and dYear are set 
      //according to the parameters.
      //Postcondition: dMonth = month; dDay = day; dYear = year

    int getDay() const;
      //Function to return the day.
      //Postcondition: The value of dDay is returned.

    int getMonth() const;
      //Function to return the month.  
      //Postcondition: The value of dMonth is returned.

    int getYear() const;
      //Function to return the year.     
      //Postcondition: The value of dYear is returned.

    int setDay(int);
    int setMonth(int);
    int setYear(int);
    static const int MonthDayTotal[];
    int getDaysInMonth();
    int daysPassed();
    int daysRemaining();
    void addDays(int);

    void printDate() const;
      //Function to output the date in the form mm-dd-yyyy.

    dateType(int month = 1, int day = 1, int year = 1900);
      //Constructor to set the date
      //The member variables dMonth, dDay, and dYear are set 
      //according to the parameters.
      //Postcondition: dMonth = month; dDay = day; dYear = year. If
      //    no values are specified, the default values are used to
      //    initialize the member variables.
      //    ADDED BY GORDON PORTZLINE
      //    month must be 1-12
      //    day must be 1-31
      //    year must not be negative
    bool isLeapYear();

private:
    int dMonth; //variable to store the month
    int dDay;   //variable to store the day
    int dYear;  //variable to store the year
};



#endif