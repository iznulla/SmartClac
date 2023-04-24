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

  int number_check(char value);
  int operator_check(char value);
  int funcs_check(char value);
  int first_item(char value);
  int input_check(string vlaue);

 private:
  string digit_symbols = "0123456789";
  string operator_symbols = "+-*/()^.%";
  // string str_symbols = "sincoatqrlgmd";
  map<string, int> math_preorites{
      {"cos", 11},  {"sin", 12},  {"tan", 13}, {"acos", 14}, {"asin", 15},
      {"atan", 16}, {"sqrt", 17}, {"ln", 18},  {"log", 19},  {"mod", 2}};
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  string math_sympols = "!@#$_vbup";
};