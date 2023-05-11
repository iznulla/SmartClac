#include "credit.h"

double s21::Credit::termAndRate(double rate_credit, double term) {
  double result{};
  result = pow((1.0 + rate(rate_credit)), term) - 1;
  return result;
}
double s21::Credit::oneMonthAnnu(double ammo, double rate_credit, double term) {
  double result{};
  result = ammo * (rate(rate_credit) +
                   (rate(rate_credit) / termAndRate(rate_credit, term)));
  return result;
}
std::pair<double, double> s21::Credit::percentAndAmmount(
    QString line, QVector<double> rate_credit) {
  double sum_percent = rate_credit[0];
  for (qsizetype i = 1; i < rate_credit.size(); ++i) {
    sum_percent += rate_credit[i];
  }
  double sum_amm_percent = line.toDouble() + sum_percent;
  return std::pair(sum_percent, sum_amm_percent);
}

std::pair<QVector<double>, QVector<double>> s21::Credit::annuCalc(double ammo,
                                                             double rate_credit,
                                                             double term) {
  QVector<double> debt_p{}, balance_o{};
  double amm = oneMonthAnnu(ammo, rate_credit, term);
  double balance_owed = ammo;
  double debt_part{};
  for (auto i = 0; i < term; ++i) {
    debt_p.push_back(percentage(balance_owed, rate_credit));
    debt_part = amm - percentage(balance_owed, rate_credit);
    balance_owed -= debt_part;
    balance_o.push_back(amm);
  }
  return std::pair(debt_p, balance_o);
}

std::pair<QVector<double>, QVector<double>> s21::Credit::difCalc(double ammo,
                                                            double rate_credit,
                                                            double term) {
  QVector<double> debt_p{}, balance_o{};
  double amm = oneMonthDif(ammo, term);
  double balance_owed = ammo;
  double debt_part{};
  for (auto i = 0; i < term; ++i) {
    debt_p.push_back(percentage(balance_owed, rate_credit));
    debt_part = amm + percentage(balance_owed, rate_credit);
    balance_owed -= amm;
    balance_o.push_back(debt_part);
  }
  return std::pair(debt_p, balance_o);
}
