#include "calcplot.h"


std::pair<QVector<double>, QVector<double>> s21::PlotCalc::calcing_plot(double xBegin, double xEnd, QString data) {
      QVector<double> x, y;
      x.clear();
      y.clear();
      for (X_ = xBegin; X_ <= xEnd; X_ += h_) {
          QString line = data, value;
          if (X_ < 0.01 && X_ > -0.01) X_ = 0;
          x.push_back(X_);
          value = line.replace("X", '(' + (QString::number(X_)) + ')');
          if (calc_.checkLine(value.toStdString()))
              Y_ = calc_.calculate(value.toStdString());

            y.push_back(Y_);
      }
     return std::pair(x, y);
  }



