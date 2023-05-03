#include <QVector>
#include "calculate.h"


class PlotCalc {
public:
  PlotCalc() = default;
  ~PlotCalc() = default;

   using result_pair = std::pair<QVector<double>, QVector<double>>;

  std::pair<QVector<double>, QVector<double>> calcing_plot(double xBegin, double xEnd, QString data);

  private:
  double h = 0.1, X, Y;
  Calculate calc{};
  

};
