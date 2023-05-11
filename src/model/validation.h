#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

namespace s21 {

class Checks {
public:
  Checks() = default;
  ~Checks() = default;

  int numberCheck(char value);
  int operatorCheck(char value);
  int funcsCheck(char value);
  int firstItem(char value);
  int inputCheck(std::string vlaue);

private:
  std::string digit_symbols_ = "0123456789.X";
  std::string operator_symbols_ = "+-*/()^%";
  std::string math_sympols_ = "!@#$_vbup";
};
} // namespace s21

#endif // VALIDATION_H
