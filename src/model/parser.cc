#include "parser.h"

int s21::Parser::priority(char op) {
  int result = 0;
  if (op == '+' || op == '-')
    result = 1;
  else if (op == '/' || op == '*' || op == '%')
    result = 2;
  else if (op == '^')
    result = 3;
  else if (checks_.funcsCheck(op))
    result = 4;
  else if (op == '(')
    result = 0;
  return result;
}
std::string s21::Parser::convertOperator(char op) {
  std::string temp{};
  temp.push_back(op);
  return temp;
}
void s21::Parser::moveLessItems(std::stack<char> *opr,
                                std::list<std::string> *node) {
  auto sz = opr->size();
  for (std::string::size_type i = 0; i != sz; ++i) {
    node->push_back(convertOperator(opr->top()));
    opr->pop();
  }
}
void s21::Parser::addItem(char op, std::stack<char> *opr,
                          std::list<std::string> *node) {
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
          if (opr->empty())
            break;
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
void s21::Parser::parsToPolish(std::string value, std::stack<char> *opr,
                               std::list<std::string> *node) {
  if (checks_.inputCheck(value)) {
    for (size_t i = 0; i != value.size(); ++i) {
      if (checks_.numberCheck(value[i])) {
        std::size_t t = i;
        double d = stod(value.substr(t), &t);
        i += t - 1;
        std::string str = std::to_string(d);
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
    throw("ERROR");
}
