#include "calculate.h"

// class Check


// class Parser



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
      throw std::invalid_argument("division by zero");
    else
      result = div(x, y);
  } else if (op == '%') {
    if (y == 0)
      throw std::invalid_argument("division by zero");
    else
      result = fmod(x, y);
  } else if (op == '^') {
    result = pow(x, y);
  }
  }
  catch (...) {
      throw std::invalid_argument("INVALID INPUT");
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
double Calculate::calcResult(std::string &lines) {
  if (lines.size() == 0) throw std::invalid_argument("ERROR");
  double res{};
  res = calculate(lines);
  return res;
}
double Calculate::calculate(std::string value) {
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
