#ifndef CALCULATE_H
#define CALCULATE_H

#include <math.h>

#include <cstdlib>
//#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <utility>

using namespace std;

class Checks {
 public:
  Checks() = default;
  ~Checks() = default;

  int numberCheck(char value);
  int operatorCheck(char value);
  int funcsCheck(char value);
  int firstItem(char value);
  int inputCheck(string vlaue);

 private:
  string digit_symbols_ = "0123456789.X";
  string operator_symbols_ = "+-*/()^%";
  string math_sympols_ = "!@#$_vbup";
};

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  int priority(char op);
  void moveLessItems(stack<char> *opr_, list<string> *node_);
  void addItem(char op, stack<char> *opr_, list<string> *node_);
  void parsToPolish(string value, stack<char> *opr_, list<string> *node_);
  string convertOperator(char op);

 private:
  Checks check_{};
};

class Calculate {
 public:
  Calculate() = default;
  ~Calculate() = default;

 public:
  double plus(double x, double y) { return x + y; }
  double sub(double x, double y) { return x - y; }
  double mul(double x, double y) { return x * y; }
  double div(double x, double y) { return x / y; }
  int checkLine(string value) { return check_.inputCheck(value); }
  double getItem();

  double calcOperator(double x, double y, char op);
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}, {"^",
  //     }};
  double calcFuncs(double x, char op);
  double calculate(string value);
  double calcResult(string &lines);

 private:
  Checks check_{};
  Parser pars_{};
  list<double> items_{};
  list<string> node_{};
  stack<char> opr_{};
};

#endif // CALCULATE_H
