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

    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(inputOperators()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(inputOperators()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(inputOperators()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(inputOperators()));

    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(inputItems()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(inputItems()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputItems() {
    QPushButton *button = (QPushButton *)sender();
    calc_text.append(button->accessibleName());
    ui->result_show->setText(ui->result_show->text() + button->text());
}
void MainWindow::inputOperators() {
    QPushButton *button = (QPushButton *)sender();
    calc_text.append(button->accessibleName());
    ui->result_show->setText(ui->result_show->text() + button->text());
    --check_dot;
}
void MainWindow::on_pushButton_AC_clicked()

{
    ui->widget->clearGraphs();
    ui->widget->replot();
    check_dot = 0, check_scope = 0;
    ui->result_show->clear();
    calc_text.clear();

}

void MainWindow::on_pushButton_Del_clicked()
{
    if (!calc_text.isEmpty())
    {
        calc_text.chop(1);
        ui->result_show->setText(ui->result_show->text().chopped(1));
    }

}


void MainWindow::on_pushButton_dot_clicked()
{
    if (!check_dot) {
        calc_text.append(".");
        ui->result_show->setText(ui->result_show->text() + ".");
        check_dot++;
    }
}
void MainWindow::on_pushButton_eq_clicked()
{
    try {
        calc.calcs(calc_text);
        ui->result_show->setText(calc_text);
        calc_text.clear();
    }
    catch (...) {
        ui->result_show->clear();
        ui->result_show->setText("ERROR");
    }
}

void MainWindow::on_pushButton_scop_open_clicked()
{
    calc_text.append("(");
    ui->result_show->setText(ui->result_show->text() + "(");
    ++check_dot;
    ++check_scope;
}

void MainWindow::on_pushButton_scop_close_clicked()
{
    calc_text.append(")");
    ui->result_show->setText(ui->result_show->text() + ")");
    check_dot++;
}


void MainWindow::on_pushButton_graphic_clicked()
{
    ui->widget->clearGraphs();
    double xB = ui->doubleSpinBox_xBegin->text().toDouble();
    double xE = ui->doubleSpinBox_xEnd->text().toDouble();

    ui->widget->xAxis->setRange(xB, xE);
    ui->widget->yAxis->setRange(xB, xE);
    try {
        auto getXY = calc.drawPlot(xB, xE, calc_text);
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(getXY.first,getXY.second);
        ui->widget->replot();
        getXY.first.clear();
        getXY.second.clear();
    }
    catch (...) {
        ui->result_show->clear();
        ui->result_show->setText("ERROR");
    }

}


void MainWindow::on_pushButton_credit_clicked()
{
    credit.show();
}

