#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "calcplot.h"
#include "credit.h"
#include "deposit.h"

class Control {
 public:
  Control() = default;
  ~Control() = default;

  void calcs(QString &lines);

  std::pair<QVector<double>, QVector<double>> drawPlot(double xBegin,
                                                       double xEnd,
                                                       QString data);
  std::pair<QVector<double>, QVector<double>> CreditCalc(double ammo,
                                                         double rate,
                                                         double term,
                                                         int is_ann);
  std::pair<QString, QString> ammountPercent(QString value,
                                             QVector<double> rate);

  void depositCalc(double sum_v, double months_v, double rate_v,
                   double tax_v, int choos_capyt, int choos_period);

  std::pair<QString, QString> getDepositPercentsAndTaxSum();
  QString getDepositTotal();


 private:
  Calculate calc_{};
  PlotCalc calcPlot_{};
  Credit cr_{};
  DepositCalcing dep_calc_{};

};

#endif // CONTROLLER_H
