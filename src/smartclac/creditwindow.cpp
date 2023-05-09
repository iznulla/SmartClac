#include "creditwindow.h"

#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditWindow) {
  ui->setupUi(this);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::on_pushButton_cr_calc_clicked()
{
    ui->listWidget->clear();
    double sum_line = ui->lineEdit_cred_inp->text().toDouble();
    double precent_line = ui->lineEdit_precent->text().toDouble();
    double month_line = ui->spinBox_month->text().toDouble();
     try
     {
         auto pay_info = controll_.CreditCalc(sum_line, precent_line, month_line, ui->comboBox->currentIndex());
         for (auto i = 0; i < pay_info.first.size(); ++i)
         {
             QString info = " Месяц " +  QString::number(i+1) + " || Сумма платежа " + QString::number(pay_info.second[i]) +
                     " || Платеж по процентам " + QString::number(pay_info.first[i]);

             ui->listWidget->addItem(info);
             ui->listWidget->addItem(
                         "--------------------------------------------------------------------"
                         "---------------");
         }
          auto total_info = controll_.ammountPercent(ui->lineEdit_cred_inp->text(), pay_info.first);
          ui->lineEdit_total_sum->setText(total_info.second);
         ui->lineEdit_pereplata->setText(total_info.first);
         } catch (...) {
         ui->listWidget->addItem("term or rate must not be zero");
    }
}

