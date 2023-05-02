#include <QString>
#include <QVector>
#include "calculate.h"

class Control {
 public:
  Control() = default;
  ~Control() = default;

  void calcs(QString &lines);

  void calcing_plot(double xBegin, double xEnd, QString data, QVector<double> *_x, QVector<double> *_y);

  QVector<double> getX() {
      return x;
  }
  QVector<double> getY() {
      return y;
  }

 private:
  Calculate calc{};
  double h = 0.1;
  QVector<double> x, y;
};
