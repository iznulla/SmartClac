#include "validation.h"

int s21::Checks::numberCheck(char value) {
  return digit_symbols_.find(value) != std::string::npos;
}
int s21::Checks::operatorCheck(char value) {
  return operator_symbols_.find(value) != std::string::npos;
}
int s21::Checks::funcsCheck(char value) {
  return math_sympols_.find(value) != std::string::npos;
}
int s21::Checks::firstItem(char value) {
  if (operatorCheck(value))
    if (value != '-' && value != '+' && value != '(') return 0;
  return 1;
}
int s21::Checks::inputCheck(std::string value) {
  int valid_operator = 0, scopes = 0, math_symb = 0, is_pre_num = 0, close = 0,
      num = 0;
  if (!firstItem(value[0])) return 0;
  for (auto &i : value) {
    if (!numberCheck(i) && !operatorCheck(i) && !funcsCheck(i)) return 0;
    if (numberCheck(i)) {
      if (close) return 0;
      valid_operator = 0, ++is_pre_num;
      ++num;
    }
    if (funcsCheck(i)) {
      if (valid_operator) --valid_operator;
      ++math_symb;
    }
    if (operatorCheck(i)) {
      if (i == '(') {
        if (is_pre_num) return 0;
        if (math_symb) --math_symb;
        ++scopes;
        if (valid_operator) --valid_operator;
      } else if (i == ')' && !valid_operator) {
        --scopes, ++close;
      } else {
        if (valid_operator) return 0;
        ++valid_operator, close = 0;
      }
      is_pre_num = 0;
    }
  }
  if (valid_operator || scopes || math_symb || !num) return 0;
  return 1;
}
