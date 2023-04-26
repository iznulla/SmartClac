#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
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
  // string str_symbols = "sincoatqrlgmd";
  map<string, int> math_preorites{{"!", 11}, {"@", 12}, {"#", 13}, {"$", 14},
                                  {"_", 15}, {"v", 16}, {"b", 17}, {"u", 18},
                                  {"p", 19}, {"%", 2}};
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  string math_sympols = "!@#$_vbup";
};

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  void clear();
  int priority(char op);
  void move_less_items();
  void add_item(char op);
  void pars_to_polish(string value);
  void print() {
    for (auto &i : node_) cout << i;
  }
  string check_pars() { return node_; }

 private:
  Checks check{};
  string node_{};
  stack<char> opr_{};
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

// double plus(double x, double y) { return x + y; }
// double sub(double x, double y) { return x - y; }
// double mul(double x, double y) { return x * y; }
// double div(double x, double y) { return x / y; }

// double calc(double x, double y, char op);
// double pop_item() {
//   double x = node_.back();
//   node_.pop_back();
//   return x;
// }

// void calcs(char op) {
//   double y = pop_item();
//   double x = pop_item();
//   node_.push_back(calc(x, y, opr_.top()));
//   opr_.pop();
// }

// std::size_t t = i;
// d = stod(value.substr(t), &t);
// i += t;
