#include <QString>
#include "calculate.h"

class Control {
 public:
  Control() = default;
  ~Control() = default;

  void calcs(QString &lines);

 private:
  Calculate calc{};
};
