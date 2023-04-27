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

  int numberCheck(char value);
  int operatorCheck(char value);
  int funcsCheck(char value);
  int firstItem(char value);
  int inputCheck(string vlaue);

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
  void moveLessItems(stack<char> *opr_, list<string> *node_);
  void addItem(char op, stack<char> *opr_, list<string> *node_);
  void parsToPolish(string value, stack<char> *opr_, list<string> *node_);
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
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}, {"^",
  //     }};
  double calcFuncs(double x, char op);
  void initPars(string value) { pars.parsToPolish(value, &opr, &node); }
  void print() {
    for (auto &i : items) {
      cout << i << endl;
    }
  }
  double calculate(string value) {
    pars.parsToPolish(value, &opr, &node);
    double result = 0;
    for (auto &i : node) {
      auto item = items.begin();
      if (check.numberCheck(i.front())) {
        std::size_t sz = i.size();
        double d = stod(i, &sz);
        items.push_back(d);
      } else if (check.operatorCheck(i.front())) {
        double y = popItem();
        double x = popItem();
        items.push_back(calcOperator(x, y, i.front()));
      } else if (check.funcsCheck(i.front())) {
        double x = popItem();
        items.push_back(calcFuncs(x, i.front()));
      }
    }
    // double y = popItem();
    // double x = popItem();
    // result = calcOperator()
    return result;
  }

 private:
  Checks check{};
  Parser pars{};
  list<double> items{};
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
