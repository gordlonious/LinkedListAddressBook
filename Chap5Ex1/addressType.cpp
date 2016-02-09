#ifndef AddressType
#define AddressType
#include <string>
#include <iostream>
#include <vector>
#include "addressType.h"
#include "StringCharIntUtil.h"
using namespace std;

addressType::addressType() {
  strtAddress = "";
  city = "";
  //wishing for alternate initialization here
  state[0] = '!';
  state[1] = '!';
  zip[0] = -1;
  zip[1] = -1;
  zip[2] = -1;
  zip[3] = -1;
  zip[4] = -1;
}
addressType::addressType(string address, string cityParam, string stateParam, string zipCode) {
  strtAddress = address;
  city = cityParam;
  storeStringState(stateParam);
  storeStringZip(zipCode);
}
string addressType::GetAddress() {
  return strtAddress;
}
string addressType::GetCity() {
  return city;
}
string addressType::GetState() {
  return stateToString();
}
string addressType::GetZip() {
  return zipToString();
}
string addressType::stateToString() {
  string st = "";
  for (char c : state)
    st += c;
  return st;
}
string addressType::zipToString() {
  string zp = "";
  for (int i : zip) {
    if (i == -1)
      zp += '!';
    else
      zp += i;
  }
  return zp;
}
void addressType::storeStringZip(string zipParam) {
  for (int i = 0; i < 5; i++) {
    if ((Convert::ToInteger(zipParam[i])) >= 0 && (Convert::ToInteger(zipParam[i])) <= 9)
      zip[i] = zipParam[i];
    else
      cerr << "func: storeStringZip " << "err: Invalid Zip Code " << "obj: " << "addressType" << endl;
  }
}
void addressType::storeStringState(string stateParam) {
  for (int i = 0; i < 2; i++) {
    if (isalpha(stateParam[i]))
      state[i] = stateParam[i];
    else
      cerr << "func: storeStringState " << "err: Invalid State Abbreviation " << "obj: " << "addressType" << endl;
  }
}
void addressType::printStrtAddress() {
  if (strtAddress != "")
    cout << strtAddress;
  else
    cerr << "strt address is not defined";
}
void addressType::PrintFullAddress() {
  if (strtAddress != "" && city != "" && zipString != "" && stateString != "")
    cout << GetAddress() << " " << GetCity() << " " << stateToString() << " " << zipToString() << endl;
  else if (strtAddress == "" && city != "" && zipString != "" && stateString != "")
    cout << "No street address found" << " " << GetCity() << " " << stateToString() << " " << zipToString() << endl;
  else if (strtAddress == "" && city == "" && zipString != "" && stateString != "")
    cout << "No street address found" << " " << "No City found" << " " << stateToString() << " " << zipToString() << endl;
  else if (strtAddress == "" && city == "" && zipString == "" && stateString != "")
    cout << "No street address found" << " " << "No City found" << " " << "No State found" << " " << zipToString() << endl;
  else if (strtAddress == "" && city == "" && zipString == "" && stateString == "")
    cout << "No address information found" << endl;
  else
    cerr << "PrintFullAddress has failed " << endl;

}
void addressType::setCity(string cityParam) {
  city = cityParam;
}
void addressType::setStreetAddress(string strtAddrParam) {
  strtAddress = strtAddrParam;
}
void addressType::setZip(string zipParam, bool convert) {
  if (convert) {
    storeStringZip(zipParam);
    zipString = zipParam;
  }
  else
    zipString = zipParam;
}
void addressType::setState(string st, bool convert) {
  if (convert) {
    storeStringState(st);
    stateString = st;
  }
  else
    stateString = st;
}
#endif