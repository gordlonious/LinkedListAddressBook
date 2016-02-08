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
  cout << "Phone number (no spaces, only digits):  ";
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
    cout << endl << "Please enter your address in 5 parts ";
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
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //getline(cin, strtAddr);

    //process address as 4 parts
    //strt#, direction, strtName and suite or apartment #
    string strtNum;
    cout << endl << "Part 1 (street number):  ";
    cin >> strtNum;
    string direction;
    cout << endl << "Part 2 (direction i.e. E, N, S, W):  ";
    cin >> direction;
    string strtName;
    cout << endl << "Part 3 (street name i.e. smith or 7th):  ";
    cin >> strtName;
    string strtType;
    cout << endl << "Part 4 (street type i.e. st, ave..):  ";
    cin >> strtType;
    string suite;
    cout << endl << "Part 5 (suite or apartment number, may leave blank):  ";
    cin >> suite;

    //all 4 parts separated with !
    //allows me to process the street address from the file more easily
    strtAddr = strtNum + '!' + direction + '!' + strtName + '!' + strtType + '!' + suite;

    //set address in address object
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

void loadEntry(fstream &book, string (&outLine)[3]) {
  string data[3];
  int item = 0;
  for (int i = 0; i < 3; i++) {
    while (book.get() != ' ') {
      if (book.get() == '!')
        data[i][item] = ' ';
      else
        data[i][item] = book.get();

      item++;
    }
  }
  outLine[0] = data[0];
  outLine[1] = data[1];
  outLine[2] = data[2];
}

void loadEntries(addressBookType<extPersonType> &abt) {
  fstream book;
  book.open("addressBook.txt");
  string data[3];
  if (book.is_open()) {
    loadEntry(book, data);
  }
  else
    cerr << "loading data failed";

  abt.Add(extPersonType(data[0], data[1], data[2]));
}


// MAIN
// GORDON PORTZLINE
// CS III
int main() {
  //load stored entries
  char load;
  cout << "Would you like to see the current address book? (Y or N):  ";
  cin >> load;
  addressBookType<extPersonType> abtCurrent = addressBookType<extPersonType>();
  if (load == 'Y' || load == 'y') {
    loadEntries(abtCurrent);
  }

  //add new entries
  addressBookType<extPersonType> abt1 = addressBookType<extPersonType>();
  requestEntries(abt1);
  //print new entries
  cout << endl << "printing entry..." << endl;
  for (extPersonType ept : abt1)
    ept.print();
  //save new entries
  abt1.saveData();

  //stop the program
  cout << "please input character a-z or 0-9 to end the program...";
  char stop;
  cin >> stop;
}