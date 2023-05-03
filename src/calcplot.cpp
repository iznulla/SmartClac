#include "calcplot.h"


std::pair<QVector<double>, QVector<double>> PlotCalc::calcing_plot(double xBegin, double xEnd, QString data) {
      QVector<double> x, y;
      x.clear();
      y.clear();
      for (X = xBegin; X <= xEnd; X += h) {
          QString line = data, value;
          if (X < 0.01 && X > -0.01) X = 0;
          x.push_back(X);
          value = line.replace("X", '(' + (QString::number(X)) + ')');
          if (calc.checkLine(value.toStdString()))
              Y = calc.calculate(value.toStdString());
          y.push_back(Y);
      }
     return std::pair(x, y);
  }



