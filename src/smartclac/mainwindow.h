#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "creditwindow.h"
//#include "../controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Control calc{};
    CreditWindow credit;
    QString calc_text;

private:
    int check_dot;
    int check_scope;


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
};
#endif // MAINWINDOW_H
