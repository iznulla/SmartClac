#ifndef CALCPLOT_H
#define CALCPLOT_H

#include <QVector>

#include "calculate.h"

namespace s21 {

class PlotCalc {
public:
  PlotCalc() = default;
  ~PlotCalc() = default;

  using result_pair = std::pair<QVector<double>, QVector<double>>;

  std::pair<QVector<double>, QVector<double>>
  calcing_plot(double xBegin, double xEnd, QString data);

private:
  double h_ = 0.1, X_, Y_;
  s21::Calculate calc_{};
};
} // namespace s21

#endif // CALCPLOT_H
