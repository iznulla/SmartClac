#include "calculate.h"

int Checks::check_number(char value) {
  return digit_symbols.find(value) != string::npos;
}
int Checks::check_operator(char value) {
  return operator_symbols.find(value) != string::npos;
}
int Checks::check_funcs(char value) {
  return str_symbols.find(value) != string::npos;
}
int Checks::check_input(string vlaue) {
  int valid_operator = 0;
  for (auto &i : vlaue) {
    if (!check_number(i) && !check_operator(i)) return 0;
    if (check_number(i)) valid_operator = 0;
    if (check_operator(i) && valid_operator) return 0;
    if (check_operator(i)) ++valid_operator;
  }
  if (valid_operator) return 0;
  return 1;
}