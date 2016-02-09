#ifndef AddressType_H
#define AddressType_H
#include <string>
#include <vector>

class addressType {
public:
  addressType();
  addressType(std::string, std::string, std::string, std::string);
  std::string GetAddress();
  std::string GetCity();
  std::string GetState();
  std::string GetZip();
  void setCity(std::string city);
  void setZip(std::string, bool convert = false);
  void setState(std::string, bool convert = false);
  void setStreetAddress(std::string strtAddress);
  void printStrtAddress();
  void PrintFullAddress();
  //i --  load from disk
  //void Load(vector<extPersonType>*);

private:
  std::string strtAddress;
  std::string city;
  char state[2];
  std::string stateString;
  int zip[5];
  std::string zipString;
  std::string stateToString();
  std::string zipToString();
  void storeStringZip(std::string);
  void storeStringState(std::string);
};
#endif // !AddressType_H
