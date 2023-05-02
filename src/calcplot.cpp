#include <iostream>
#include <QVector>
#include "calculate.h"




//ui->widget->xAxis->setRange(xBegin, xEnd);
//ui->widget->yAxis->setRange(xBegin, xEnd);
class PlotCalc {
public:
  PlotCalc() = default;
  ~PlotCalc() = default;


//    N = (xEnd - xBegin)/h + 2;
  void calcing_plot(double xBegin, double _y, QString data) {
      for ( ;X <= xEnd; X += h) {
          QString line = data, value;
          if (X < 0.01 && X > -0.01) X = 0;
          x.push_back(X);

          value = line.replace("X", ('(' + QString::number(X) + ')'));
          if (calc.checkLine(value.toStdString())) {
              if (value.toStdString().data())
                  Y = calc.calculate(value.toStdString());
              else
                  Y = 0;
          }
          y.push_back(Y);
      }
  }

  private:
  double h = 0.1, xBegin = 1, xEnd = 2, X = xBegin, Y;
  Calculate calc{};
  QVector<double> x, y;

};

//ui->widget->addGraph();
//ui->widget->graph(0)->setData(x, y);
//ui->widget->replot();
//x.clear();
//y.clear();
//}
