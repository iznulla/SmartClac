#include "controller.h"

void Control::calcs(QString &lines) {
    string cast_expression_to_str = lines.toStdString();
    double result = calc.calcResult(cast_expression_to_str);
    lines = QString::number(result, 'g', 12);
}

void Control::calcing_plot(double xBegin, double xEnd, QString data, QVector<double> *_x, QVector<double> *_y) {
    double X, Y;
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
    *_x = x;
    *_y = y;
}

