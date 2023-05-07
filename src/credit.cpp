#include "credit.h"

double Credit::termAndRate(double rate_, double term_) {
  double result;
  result = pow((1.0 + rate(rate_)), term_) - 1;
  return result;
}
double Credit::oneMonthAnnu(double ammo_, double rate_, double term_) {
  double result;
  result = ammo_ * (rate(rate_) + (rate(rate_) / termAndRate(rate_, term_)));
  return result;
}
double Credit::percentAmmount(std::vector<double> rate_) {
  double result = rate_[0];
  for (auto i = 1; i < rate_.size(); ++i) {
    result += rate_[i];
  }
  return result;
}

std::pair<std::vector<double>, std::vector<double>> Credit::annuCalc(
    double ammo_, double rate_, double term_) {
  std::vector<double> debt_p{}, balance_o{};
  double amm = oneMonthAnnu(ammo_, rate_, term_);
  double balance_owed = ammo_;
  double debt_part;
  for (auto i = 0.0; i < term_; ++i) {
    debt_p.push_back(percentage(balance_owed, rate_));
    debt_part = amm - percentage(balance_owed, rate_);
    balance_owed -= debt_part;
    balance_o.push_back(debt_part);
  }
  return std::pair(debt_p, balance_o);
}

std::pair<std::vector<double>, std::vector<double>> Credit::difCalc(
    double ammo_, double rate_, double term_) {
  std::vector<double> debt_p{}, balance_o{};
  double amm = oneMonthDif(ammo_, term_);
  double balance_owed = ammo_;
  double debt_part;
  for (auto i = 0.0; i < term_; ++i) {
    // debt_p.push_back(percentage(balance_owed, rate_));
    debt_part = amm + percentage(balance_owed, rate_);
    balance_owed -= amm;
    debt_p.push_back(debt_part);
    balance_o.push_back(amm);
  }
  return std::pair(debt_p, balance_o);
}

int main() {
  Credit cr;
  std::cout << "Платеж Долговая часть остаток" << std::endl;
  auto ann = cr.annuCalc(200000, 12, 24);
  // for (auto i = 0; i < ann.first.size(); ++i) {
  //   std::cout << ann.first[i] << " " << ann.second[i] << std::endl;
  // }
  std::cout << cr.percentAmmount(ann.first) << std::endl;
  return 0;
}