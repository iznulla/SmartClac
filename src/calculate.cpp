#include "calculate.h"

// class Check
int Checks::number_check(char value) {
  return digit_symbols.find(value) != string::npos;
}
int Checks::operator_check(char value) {
  return operator_symbols.find(value) != string::npos;
}
int Checks::funcs_check(char value) {
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

int Parser::priority(char op) {
  int result = 10;
  if (op == '+' || op == '-')
    result = 1;
  else if (op == '/' || op == '*' || op == '%')
    result = 2;
  else if (op == '^')
    result = 3;
  else if (check.funcs_check(op))
    result = 4;
  else if (op == '(')
    result = 0;
  return result;
}
string Parser::convertOperator(char op) {
  string temp;
  temp.push_back(op);
  return temp;
}
void Parser::move_less_items(stack<char> *opr_, list<string> *node_) {
  auto sz = opr_->size();
  for (auto i = 0; i != sz; ++i) {
    node_->push_back(convertOperator(opr_->top()));
    opr_->pop();
  }
}
void Parser::add_item(char op, stack<char> *opr_, list<string> *node_) {
  if (!opr_->empty()) {
    if (op == ')') {
      while (opr_->top() != '(') {
        node_->push_back(convertOperator(opr_->top()));
        opr_->pop();
      }
      opr_->pop();
      return;
    }
    if (priority(op) <= priority(opr_->top())) {
      if (priority(op) == 0 || priority(op) == 3) {
        opr_->push(op);
      } else {
        while (priority(op) <= priority(opr_->top())) {
          node_->push_back(convertOperator(opr_->top()));
          opr_->pop();
          if (opr_->empty()) break;
        }
        opr_->push(op);
      }
    } else {
      opr_->push(op);
    }
  } else {
    opr_->push(op);
  }
}
void Parser::pars_to_polish(string value, stack<char> *opr_,
                            list<string> *node_) {
  if (check.input_check(value)) {
    for (size_t i = 0; i != value.size(); ++i) {
      if (check.number_check(value[i])) {
        std::size_t t = i;
        double d = stod(value.substr(t), &t);
        i += t - 1;
        string str = to_string(d);
        node_->push_back(str);
      } else {
        if ((value[i] == '-' && value[i - 1] == '(') ||
            ((i == 0) && (value[i] == '-')))
          node_->push_back("0");
        add_item(value[i], opr_, node_);
      }
    }
    move_less_items(opr_, node_);
  }
}

// class Calculate

double Calculate::popItem() {
  double x = item.back();
  item.pop_back();
  return x;
}
double Calculate::calcOperator(double x, double y, char op) {
  if (op == '+')
    return plus(x, y);
  else if (op == '-')
    return sub(x, y);
  else if (op == '*')
    return mul(x, y);
  else if (op == '/')
    return div(x, y);
  else if (op == '%')
    return fmod(x, y);
  else
    return 0;
}
double Calculate::calcFuncs(double x, char op) {
  double result;
  if (op == '!')
    result = cos(x);
  else if (op == '@')
    result = sin(x);
  else if (op == '#')
    result = tan(x);
  else if (op == '$')
    result = acos(x);
  else if (op == '_')
    result = asin(x);
  else if (op == 'v')
    result = atan(x);
  else if (op == 'b')
    result = sqrt(x);
  else if (op == 'u')
    result = log(x);
  else if (op == 'p')
    result = log10(x);
  return result;
}
// string Parser::check_pars() {
//   string str;
//   for (auto &i : node_) {
//     str.append(i);
//   }
//   for (auto &i : str) {
//     cout << i;
//   }
//   return str;
// }