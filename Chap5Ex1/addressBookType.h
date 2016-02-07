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
  //addressBookType(linkedListType<extPersonType> listPerson);
  //last name search
  void bookSearch(std::string, extPersonType &outPerson, int &failState);
  void printPerson(std::string lastName);

  ////Add person to addressBook
  void Add(extPersonType &ept);
  //delete person from addressBook
  void Delete(extPersonType &ept);
  //operator overloads for convenience
  bool operator==(extPersonType &ept);
  bool operator!=(extPersonType &ept);

private:
  //override attempts:
  bool search(const Type& searchItem) const;
  void insertFirst(const Type& newItem);
  void insertLast(const Type& newItem);
  void deleteNode(const Type& deleteItem);
};

template<class Type>
bool addressBookType<Type>::search(const Type& searchItem) const { return true; }

template<class Type>
void addressBookType<Type>::insertFirst(const Type& newItem) { }

template<class Type>
void addressBookType<Type>::insertLast(const Type& newItem) { }

template<class Type>
void addressBookType<Type>::deleteNode(const Type& deleteItem) { }

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

//template<class Type>
//addressBookType<Type>::addressBookType(linkedListType<extPersonType> listPerson) : linkedListType<Type>(listPerson) { }

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
  nodeType<Type> *newNode; //pointer to create the new node

  newNode = new nodeType<Type>; //create the new node

  newNode->info = ept;  //store the new item in the node
  newNode->link = NULL;     //set the link field of newNode
  //to NULL

  if (first == NULL)  //if the list is empty, newNode is 
    //both the first and last node
  {
    first = newNode;
    last = newNode;
    count++;        //increment count
  }
  else    //the list is not empty, insert newNode after last
  {
    last->link = newNode; //insert newNode after last
    last = newNode; //make last point to the actual 
    //last node in the list
    count++;        //increment count
  }
}

template<class Type>
void addressBookType<Type>::Delete(extPersonType &ept) {
  nodeType<Type> *current; //pointer to traverse the list
  nodeType<Type> *trailCurrent; //pointer just before current
  bool found;

  if (first == NULL)    //Case 1; the list is empty. 
    cout << "Cannot delete from an empty list."
    << endl;
  else
  {
    if (first->info == ept) //Case 2 
    {
      current = first;
      first = first->link;
      count--;
      if (first == NULL)    //the list has only one node
        last = NULL;
      delete current;
    }
    else //search the list for the node with the given info
    {
      found = false;
      trailCurrent = first;  //set trailCurrent to point
      //to the first node
      current = first->link; //set current to point to 
      //the second node

      while (current != NULL && !found)
      {
        if (current->info != ept)
        {
          trailCurrent = current;
          current = current->link;
        }
        else
          found = true;
      }//end while

      if (found) //Case 3; if found, delete the node
      {
        trailCurrent->link = current->link;
        count--;

        if (last == current)   //node to be deleted 
          //was the last node
          last = trailCurrent; //update the value 
        //of last
        delete current;  //delete the node from the list
      }
      else
        cout << "The item to be deleted is not in "
        << "the list." << endl;
    }//end else
  }//end else
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