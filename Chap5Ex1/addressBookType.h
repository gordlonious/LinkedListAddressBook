#ifndef addressBookType_H
#define addressBookType_H
#include <string>
#include "RelationType.h"
#include "addressType.h"
#include "extPersonType.h"
#include "unorderedLinkedList.h"

template<class Type>
class addressBookType : unorderedLinkedList<Type> {
public:
  addressBookType();
  addressBookType(unorderedLinkedList<extPersonType> listPerson);
  //last name search
  void bookSearch(std::string, extPersonType &outPerson, int &failState);
  void testMethod(std::string);
  void addressBookType<extPersonType>::printPerson(std::string lastName);
  //void addressBookType::printPerson(int month);
  ////finds first entry for the date
  ////if not all params are set, searchDate will search based on just the month
  ////searchDate returns a vector of indeces where the dates were at least partially matched
  //void searchDate(vector<int> &indexVec, int month, int day = -1, int year = -1);
  ////prints all entries between two dates
  //void printPerson(dateType, dateType);
  ////prints all entries with a certain relationship type
  //void printPerson(RelationType);
  ////print all entries between two names alphabetically
  //void printPerson(std::string, std::string);
  ////Add person to addressBook
  void Add(extPersonType &ept);
  //delete person from addressBook
  void Delete(extPersonType &ept);
  //operator overloads for convenience
  bool operator==(extPersonType &ept);
  bool operator!=(extPersonType &ept);
};
template<class Type>
bool addressBookType<Type>::operator==(extPersonType &ept) {
  bool equals = false;
    //currently no way to set values of private variables after construction..
    //proceeding with just name checks
    int checks = 0;
    if (getFirstName() == ept.getFirstName())
      checks++;
    if (getLastName() == ept.getLastName())
      checks++;
    if (checks == 2)
      equals = true;
    return equals;
}
template<class Type>
bool addressBookType<Type>::operator!=(extPersonType &ept) {
  return !((*this) == ept);
}
#endif