#include <math.h>

#include <QString>
// #include <iostream>
#include <QVector>

class Credit {
 public:
  Credit() = default;
  ~Credit() = default;

 public:
  double rate(double value_) { return value_ / 100 / 12; }
  double termAndRate(double rate_, double term_);
  double oneMonthAnnu(double ammo_, double rate_, double term_);
  double oneMonthDif(double ammo_, double term_) { return ammo_ / term_; }
  double percentage(double ammo, double rate_) { return ammo * rate(rate_); }
  std::pair<double, double> percentAndAmmount(QString line,
                                                QVector<double> rate_);

  std::pair<QVector<double>, QVector<double>> annuCalc(double ammo_,
                                                       double rate_,
                                                       double term_);

  std::pair<QVector<double>, QVector<double>> difCalc(double ammo_,
                                                      double rate_,
                                                      double term_);
};
