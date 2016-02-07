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
  cout << "Last name:  ";
  cin >> lName;
  abt.setName(fName, lName);
  string phone;
  cout << "Phone number:  ";
  cin >> phone;
  abt.setPhone(phone);
  char contCin;
  cout << "Continue with address info?  ";
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

void requestEntries(addressBookType<extPersonType>& abt) {
  bool stop = false;
  while (!stop) {
    extPersonType entry = extPersonType();
    requestFullInfo(entry);
    abt.Add(entry);
    char another;
    cout << "Add another entry? Y || N  " << endl;
    cin >> another;
    if (another != 'Y' && another != 'y')
      stop = true;
  }
}

int main() {
  
  cout << endl << "printing entry..." << endl;
  char stop;
  cin >> stop;
}