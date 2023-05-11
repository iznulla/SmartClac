#ifndef PARSER_H
#define PARSER_H

#include "validation.h"
#include <stack>
#include <list>

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  int priority(char op);
  void moveLessItems(std::stack<char> *opr, std::list<std::string> *node);
  void addItem(char op, std::stack<char> *opr, std::list<std::string> *node);
  void parsToPolish(std::string value, std::stack<char> *opr, std::list<std::string> *node);
  std::string convertOperator(char op);

 private:
  Checks check_{};
};

#endif // PARSER_H
