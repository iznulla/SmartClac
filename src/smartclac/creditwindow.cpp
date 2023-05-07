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

  auto pay_info = controll_.CreditCalc(sum_line, precent_line, month_line, ui->comboBox->currentIndex());
  QString overpay = QString::number(pay_info.first[0]);
  ui->lineEdit_pereplata->setText(overpay);
//      QString info = "Месяц  " + str_i + " || Платеж " + str_procent_pay +
//                     " || Остаток " + str_prew_sum;

//      ui->listWidget->addItem(info);
//      ui->listWidget->addItem(
//          "--------------------------------------------------------------------"
//          "---------------");

//    QString total_sm = QString::number(total_pay, 'g', 10);
//    ui->lineEdit_total_sum->setText(total_sm);

//    overpay = total_pay - sum_line;
//    QString ov_pay = QString::number(overpay);
//    ui->lineEdit_pereplata->setText(ov_pay);

}
