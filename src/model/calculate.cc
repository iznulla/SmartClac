#include "calculate.h"

double s21::Calculate::getItem() {
  double x = items_.back();
  items_.pop_back();
  return x;
}
double s21::Calculate::calcOperator(double x, double y, char op) {
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
        throw("ERROR");
      else
        result = div(x, y);
    } else if (op == '%') {
      if (y == 0)
        throw("ERROR");
      else
        result = fmod(x, y);
    } else if (op == '^') {
      result = pow(x, y);
    }
  } catch (...) {
    throw("ERROR");
  }

  return result;
}
double s21::Calculate::calcFuncs(double x, char op) {
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
double s21::Calculate::calcResult(std::string &lines) {
  if (lines.size() == 0)
    throw("ERROR");
  double res{};
  res = calculate(lines);
  return res;
}
double s21::Calculate::calculate(std::string value) {
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
