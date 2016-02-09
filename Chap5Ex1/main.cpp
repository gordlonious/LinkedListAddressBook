#include <iostream>
#include <sstream>
#include <istream>
#include <vector>
#include "addressType.h"
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include "date.h"
#include "linkedList.h"
#include "addressBookType.h"
using namespace std;

fstream bookStream;

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
  abt.setPhone(phone, true);
  char contCin;
  cout << "Continue with address info? (Y or N):  ";
  cin >> contCin;
  if (contCin == 'Y' || contCin == 'y') {
    addressType addr;
    string city;
    cout << endl << "City:  ";
    cin >> city;
    addr.setCity(city);
    string st;
    cout << endl << "State:  ";
    cin >> st;
    addr.setState(st);
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

void loadEntry(fstream &book, string(&outLine)[3]) {
  string data[3];
  //I DON'T KNOW MUCH ABOUT FILES
  //http://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
  //new lines will be skipped unless we stop it from happening :
  book.unsetf(std::ios_base::skipws);
  // count the newlines with an algorithm specialized for counting:
  unsigned line_count = std::count(
    std::istream_iterator<char>(book),
    std::istream_iterator<char>(),
    '\n');
  for (unsigned int j = 0; j < line_count; j++) {
    for (int i = 0; i < 3; i++) {
      //cin.ignore();
      string line;
      std::getline(book, line);
      //turn line into an array of strings
      string buf; // Have a buffer string
      stringstream ss(line); // Insert the string into a stream

      vector<string> tokens; // Create vector to hold our words

      while (ss >> buf)
        tokens.push_back(buf);
      //sort through each char
      for (unsigned int k = 0; k < line.size(); k++) {
        if (line[k] == ' ')
          break;
        if (line[k] == '!') {
          string *item = &data[i];
          (*item) += ' ';
        }
        else {
          string *item = &data[i];
          (*item) += line[k];
        }
      }
    }
  }
  outLine[0] = data[0];
  outLine[1] = data[1];
  outLine[2] = data[2];
}

void loadTest(fstream &book, vector<vector<string>> &data, int &entryCount) {

  //http://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
  //new lines will be skipped unless we stop it from happening :
  book.unsetf(std::ios_base::skipws);
  // count the newlines with an algorithm specialized for counting:
  // gportzline: then reset the file stream
  unsigned line_count = std::count(
    std::istream_iterator<char>(book),
    std::istream_iterator<char>(),
    '\n');
  entryCount = line_count;
  //reset
  book.clear();
  book.seekg(0, std::ios::beg);

  //note that this constructor provides room for at LEAST 500 entries -- push_back allocates memory for each entry added after 500
  vector<vector<string>> currentAB = vector<vector<string>>(500);  //make sure there is room for at least 500 entries
  for (unsigned int j = 0; j < line_count; j++) {
    string line;
    std::getline(book, line);
    //split line into 3 data pieces -- fname, lname and address (everything that is stored so far)
    string buf; // Have a buffer string
    stringstream ss(line); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    while (ss >> buf)
      tokens.push_back(buf);
    //make address data more readable
    for (unsigned int k = 0; k < tokens[2].size(); k++) {
      if (tokens[2][k] == '!')
        tokens[2][k] = ' ';
    }
    //prepare data for caller
    currentAB.insert(currentAB.begin(), tokens);
  }
  data = currentAB;
}

void loadEntries(addressBookType<extPersonType> &abt, string &loadState) {
  fstream book;
  book.open("addressBook.txt");
  int abEntryCount = -1;
  vector<vector<string>> abData;
  if (book.is_open()) {
    loadTest(book, abData, abEntryCount);
    //loadEntry(book, data);
  }
  else
    cerr << "loading data failed";
  if (abEntryCount != 0) {
    if (abEntryCount != -1) {
      for (int i = 0; i < abEntryCount; i++)
        abt.Add(extPersonType(abData[i][0], abData[i][1], abData[i][2]));
    }
    else {
      for (unsigned int i = 0; i < abData.size(); i++) {
        abt.Add(extPersonType(abData[i][0], abData[i][1], abData[i][2]));

      }
    }
  }
  else
    loadState = "There are no addresses in the database";
}


// MAIN
// GORDON PORTZLINE
// CS III
int main() {
  //load stored entries
  char load;
  cout << "Would you like to see the current address book? (Y or N):  ";
  cin >> load;
  if (load == 'Y' || load == 'y') {
    addressBookType<extPersonType> abtCurrent = addressBookType<extPersonType>();
    string dbState;
    loadEntries(abtCurrent, dbState);
    for (extPersonType ept : abtCurrent)
      ept.print();
  }

  char add;
  cout << endl << "Would you like to add more contacts to the address book? (Y or N):  ";
  cin >> add;
  if (add == 'Y' || add == 'y') {
    //add new entries
    addressBookType<extPersonType> abt1 = addressBookType<extPersonType>();
    requestEntries(abt1);
    //print new entries
    cout << endl << "printing entry..." << endl;
    for (extPersonType ept : abt1)
      ept.print();
    //save new entries
    abt1.saveData();
  }

  //stop the program
  cout << endl << "please input character a-z or 0-9 to end the program...";
  char stop;
  cin >> stop;
}