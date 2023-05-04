#include <QString>
#include <QVector>
#include "calcplot.h"

class Control {
 public:
  Control() = default;
  ~Control() = default;

  void calcs(QString &lines);

  std::pair<QVector<double>, QVector<double>> drawPlot(double xBegin, double xEnd, QString data);

 private:
  Calculate calc{};
  PlotCalc calcPlot{};
  double h = 0.1;
  QVector<double> x, y;
};
