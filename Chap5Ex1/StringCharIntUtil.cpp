#ifndef StringCharIntUtil
#define StringCharIntUtil
#include <iostream>
#include <string>
#include "StringCharIntUtil.h"
using namespace std;

int Convert::ToInteger(char c) {
  return c - '0';
}
#endif // !StringCharIntUtil
