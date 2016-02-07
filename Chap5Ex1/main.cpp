#include <iostream>
#include "addressType.h"
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include "date.h"
#include "linkedList.h"
#include "addressBookType.h"
using namespace std;

//template<class Type>
//static bool unorderedLinkedList<Type>::

//one out param that is the person to be added to the address book
void requestFullInfo(extPersonType &abt) {
  string fName;
  string lName;
  cout << "First name:  ";
  cin >> fName;
  cout << endl << "Last name:  ";
  cin >> lName;
  abt.setName(fName, lName);
  string phone;
  cout << "Phone number:  ";
  cin >> phone;
  abt.setPhone(phone);
  char contCin;
  cout << endl << "Continue with address info?  ";
  cin >> contCin;
  if (contCin == 'Y' || contCin == 'y') {
    addressType addr;
    string city;
    cout << endl << "City:  ";
    cin >> city;
    addr.setCity(city);
    string strtAddr;
    cout << endl << "Street address:  ";
    cin >> strtAddr;
    addr.setStreetAddress(strtAddr);
    string zip;
    cout << endl << "Zip code:  ";
    cin >> zip;
    addr.setZip(zip);
    string st;
    cout << endl << "State:  ";
    cin >> st;
    addr.setState(st);
    abt.loadAddress(addr);
  }
}

int main() {
  extPersonType entry1 = extPersonType();
  requestFullInfo(entry1);
  //addressBookType<extPersonType> abt1;
  //linkedListType<extPersonType> list;
  //unorderedLinkedList<extPersonType> testList = unorderedLinkedList<extPersonType>();
  /*addressBookType<extPersonType> abtPersons = addressBookType<extPersonType>();
  abtPersons.Add(entry1);*/
  //abtPersons.printPerson("portzline");
  char stop;
  cin >> stop;
}