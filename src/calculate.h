#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

struct Node_data {
  double value;
};

class Checks {
 public:
  Checks() = default;
  ~Checks() = default;

  int check_number(char value);
  int check_operator(char value);
  int check_funcs(char value);
  int check_input(string vlaue);

 private:
  string digit_symbols = "0123456789";
  string operator_symbols = "+-*/=()^.";
  string str_symbols = "sincoatqrlgmd";
  map<string, int> math_symbols{
      {"COS", 11},  {"SIN", 12},  {"TAN", 13}, {"ACOS", 14}, {"ASIN", 15},
      {"ATAN", 16}, {"SQRT", 17}, {"LN", 18},  {"LOG", 19},  {"MOD", 2}};
};