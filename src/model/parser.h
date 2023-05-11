#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <stack>

#include "validation.h"

namespace s21 {

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  int priority(char op);
  void moveLessItems(std::stack<char> *opr, std::list<std::string> *node);
  void addItem(char op, std::stack<char> *opr, std::list<std::string> *node);
  void parsToPolish(std::string value, std::stack<char> *opr,
                    std::list<std::string> *node);
  std::string convertOperator(char op);

 private:
  s21::Checks checks_{};
};
}  // namespace s21

#endif  // PARSER_H
