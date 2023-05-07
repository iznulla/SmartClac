#include <math.h>

#include <iostream>
#include <vector>

class Credit {
 public:
  Credit() = default;
  ~Credit() = default;

 public:
  double rate(double value_) { return value_ / 100 / 12; }
  double termAndRate(double rate_, double term_) {
    double result;
    result = pow((1.0 + rate(rate_)), term_) - 1;
    return result;
  }
  double oneMonthAnnu(double ammo_, double rate_, double term_) {
    double result;
    result = ammo_ * (rate(rate_) + (rate(rate_) / termAndRate(rate_, term_)));
    return result;
  }
  double percentage(double ammo, double rate_) { return ammo * rate(rate_); }

  std::pair<std::vector<double>, std::vector<double>> annuCalc(double ammo_,
                                                               double rate_,
                                                               double term_) {
    std::vector<double> debt_p{}, balance_o{};
    double amm = oneMonthAnnu(ammo_, rate_, term_);
    double balance_owed = ammo_;
    double debt_part;
    for (auto i = 0.0; i < term_; ++i) {
      debt_part = amm - percentage(balance_owed, rate_);
      balance_owed -= debt_part;
      debt_p.push_back(debt_part);
      balance_o.push_back(balance_owed);
    }
    return std::pair(debt_p, balance_o);
  }

  double oneMonthDif(double ammo_, double term_) { return ammo_ / term_; }

  void difCalc(double ammo_, double rate_, double term_) {
    std::vector<double> debt_p{}, balance_o{};
    double amm = oneMonthDif(ammo_, term_);
    double balance_owed = ammo_;
    double debt_part;
    for (auto i = 0.0; i < term_; ++i) {
      debt_part = amm + percentage(balance_owed, rate_);
      balance_owed -= amm;
      debt_p.push_back(debt_part);
      balance_o.push_back(balance_owed);
    }
  }

 private:
  double loan_ammount;
  double interest_rate;

  int term;
};

int main() {
  Credit cr;
  std::cout << "Платеж Долговая часть остаток" << std::endl;
  auto ann = cr.annuCalc(200000, 12, 24);
  for (auto &i : &j : ann.first, ann.second) {
    std::cout << i << std::endl;
  }
  return 0;
}