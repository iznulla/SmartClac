#include "controller.h"

void s21::Control::calcs(QString &lines) {
  std::string cast_expression_to_str = lines.toStdString();
  double result = calc_.calcResult(cast_expression_to_str);
  lines = QString::number(result, 'g', 8);
}

std::pair<QVector<double>, QVector<double>> s21::Control::drawPlot(
    double xBegin, double xEnd, QString data) {
  return std::pair(calcPlot_.calcing_plot(xBegin, xEnd, data));
}

std::pair<QVector<double>, QVector<double>> s21::Control::CreditCalc(
    double ammo, double rate, double term, int is_ann) {
  if ((term > 0) && rate) {
    if (!is_ann)
      return std::pair(cr_.annuCalc(ammo, rate, term));
    else
      return std::pair(cr_.difCalc(ammo, rate, term));
  } else {
    throw std::invalid_argument("rate is zero");
  }
}

std::pair<QString, QString> s21::Control::ammountPercent(QString value,
                                                         QVector<double> rate) {
  auto ammo_percent = cr_.percentAndAmmount(value, rate);
  QString sum_credit_and_percent = QString::number(ammo_percent.first, 'g', 8);
  QString sum_percent = QString::number(ammo_percent.second, 'g', 8);
  return std::pair(sum_credit_and_percent, sum_percent);
}

void s21::Control::depositCalc(double sum_v, double months_v, double rate_v,
                               double tax_v, int choos_capyt,
                               int choos_period) {
  dep_calc_.initData(sum_v, months_v, rate_v, tax_v);
  dep_calc_.debitCalcResult(choos_capyt, choos_period);
}

std::pair<QString, QString> s21::Control::getDepositPercentsAndTaxSum() {
  dep_calc_.percents = round(dep_calc_.percents);
  dep_calc_.tax_sum = round(dep_calc_.tax_sum);
  return std::pair(QString::number(dep_calc_.percents, 'g', 8),
                   QString::number(dep_calc_.tax_sum, 'g', 8));
}

QString s21::Control::getDepositTotal() {
  return QString::number(dep_calc_.total, 'g', 8);
}
