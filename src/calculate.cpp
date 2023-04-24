#include "calculate.h"

int Checks::number_check(char value) {
  return digit_symbols.find(value) != string::npos;
}
int Checks::operator_check(char value) {
  return operator_symbols.find(value) != string::npos;
}
int Checks::funcs_check(char value) {
  // {"COS", 11},  {"SIN", 12},  {"TAN", 13}, {"ACOS", 14}, {"ASIN", 15},
  //     {"ATAN", 16}, {"SQRT", 17}, {"LN", 18},  {"LOG", 19},  {"MOD", 2}};

  return math_sympols.find(value) != string::npos;
}
int Checks::input_check(string vlaue) {
  int valid_operator = 0, scopes = 0, math_symb = 0, is_pre_num = 0, close = 0;
  for (auto &i : vlaue) {
    if (!number_check(i) && !operator_check(i) && !funcs_check(i)) return 0;
    if (number_check(i)) {
      if (close) return 0;
      valid_operator = 0, ++is_pre_num;
    }
    if (funcs_check(i)) {
      ++math_symb, --valid_operator;
    }
    if (operator_check(i)) {
      if (i == '(') {
        if (is_pre_num) return 0;
        if (math_symb) --math_symb;
        ++scopes;
      } else if (i == ')' && !valid_operator) {
        --scopes, ++close;
      } else {
        if (valid_operator) return 0;
        ++valid_operator, close = 0;
      }
      is_pre_num = 0;
    }
  }
  if (valid_operator || scopes || math_symb) return 0;
  return 1;
}