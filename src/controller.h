#include <QString>
// #include <QVector>

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

 private:
  Calculate calc{};
  PlotCalc calcPlot{};
  Credit cr{};
  double h = 0.1;
  QVector<double> x, y;
};
