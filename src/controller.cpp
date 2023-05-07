#include "controller.h"

void Control::calcs(QString &lines) {
  string cast_expression_to_str = lines.toStdString();
  double result = calc.calcResult(cast_expression_to_str);
  lines = QString::number(result, 'g', 12);
}

std::pair<QVector<double>, QVector<double>> Control::drawPlot(double xBegin,
                                                              double xEnd,
                                                              QString data) {
  return std::pair(calcPlot.calcing_plot(xBegin, xEnd, data));
}

std::pair<QVector<double>, QVector<double>> Control::CreditCalc(double ammo_,
                                                                double rate_,
                                                                double term_,
                                                                int is_ann) {
  if (is_ann)
    return std::pair(cr.annuCalc(ammo_, rate_, term_));
  else
    return std::pair(cr.difCalc(ammo_,rate_, term_));
}
