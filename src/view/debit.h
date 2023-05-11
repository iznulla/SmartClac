#ifndef DEBIT_H
#define DEBIT_H

#include <../controller/controller.h>

#include <QDialog>

namespace Ui {
class Debit;
}

class Debit : public QDialog {
  Q_OBJECT

 public:
  explicit Debit(QWidget *parent = nullptr);
  ~Debit();

 private slots:
  void on_pushButton_calculate_clicked();

  double on_pushButton_del_clicked();

  void on_pushButton_add_clicked();

  double on_pushButton_del_2_clicked();

  void on_pushButton_add_2_clicked();

 private:
  Ui::Debit *ui;
  s21::Control controll_{};
};

#endif  // DEBIT_H
