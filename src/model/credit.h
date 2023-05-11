#ifndef CREDIT_H
#define CREDIT_H

#include <math.h>

#include <QString>
#include <QVector>

namespace s21 {

class Credit {
public:
    Credit() = default;
    ~Credit() = default;

public:
    double rate(double value) { return value / 100 / 12; }
    double termAndRate(double rate_credit, double term);
    double oneMonthAnnu(double ammo, double rate_credit, double term);
    double oneMonthDif(double ammo, double term) { return ammo / term; }
    double percentage(double ammo, double rate_credit) {
        return ammo * rate(rate_credit);
    }
    std::pair<double, double> percentAndAmmount(QString line,
                                                QVector<double> rate_credit);

    std::pair<QVector<double>, QVector<double>> annuCalc(double ammo,
                                                         double rate_credit,
                                                         double term);

    std::pair<QVector<double>, QVector<double>> difCalc(double ammo,
                                                        double rate_credit,
                                                        double term);
};
}  // namespace s21

#endif // CREDIT_H
