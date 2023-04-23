#include "calculate.h"

int Checks::check_number(char value) {
  return digit_symbols.find(value) != string::npos;
}
int Checks::check_operator(char value) {
  return operator_symbols.find(value) != string::npos;
}
int Checks::check_funcs(char value) {
  // {"COS", 11},  {"SIN", 12},  {"TAN", 13}, {"ACOS", 14}, {"ASIN", 15},
  //     {"ATAN", 16}, {"SQRT", 17}, {"LN", 18},  {"LOG", 19},  {"MOD", 2}};

  return math_sympols.find(value) != string::npos;
}
int Checks::check_input(string vlaue) {
  int valid_operator = 0;
  int scopes = 0;
  unsigned int math_symb = 0;
  for (auto &i : vlaue) {
    if (!check_number(i) && !check_operator(i) && !check_funcs(i)) return 0;
    if (check_number(i)) valid_operator = 0;
    if (check_funcs(i)) {
      ++math_symb;
      --valid_operator;
    };
    if (check_operator(i) && valid_operator) return 0;
    if (check_operator(i)) {
      if (i == '(') {
        if (math_symb) --math_symb;
        ++scopes;
      } else if (i == ')') {
        --scopes;
      } else {
        ++valid_operator;
      }
    }
  }
  if (valid_operator || scopes || math_symb) return 0;
  return 1;
}