#include "calculate.h"

// class Check
int Checks::numberCheck(char value) {
  return digit_symbols_.find(value) != string::npos;
}
int Checks::operatorCheck(char value) {
  return operator_symbols_.find(value) != string::npos;
}
int Checks::funcsCheck(char value) {
  return math_sympols_.find(value) != string::npos;
}
int Checks::firstItem(char value) {
  if (operatorCheck(value))
    if (value != '-' && value != '+' && value != '(') return 0;
  return 1;
}
int Checks::inputCheck(string value) {
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

// class Parser

int Parser::priority(char op) {
  int result = 0;
  if (op == '+' || op == '-')
    result = 1;
  else if (op == '/' || op == '*' || op == '%')
    result = 2;
  else if (op == '^')
    result = 3;
  else if (check_.funcsCheck(op))
    result = 4;
  else if (op == '(')
    result = 0;
  return result;
}
string Parser::convertOperator(char op) {
    string temp{};
  temp.push_back(op);
  return temp;
}
void Parser::moveLessItems(stack<char> *opr, list<string> *node) {
  auto sz = opr->size();
  for (string::size_type i = 0; i != sz; ++i) {
    node->push_back(convertOperator(opr->top()));
    opr->pop();
  }
}
void Parser::addItem(char op, stack<char> *opr, list<string> *node) {
  if (!opr->empty()) {
    if (op == ')') {
      while (opr->top() != '(') {
        node->push_back(convertOperator(opr->top()));
        opr->pop();
      }
      opr->pop();
      return;
    }
    if (priority(op) <= priority(opr->top())) {
      if (priority(op) == 0 || (priority(op) == 3)) {
        opr->push(op);
      } else {
        while (priority(op) <= priority(opr->top())) {
          node->push_back(convertOperator(opr->top()));
          opr->pop();
          if (opr->empty()) break;
        }
        opr->push(op);
      }
    } else {
      opr->push(op);
    }
  } else {
    opr->push(op);
  }
}
void Parser::parsToPolish(string value, stack<char> *opr,
                          list<string> *node) {
  if (check_.inputCheck(value)) {
    for (size_t i = 0; i != value.size(); ++i) {
      if (check_.numberCheck(value[i])) {
        std::size_t t = i;
        double d = stod(value.substr(t), &t);
        i += t - 1;
        string str = to_string(d);
        node->push_back(str);
      } else {
        if ((value[i] == '-' && value[i - 1] == '(') ||
            ((i == 0) && (value[i] == '-')))
          node->push_back("0");
        addItem(value[i], opr, node);
      }
    }
    moveLessItems(opr, node);
  } else
    throw invalid_argument("ERROR");
}

// class Calculate

double Calculate::getItem() {
  double x = items_.back();
  items_.pop_back();
  return x;
}
double Calculate::calcOperator(double x, double y, char op) {
    double result{};
  try {
  if (op == '+') {
    result = plus(x, y);
  } else if (op == '-') {
    result = sub(x, y);
  } else if (op == '*') { 
    result = mul(x, y);
  } else if (op == '/') {
    if (y == 0)
      throw invalid_argument("division by zero");
    else
      result = div(x, y);
  } else if (op == '%') {
    if (y == 0)
      throw invalid_argument("division by zero");
    else
      result = fmod(x, y);
  } else if (op == '^') {
    result = pow(x, y);
  }
  }
  catch (...) {
      throw invalid_argument("INVALID INPUT");
  }

  return result;
}
double Calculate::calcFuncs(double x, char op) {
    double result{};
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
  else
    result = log10(x);
  return result;
}
double Calculate::calcResult(string &lines) {
  if (lines.size() == 0) throw invalid_argument("ERROR");
  double res{};
  res = calculate(lines);
  return res;
}
double Calculate::calculate(string value) {
  node_.clear();
  pars_.parsToPolish(value, &opr_, &node_);
  double result{};
  for (auto &i : node_) {
    if (check_.numberCheck(i.front())) {
      std::size_t sz = i.size();
      double d = stod(i, &sz);
      items_.push_back(d);
    } else if (check_.operatorCheck(i.front())) {
      double y = getItem();
      double x = getItem();
      items_.push_back(calcOperator(x, y, i.front()));
    } else if (check_.funcsCheck(i.front())) {
      double x = getItem();
      items_.push_back(calcFuncs(x, i.front()));
    }
  }
  result = getItem();
  return result;
}
