
//************************************************************
// Author: D.S. Malik
// 
// Implemenation file personType
//************************************************************
#ifndef PersonType_S
#define PersonType_S

#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

void personType::print() const
{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

    //Default constructor
personType::personType() 
{ 
    firstName = "";
    lastName = "";
}

    //Constructor with parameters
personType::personType(string first, string last) 
{ 
    firstName = first;
    lastName = last;
}

#endif

