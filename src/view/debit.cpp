#include "debit.h"

#include <QDebug>

#include "ui_debit.h"

Debit::Debit(QWidget *parent) : QDialog(parent), ui(new Ui::Debit) {
  ui->setupUi(this);
  ui->lineEdit_sum_dep->setValidator(new QDoubleValidator(this));
  ui->lineEdit_period->setValidator(new QDoubleValidator(this));
  ui->lineEdit_rate->setValidator(new QDoubleValidator(this));
  ui->lineEdit_tax->setValidator(new QDoubleValidator(this));
  ui->lineEdit_add->setValidator(new QDoubleValidator(this));
  ui->lineEdit_del->setValidator(new QDoubleValidator(this));
  ui->lineEdit_add_all->setValidator(new QDoubleValidator(this));
  ui->lineEdit_sub_all->setValidator(new QDoubleValidator(this));
}

Debit::~Debit() { delete ui; }

void Debit::on_pushButton_calculate_clicked() {
  double add_all{}, sub_all{};
  double sum = ui->lineEdit_sum_dep->text().toDouble();

  while (ui->listWidget_add->count() != 0) {
    add_all += on_pushButton_del_clicked();
  }
  sum += add_all;
  while (ui->listWidget_sub->count() != 0) {
    sub_all += on_pushButton_del_2_clicked();
  }
  sum -= sub_all;

  double months = ui->lineEdit_period->text().toDouble();
  double rate = ui->lineEdit_rate->text().toDouble();
  double tax = ui->lineEdit_tax->text().toDouble();
  int choosed_capytal = ui->comboBox_capital->currentIndex();
  int choosed_period = ui->comboBox_peiod_of_pay->currentIndex();

  controll_.depositCalc(sum, months, rate, tax, choosed_capytal,
                        choosed_period);

  QString total_string;
  total_string = QString::number(add_all);
  ui->lineEdit_add_all->setText(total_string);
  total_string = QString::number(sub_all);
  ui->lineEdit_sub_all->setText(total_string);

  auto percent_tax_sum = controll_.getDepositPercentsAndTaxSum();
  ui->lineEdit_total_sum_dep->setText(controll_.getDepositTotal());
  ui->lineEdit_percents->setText(percent_tax_sum.first);
  ui->lineEdit_tax_sum->setText(percent_tax_sum.second);
}

double Debit::on_pushButton_del_clicked() {
  QString line = "";
  if (ui->listWidget_add->count() != 0) {
    line =
        ui->listWidget_add->takeItem(ui->listWidget_add->count() - 1)->text();
  }
  return line.toDouble();
}

void Debit::on_pushButton_add_clicked() {
  QString line;
  line = ui->lineEdit_add->text();
  ui->listWidget_add->addItem(line);
}

double Debit::on_pushButton_del_2_clicked() {
  QString line = "";
  if (ui->listWidget_sub->count() != 0) {
    line =
        ui->listWidget_sub->takeItem(ui->listWidget_sub->count() - 1)->text();
  }
  return line.toDouble();
}

void Debit::on_pushButton_add_2_clicked() {
  QString line;
  line = ui->lineEdit_del->text();
  ui->listWidget_sub->addItem(line);
}
