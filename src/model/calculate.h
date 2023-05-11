#ifndef CALCULATE_H
#define CALCULATE_H

#include <math.h>

#include "parser.h"
#include "validation.h"

namespace s21 {

class Calculate {
 public:
  Calculate() = default;
  ~Calculate() = default;

 public:
  double plus(double x, double y) { return x + y; }
  double sub(double x, double y) { return x - y; }
  double mul(double x, double y) { return x * y; }
  double div(double x, double y) { return x / y; }
  int checkLine(std::string value) { return check_.inputCheck(value); }
  double getItem();

  double calcOperator(double x, double y, char op);
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}, {"^",
  //     }};
  double calcFuncs(double x, char op);
  double calculate(std::string value);
  double calcResult(std::string &lines);

 private:
  s21::Checks check_{};
  s21::Parser pars_;
  std::list<double> items_{};
  std::list<std::string> node_{};
  std::stack<char> opr_{};
};
}  // namespace s21

#endif  // CALCULATE_H
