#ifndef StringCharIntUtil_H
#define StringCharIntUtil_H
#include <string>

class Convert {
public:
  static int ToInteger(char);
  //finds the first occurence of an integer and returns it as a c++ int
  //else returns -1
  static int ToIntegerFirst(std::string);
  //adds all occurences of integers in the string and returns it
  //if only one is found that value is returned
  //else returns -1
  static int toIntegerAll(std::string);
};
#endif // !StringCharIntUtil_H
