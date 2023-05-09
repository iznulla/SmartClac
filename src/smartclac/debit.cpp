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

  double rate, sum, months, total = 0.0, percents, tax, part_for_tax,
                            tax_sum = 0.0, add_all = 0.0, sub_all = 0.0;
  sum = ui->lineEdit_sum_dep->text().toDouble();
  months = ui->lineEdit_period->text().toDouble();
  rate = ui->lineEdit_rate->text().toDouble();
  tax = ui->lineEdit_tax->text().toDouble() * 1000000 / 100;

  //    count = QString::QListWidgetItem((*tmp));
  //    qDebug()<<(count);

  while (ui->listWidget_add->count() != 0) {
    add_all += on_pushButton_del_clicked();
    qDebug() << sum;
  }
  sum += add_all;
  while (ui->listWidget_sub->count() != 0) {
    sub_all += on_pushButton_del_2_clicked();
    qDebug() << sum;
  }
  sum -= sub_all;

  total_string = QString::number(add_all);
  ui->lineEdit_add_all->setText(total_string);
  total_string = QString::number(sub_all);
  ui->lineEdit_sub_all->setText(total_string);
  ui->lineEdit_add->setText("0");
  ui->lineEdit_del->setText("0");
  if (ui->comboBox_capital->currentText() == "Ежемесячно") {
    ui->comboBox_peiod_of_pay->setCurrentIndex(0);
    //        percents = (sum * pow((1 + rate * months * AVERAGE_DAYS_IN_MONTH /
    //        365 / 1000), months-1)) - sum;
    percents = (sum * pow((1 + (rate / 100) / 12), months)) - sum;
    //                qDebug()<<(percents);
  } else {
    percents = (sum * rate * months * AVERAGE_DAYS_IN_MONTH / 365) / 100;
  }
  part_for_tax = percents - tax;

  if (part_for_tax > 0 && tax) {
    tax_sum = part_for_tax * NDFL;
  } else {
    tax_sum = 0;
  }

  if (ui->comboBox_peiod_of_pay->currentText() == "Ежемесячно") {
    total = sum;
  } else {
    total = sum + percents - tax_sum;
  }

  total = round(total);
  percents = round(percents);
  line = QString::number(total, 'g', 20);
  ui->lineEdit_total_sum_dep->setText(line);
  line = QString::number(percents, 'g', 20);
  ui->lineEdit_percents->setText(line);
  line = QString::number(tax_sum);
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
    //        qDebug()<<(line);
  }
  return line.toDouble();
}

void Debit::on_pushButton_add_2_clicked() {
  QString line;
  line = ui->lineEdit_del->text();
  ui->listWidget_sub->addItem(line);
}
