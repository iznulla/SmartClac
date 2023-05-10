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
  QString line, total_string;

  double add_all = 0.0, sub_all = 0.0;
  deposit_calcing_.sum = ui->lineEdit_sum_dep->text().toDouble();
  deposit_calcing_.months = ui->lineEdit_period->text().toDouble();
  deposit_calcing_.rate = ui->lineEdit_rate->text().toDouble();
  deposit_calcing_.tax = ui->lineEdit_tax->text().toDouble();


  while (ui->listWidget_add->count() != 0) {
    add_all += on_pushButton_del_clicked();
  }
  deposit_calcing_.sum += add_all;
  while (ui->listWidget_sub->count() != 0) {
    sub_all += on_pushButton_del_2_clicked();
  }
  deposit_calcing_.sum -= sub_all;

  deposit_calcing_.debitInitCalc(ui->comboBox_capital->currentIndex());

  total_string = QString::number(add_all);
  ui->lineEdit_add_all->setText(total_string);
  total_string = QString::number(sub_all);
  ui->lineEdit_sub_all->setText(total_string);


  deposit_calcing_.total = round(deposit_calcing_.total);
  deposit_calcing_.percents = round(deposit_calcing_.percents);
  line = QString::number(deposit_calcing_.total, 'g', 20);
  ui->lineEdit_total_sum_dep->setText(line);
  line = QString::number(deposit_calcing_.percents, 'g', 20);
  ui->lineEdit_percents->setText(line);
  line = QString::number(deposit_calcing_.tax_sum);
  ui->lineEdit_tax_sum->setText(line);
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
