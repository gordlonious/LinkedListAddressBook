#ifndef ExtPersonType_H
#define ExtPersonType_H
#include <string>
#include <array>
#include "personType.h"
#include "date.h"
#include "addressType.h"
#include "RelationType.h"

class extPersonType : public personType {
public:
  extPersonType();
  extPersonType(std::string relation, std::string phone, std::string firstName, std::string lastName);
  std::string GetPhone();
  std::string GetPhone(bool useTemp);
  dateType getDate();
  void setPhone(std::string phone, bool convert = false);
  void loadAddress(addressType);
  void loadBirthDate(dateType);
  void print();
  friend bool operator==(extPersonType &eptLeft, extPersonType &eptRight);
  RelationType relation;
private:
  static std::string relationNames[3];
  RelationType RelationStringToEnum(std::string);
  int Phone[10];
  std::string stringPhone; //please don't destroy me... string pointers not working..
  addressType Address;
  dateType birthDate;
  void storeStringPhone(std::string);
};

//bool operator==(const extPersonType &eptLeft, const extPersonType &eptRight) {
//  bool equals = false;
//  //currently no way to set values of private variables after construction..
//  //proceeding with just name checks
//  int checks = 0;
//  if (eptLeft.getFirstName() == eptRight.getFirstName())
//    checks++;
//  if (eptLeft.getLastName() == eptRight.getLastName())
//    checks++;
//  if (checks == 2)
//    equals = true;
//  return equals;
//}
#endif