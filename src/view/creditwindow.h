#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QDialog>

#include "../controller/controller.h"

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QDialog {
  Q_OBJECT

 public:
  explicit CreditWindow(QWidget *parent = nullptr);
  ~CreditWindow();

 private slots:
  void on_pushButton_cr_calc_clicked();

 private:
  Ui::CreditWindow *ui;
  s21::Control controll_{};
};

#endif  // CREDITWINDOW_H
