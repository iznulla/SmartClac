

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
  std::pair<QVector<double>, QVector<double>> CreditCalc(double ammo,
                                                         double rate,
                                                         double term,
                                                         int is_ann);
  std::pair<QString, QString> ammountPercent(QString value,
                                             QVector<double> rate);

 private:
  Calculate calc_{};
  PlotCalc calcPlot_{};
  Credit cr_{};
};
