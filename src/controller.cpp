#include "controller.h"

void Control::calcs(QString &lines) {
  string cast_expression_to_str = lines.toStdString();
  double result = calc_.calcResult(cast_expression_to_str);
  lines = QString::number(result, 'g', 12);
}

std::pair<QVector<double>, QVector<double>> Control::drawPlot(double xBegin,
                                                              double xEnd,
                                                              QString data) {
  return std::pair(calcPlot_.calcing_plot(xBegin, xEnd, data));
}

std::pair<QVector<double>, QVector<double>> Control::CreditCalc(double ammo,
                                                                double rate,
                                                                double term,
                                                                int is_ann) {
    if ((term > 0) && rate)
    {
        if (!is_ann)
            return std::pair(cr_.annuCalc(ammo, rate, term));
        else
            return std::pair(cr_.difCalc(ammo, rate, term));
    } else {
        throw invalid_argument("rate is zero");
    }
}

std::pair<QString, QString> Control::ammountPercent(QString value,
                                                    QVector<double> rate) {
  auto ammo_percent = cr_.percentAndAmmount(value, rate);
  QString sum_credit_and_percent = QString::number(ammo_percent.first, 'g', 7);
  QString sum_percent = QString::number(ammo_percent.second, 'g', 7);
  return std::pair(sum_credit_and_percent, sum_percent);
}

void Control::depositCalc(double sum_v, double months_v, double rate_v, double tax_v, int choos_capyt, int choos_period) {
    dep_calc_.initData(sum_v, months_v, rate_v, tax_v);
    dep_calc_.debitCalcResult(choos_capyt, choos_period);
}

std::pair<QString, QString> Control::getDepositPercentsAndTaxSum() {
    dep_calc_.percents = round(dep_calc_.percents);
    dep_calc_.tax_sum = round(dep_calc_.tax_sum);
    return std::pair(QString::number(dep_calc_.percents, 'g', 7), QString::number(dep_calc_.tax_sum, 'g', 7));
}

QString Control::getDepositTotal() {
    return QString::number(dep_calc_.total, 'g', 7);
}
