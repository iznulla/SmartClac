#include <math.h>

#include <cstdlib>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <utility>

using namespace std;

class Checks {
 public:
  Checks() = default;
  ~Checks() = default;

  int number_check(char value);
  int operator_check(char value);
  int funcs_check(char value);
  int first_item(char value);
  int input_check(string vlaue);

 private:
  string digit_symbols = "0123456789.";
  string operator_symbols = "+-*/()^%";
  string math_sympols = "!@#$_vbup";
};

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  int priority(char op);
  void move_less_items(stack<char> *opr_, list<string> *node_);
  void add_item(char op, stack<char> *opr_, list<string> *node_);
  void pars_to_polish(string value, stack<char> *opr_, list<string> *node_);
  string convertOperator(char op);

 private:
  Checks check{};
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

  double popItem();

  double calcOperator(double x, double y, char op);
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  double calcFuncs(double x, char op);
  void initPars(string value) { pars.pars_to_polish(value, &opr, &node); }
  void print() {
    for (auto &i : node) {
      cout << i << endl;
    }
  }

 private:
  Checks check{};
  Parser pars{};
  list<double> item{};
  list<string> node{};
  stack<char> opr{};
};

// double Parser::calc(double x, double y, char op) {
//   if (op == '+')
//     return plus(x, y);
//   else if (op == '-')
//     return sub(x, y);
//   else if (op == '*')
//     return mul(x, y);
//   else if (op == '/')
//     return div(x, y);
//   else
//     return 0;
// }

// double calc(double x, double y, char op);

// void calcs(char op) {
//   double y = pop_item();
//   double x = pop_item();
//   node_.push_back(calc(x, y, opr_.top()));
//   opr_.pop();
// }

// std::size_t t = i;
// d = stod(value.substr(t), &t);
// i += t;
