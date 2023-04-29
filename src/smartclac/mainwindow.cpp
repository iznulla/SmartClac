#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(inputItems()));

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(inputItems()));

    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(inputItems()));

    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(inputItems()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputItems() {
    QPushButton *button = (QPushButton *)sender();

      QString new_label, show_label;
      new_label = (ui->result_show->text() + button->accessibleName());
      show_label = (ui->result_show->text() + button->text());
      ui->result_show->setText(show_label);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->result_show->clear();
}


void MainWindow::on_pushButton_eq_clicked()
{
    double res;
    string tt;
    tt = ui->result_show->text().toStdString();
    res = calc.calculate(tt);
    QString end_calc = QString::number(res, 'g', 14);
    ui->result_show->setText(end_calc);
}

