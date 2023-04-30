#include "controller.h"

void Control::calcs(QString &lines) {
    string cast_expression_to_str = lines.toStdString();
    double result = calc.calcResult(cast_expression_to_str);
    lines = QString::number(result, 'g', 12);
}