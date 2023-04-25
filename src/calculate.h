#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>

using namespace std;

struct Node_operator {
  char value;
  int priority = 0;
};

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
  string digit_symbols = "0123456789";
  string operator_symbols = "+-*/()^.%";
  // string str_symbols = "sincoatqrlgmd";
  map<string, int> math_preorites{{"!", 11}, {"@", 12}, {"#", 13}, {"$", 14},
                                  {"_", 15}, {"v", 16}, {"b", 17}, {"u", 18},
                                  {"p", 19}, {"%", 2}};
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  string math_sympols = "!@#$_vbup";
};

class Calculate {
 public:
  Calculate() = default;
  ~Calculate() = default;

  void clear() {
    this->node_.clear();
    while (!opr_.empty()) {
      this->opr_.pop();
    }
  }
  double plus(double x, double y) { return x + y; }
  double sub(double x, double y) { return x - y; }
  double mul(double x, double y) { return x * y; }
  double div(double x, double y) { return x / y; }

  double calc(double x, double y, char op) {
    if (op == '+')
      return plus(x, y);
    else if (op == '-')
      return sub(x, y);
    else if (op == '*')
      return mul(x, y);
    else if (op == '/')
      return div(x, y);
    else
      return 0;
  }
  double pop_item() {
    double x = node_.back();
    node_.pop_back();
    return x;
  }

  int priority(char op) {
    int result = 10;
    if (op == '+' || op == '-')
      result = 1;
    else if (op == '/' || op == '*')
      result = 2;
    else if (op == '(')
      result = 0;
    return result;
  }

  void calculate(char op) {
    double y = pop_item();
    double x = pop_item();
    node_.push_back(calc(x, y, opr_.top()));
    opr_.pop();
  }

  void add_item(char op) {
    if (!opr_.empty()) {
      if (priority(op) <= priority(opr_.top())) {
        calculate(opr_.top());
        if (op != 0) opr_.push(op);
      } else {
        opr_.push(op);
      }
    } else {
      opr_.push(op);
    }
  }

  void pars_and_calc(string value) {
    if (check.input_check(value)) {
      double d;
      for (size_t i = 0; i != value.size();) {
        if (check.number_check(value[i])) {
          std::size_t t = i;
          d = stod(value.substr(t), &t);
          i += t;
          this->node_.push_back(d);
        } else if (value[i] == '(' || value[i] == ')') {
          ++i;
          continue;
        } else {
          add_item(value[i]);
          i++;
        }
      }
      calculate(opr_.top());
    }
  }
  void print() {
    for (auto &i : node_) cout << i << endl;
  }

  double calcAll(string value) {
    pars_and_calc(value);
    if (node_.size() > 1) calculate(opr_.top());
    double res = node_.back();
    return res;
  }

 private:
  Checks check{};
  list<double> node_{};
  stack<char> opr_{};
};