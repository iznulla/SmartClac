#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <math.h>

#include <iostream>

constexpr double AVERAGE_DAYS_IN_MONTH = 30.416666666666667851;
constexpr double NDFL = 13.00 / 100.00;

namespace s21 {

struct DepositCalcing {
  double total{};
  double percents{};
  double tax_sum{};
  double sum{};
  double months{};
  double rate{};
  double tax{};

  void initData(double sum_v, double months_v, double rate_v, double tax_v);

  double percent(int choos);

  std::pair<double, double> taxSum(int choos);
  void debitCalcResult(int choos_capyt, int choos_period);
};
} // namespace s21

#endif // DEPOSIT_H
