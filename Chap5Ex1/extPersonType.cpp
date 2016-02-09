#ifndef ExtPersonType_S
#define ExtPersonType_S
#include <string>
#include <iostream>
#include <regex>
#include "StringCharIntUtil.h"
#include "RelationType.h"
#include "extPersonType.h"
#include "personType.h"
using namespace std;

extPersonType::extPersonType()
: personType()
{
  relation = RelationType::NoRelation;
  for (int i = 0; i < 10; i++)
    Phone[i] = 0;
  Address = addressType();
  birthDate = dateType();
}
extPersonType::extPersonType(string firstName, string lastName, string address) : personType(firstName, lastName) {
  Address = addressType();
  Address.setStreetAddress(address);
  relation = RelationType::NoRelation;
}
extPersonType::extPersonType(std::string relationParam, std::string phoneParam, std::string firstName, std::string lastName) :
personType(firstName, lastName)
{
  relation = RelationStringToEnum(relationParam);
  stringPhone = phoneParam;
  storeStringPhone(phoneParam);
  Address = addressType();
  birthDate = dateType();
}
string extPersonType::relationNames[3] = { { "friend" }, { "family member" }, { "business associate" } };

void extPersonType::loadAddress(addressType addr) {
  Address = addr;
}

void extPersonType::loadBirthDate(dateType dt) {
  birthDate = dt;
}

RelationType extPersonType::RelationStringToEnum(string rel) {
  if (rel == relationNames[0] || rel == relationNames[1] || rel == relationNames[2]) {
    if (rel == relationNames[0])
      return RelationType::Friend;
    else if (rel == relationNames[1])
      return RelationType::FamilyMember;
    else if (rel == relationNames[2])
      return RelationType::BusinessAssociate;
    else {
      cerr << "No matching Relation Type" << endl;
      return RelationType::NoRelation;
    }
  }
  else {
    cerr << "No matching Relation Type" << endl;
    return RelationType::NoRelation;
  }
}
void extPersonType::storeStringPhone(string phoneStr) {
  for (int i = 0; i < 10; i++) {
    Phone[i] = Convert::ToInteger(phoneStr[i]);
  }
}
void extPersonType::print() {
  personType::print();
  cout << " " << relationNames[relation];
  cout << " born: " << birthDate.getMonth() << "."
    << birthDate.getDay() << "." << birthDate.getYear();
  cout << " " << GetPhone(true) << endl;
  cout << "address: ";
  if (Address.GetCity() == "" || Address.GetState() == "")
    Address.printStrtAddress();
  else
    Address.PrintFullAddress();
}
//method does everything as expected in debugging!
//memory is somehow being overwritten???
//pointers don't seem to help
string extPersonType::GetPhone() {
  stringPhone = "";
  for (int i = 0; i < 10; i++) {
    string tmp = "" + Phone[i];
    (stringPhone) += tmp;
  }
  return (stringPhone);
}
//bleh
string extPersonType::GetPhone(bool useTemp) {
  if (useTemp)
    return stringPhone;
  else
    return GetPhone();
}
dateType extPersonType::getDate() {
  return birthDate;
}
void extPersonType::setPhone(string phone, bool convert) {
  if (convert) {
    storeStringPhone(phone);
    stringPhone = phone;
  }
  else
    stringPhone = phone;
}
addressType extPersonType::getextAddress() {
  return Address;
}
#endif