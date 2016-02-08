#include <iostream>
#include "addressType.h"
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include "date.h"
#include "linkedList.h"
#include "addressBookType.h"
using namespace std;

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
    //getline acting up
    //activate stream exceptions
    ////ifstream stream;
    ////cin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    //try{
    //  cin.exceptions(ios_base::badbit | ios_base::failbit);
    //  getline(cin, strtAddr);
    //}
    //catch (ios_base::failure &err) {
    //  cerr << err.what() << endl;
    //  throw;
    //}

    //Using code from internet! URL:  http://stackoverflow.com/questions/10553597/cin-and-getline-skipping-input
    //"If you're using getline after cin >> something, you need to flush the newline out of the buffer"
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, strtAddr);
    bool test = cin.bad();
    bool test2 = cin.fail();
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
  addressBookType<extPersonType> abt1 = addressBookType<extPersonType>();
  requestEntries(abt1);
  cout << endl << "printing entry..." << endl;
  for (extPersonType ept : abt1)
    ept.print();
  char stop;
  cin >> stop;
}