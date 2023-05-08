

#include "calcplot.h"
#include "credit.h"

class Control {
 public:
  Control() = default;
  ~Control() = default;

  void calcs(QString &lines);

  std::pair<QVector<double>, QVector<double>> drawPlot(double xBegin,
                                                       double xEnd,
                                                       QString data);
  std::pair<QVector<double>, QVector<double>> CreditCalc(double ammo_,
                                                         double rate_,
                                                         double term_,
                                                         int is_ann);
  std::pair<QString, QString> ammountPercent(QString value, QVector<double> rate) {
      auto ammo_percent = cr.percentAndAmmount(value, rate);
    QString sum_credit_and_percent = QString::number(ammo_percent.first, 'g', 7);
    QString sum_percent = QString::number(ammo_percent.second, 'g', 7);
    return std::pair(sum_credit_and_percent, sum_percent);
  }

 private:
  Calculate calc{};
  PlotCalc calcPlot{};
  Credit cr{};
//  double h = 0.1;
  QVector<double> x, y;
};
