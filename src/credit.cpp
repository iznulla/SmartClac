#include <math.h>

#include <iostream>

class Credit {
 public:
  Credit() = default;
  ~Credit() = default;

 public:
  double rate(double value) { return value / 100 / 12; }
  double termAndRate(double rate_, double term_) {
    double result;
    result = pow((1.0 + rate(rate_)), term_) - 1;
    return result;
  }
  double oneMonth(double ammo, double rate_, double term_) {
    double result;
    result = ammo * (rate_ + rate_ / termAndRate(rate_, term_));
    return result;
  }

 private:
  double loan_ammount;
  double interest_rate;
  int term;
};

int main() {
  Credit cr;
  double eee = 0.001;
  double ra = cr.rate(12);
  double e = cr.oneMonth(200000, 12, 24);
  std::cout << "Hello " << e << std::endl;
  return 0;
}