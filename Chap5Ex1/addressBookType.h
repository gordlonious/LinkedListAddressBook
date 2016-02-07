#ifndef addressBookType_H
#define addressBookType_H
#include <string>
#include "RelationType.h"
#include "addressType.h"
#include "extPersonType.h"
#include "linkedList.h"
#include "unorderedLinkedList.h"

template<class Type>
class addressBookType : public linkedListType<Type> {
public:
  addressBookType();
  addressBookType(linkedListType<extPersonType> listPerson);
  //last name search
  void bookSearch(std::string, extPersonType &outPerson, int &failState);
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

template<class Type>
addressBookType<Type>::addressBookType() : linkedListType<Type>() { }

template<class Type>
addressBookType<Type>::addressBookType(linkedListType<extPersonType> listPerson) : linkedListType<Type>(listPerson) { }

//sequential name search (by last name)
//returns the first occurence of the last name in the address book
//2 out parameters
//1st param: last name to search for
//2nd param: extPersonType object reference to write to if the last name is found in the book
//3rd param: error state reference to write to so the user knows whether or not to use 2nd out param
//3rd param: -1 indicates person not found, 0 indicates found
template<class Type>
void addressBookType<Type>::bookSearch(std::string lastName, extPersonType &outPerson, int &failState) {
  bool found = false;
  nodeType<extPersonType> *current = first;

  while (!found) {
    if (current->info.getLastName() == lastName) {
      found = true;
      outPerson = current->info;
      failState = 0;
    }
  }
  if (!found)
    failState = -1;
  else
    failState = 0;
}
template<class Type>
void addressBookType<Type>::Add(extPersonType &ept) {
  nodeType<extPersonType> newNode = nodeType<extPersonType>();
  newNode.link = NULL;
  last->link = *ept;
  newNode.info = ept;
  last = newNode;
}

template<class Type>
void addressBookType<Type>::printPerson(string lastName) {
  extPersonType foundPerson = extPersonType();
  int searchFail = -1;
  bookSearch(lastName, foundPerson, searchFail);
  if (searchFail != -1)
    foundPerson.print();
  else
    cerr << "Could not find person to print" << endl;
}
#endif