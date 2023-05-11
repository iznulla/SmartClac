#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "creditwindow.h"
#include "debit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  s21::Control calc_{};
  CreditWindow credit_;
  Debit debit_{};
  QString calc_text_;

 private:
  int check_dot_;
  int check_scope_;

 private slots:
  void inputItems();
  void inputOperators();
  void on_pushButton_AC_clicked();
  void on_pushButton_eq_clicked();
  void on_pushButton_Del_clicked();
  void on_pushButton_dot_clicked();
  void on_pushButton_scop_open_clicked();
  void on_pushButton_scop_close_clicked();
  void on_pushButton_graphic_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_debet_clicked();
};
#endif  // MAINWINDOW_H
