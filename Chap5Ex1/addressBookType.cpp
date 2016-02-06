#ifndef addressBookType_S
#define addressBookType_S
#include <iostream>
#include <string>
#include <vector>
#include "linkedList.h"
#include "addressBookType.h"
#include "extPersonType.h"

template<class Type>
addressBookType<Type>::addressBookType() { }

template<class Type>
addressBookType<Type>::addressBookType(unorderedLinkedList<extPersonType> listPerson) : unorderedLinkedList<Type>(listPerson) { }

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
void addressBookType<Type>::testMethod(string s) { }

template<class Type>
void addressBookType<Type>::printPerson(string lastName) { }
//void addressBookType<extPersonType>::printPerson(string lastName) {
//  extPersonType foundPerson = extPersonType();
//  int searchFail = -1;
//  //bookSearch(lastName, foundPerson, searchFail);
//  if (searchFail != -1)
//    foundPerson.print();
//  else
//    cerr << "Could not find person to print" << endl;
//}
//void addressBookType::printPerson(int month) {
//  vector<int> indices = vector<int>();
//  searchDate(indices, 3);
//  for (unsigned int i = 0; i < indices.size(); i++) {
//    extPersonType temp;
//    retrieveAt(indices[i], temp);
//    temp.print();
//  }
//}
//between dates
//void addressBookType::printPerson(dateType dtBeg, dateType dtEnd) {
//  for (int i = 0; i < arrayListType::length; i++) {
//    bool beginningFound = false;
//    if (arrayListType::list[i].getDate().getYear() > dtBeg.getYear() && arrayListType::list[i].getDate().getYear() < dtEnd.getYear())
//      arrayListType::list[i].print();
//    else if (arrayListType::list[i].getDate().getMonth() > dtBeg.getMonth() && arrayListType::list[i].getDate().getMonth() < dtEnd.getMonth()) {
//      arrayListType::list[i].print();
//    }
//    else if (arrayListType::list[i].getDate().getDay() > dtBeg.getDay() && arrayListType::list[i].getDate().getDay() < dtBeg.getDay()) {
//      arrayListType::list[i].print();
//    }
//  }
//}
//void addressBookType::searchDate(vector<int> &indexVec, int month, int day, int year) {
//  if (month != -1 && day != -1 && year != -1) {
//    //search full date
//    int full = 0;
//    for (int i = 0; i < arrayListType::length; i++) {
//      if (arrayListType::list[i].getDate().getMonth() == month)
//        full++;
//      else if (arrayListType::list[i].getDate().getDay() == day)
//        full++;
//      else if (arrayListType::list[i].getDate().getYear() == year)
//        full++;
//      if (full == 3)
//        indexVec.push_back(i);
//    }
//    if (full != 3)
//      cerr << "no date entry was found (searchDate())" << endl;
//  }
//  else //search for month
//  for (int i = 0; i < arrayListType::length; i++) {
//    if (arrayListType::list[i].getDate().getMonth() == month)
//      indexVec.push_back(i);
//  }
//}
//void addressBookType::printPerson(RelationType rt) {
//  for (int i = 0; i < arrayListType::length; i++) {
//    if (arrayListType::list[i].relation == rt)
//      arrayListType::list[i].print();
//  }
//}
//void addressBookType::printPerson(string lastStart, string lastEnd) {
//  //relying on character encodings..
//  //must be lower case
//  if (lastStart[0] < 97 || lastStart[0] > 122)
//    cerr << "must be lower case (printPerson())" << endl;
//  else if (lastEnd[0] < 97 || lastEnd[0] > 122)
//    cerr << "must be lower case (printPerson())" << endl;
//  else {
//    for (int i = 0; i < arrayListType::length; i++) {
//      if (arrayListType::list[i].getLastName()[0] > lastStart[0] && arrayListType::list[i].getLastName()[0] < lastEnd[0])
//        arrayListType::list[i].print();
//    }
//  }
  //all possible solutions I could think of were O(n^4)/(n^3 + 2n) or something!!
  //reverting to first char comparisons
  //still within direction parameters..
//}
#endif