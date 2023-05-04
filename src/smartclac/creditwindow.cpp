#include "creditwindow.h"

#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditWindow) {
  ui->setupUi(this);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::on_pushButton_clicked() {
  sum_line = ui->lineEdit_cred_inp->text().toDouble();
  precent_line = ui->lineEdit_precent->text().toDouble();
  month_line = ui->spinBox_month->text().toDouble();
  double prew_sum = sum_line;

  if (ui->comboBox->currentIndex() == 0)

  {
    double ann = precent_line / 100 / month_line;
    int month_pay = sum_line * (ann + (ann / (pow(1 + ann, month_line) - 1)));
    QString str_month_pay = QString::number(month_pay);
    double total_pay = month_pay * month_line;
    int overpay = total_pay - sum_line;

    QString total_sm = QString::number(total_pay, 'g', 10);
    ui->lineEdit_total_sum->setText(total_sm);

    QString ov_pay = QString::number(overpay);
    ui->lineEdit_pereplata->setText(ov_pay);

    for (int i = 1; i <= month_line; i++) {
      int procent_pay = prew_sum * ann;
      QString str_prew_sum = QString::number(prew_sum);
      prew_sum = prew_sum - month_pay + procent_pay;
      int without_precent_pay = month_pay - procent_pay;

      QString str_procent_pay = QString::number(procent_pay);
      QString str_i = QString::number(i);
      QString str_without_precent_pay = QString::number(without_precent_pay);
      QString info = "Месяц  " + str_i + " || Платеж " + str_month_pay +
                     " || Проценты " + str_procent_pay + " || Тело кредита " +
                     str_without_precent_pay + " || Остаток " + str_prew_sum;

      ui->listWidget->addItem(info);
      ui->listWidget->addItem(
          "--------------------------------------------------------------------"
          "---------------");
    }
  } else if (ui->comboBox->currentIndex() == 1) {
    double proc = 0, oz, overpay;
    double mast_pay = sum_line / month_line;
    double total_pay = 0;

    if (precent_line > 9)
      proc = precent_line * 0.01;
    else
      proc = precent_line * 0.1;

    for (int i = 1; i <= month_line; i++) {
      oz = prew_sum * proc / month_line;
      oz = oz + mast_pay;
      QString str_prew_sum = QString::number(prew_sum, 'g', 10);
      prew_sum = prew_sum - oz;
      total_pay = total_pay + oz;

      QString str_i = QString::number(i);
      QString str_procent_pay = QString::number(oz);
      QString info = "Месяц  " + str_i + " || Платеж " + str_procent_pay +
                     " || Остаток " + str_prew_sum;

      ui->listWidget->addItem(info);
      ui->listWidget->addItem(
          "--------------------------------------------------------------------"
          "---------------");
    }
    QString total_sm = QString::number(total_pay, 'g', 10);
    ui->lineEdit_total_sum->setText(total_sm);

    overpay = total_pay - sum_line;
    QString ov_pay = QString::number(overpay);
    ui->lineEdit_pereplata->setText(ov_pay);
  }
}
