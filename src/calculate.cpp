#include "calculate.h"

// class Check
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
int Checks::first_item(char value) {
  if (operator_check(value))
    if (value != '-' && value != '+' && value != '(') return 0;
  return 1;
}
int Checks::input_check(string value) {
  int valid_operator = 0, scopes = 0, math_symb = 0, is_pre_num = 0, close = 0;
  if (!first_item(value[0])) return 0;
  for (auto &i : value) {
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
  if (valid_operator || scopes || math_symb) return 0;
  return 1;
}

// class Parser

void Parser::clear() {
  this->node_.clear();
  while (!opr_.empty()) {
    this->opr_.pop();
  }
}
int Parser::priority(char op) {
  int result = 10;
  if (op == '+' || op == '-')
    result = 1;
  else if (op == '/' || op == '*' || op == '%')
    result = 2;
  else if (op == '^')
    result = 3;
  else if (op == '(')
    result = 0;
  return result;
}
void Parser::move_less_items() {
  auto sz = opr_.size();
  for (auto i = 0; i != sz; ++i) {
    node_.push_back(opr_.top());
    opr_.pop();
  }
}
void Parser::add_item(char op) {
  if (!opr_.empty()) {
    if (op == ')') {
      while (opr_.top() != '(') {
        node_.push_back(opr_.top());
        opr_.pop();
      }
      opr_.pop();
      return;
    }
    if (priority(op) <= priority(opr_.top())) {
      if (priority(op) == 0) {
        opr_.push(op);
      } else {
        while (priority(op) <= priority(opr_.top())) {
          node_.push_back(opr_.top());
          opr_.pop();
          if (opr_.empty()) break;
        }
        opr_.push(op);
      }
    } else {
      opr_.push(op);
    }
  } else {
    opr_.push(op);
  }
}
void Parser::pars_to_polish(string value) {
  if (check.input_check(value)) {
    for (size_t i = 0; i != value.size(); ++i) {
      if (check.number_check(value[i])) {
        this->node_.push_back(value[i]);
      } else {
        if (value[i] == '-' && value[i - 1] == '(') this->node_.push_back('0');
        add_item(value[i]);
      }
    }
    move_less_items();
  }
}