#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../calculate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Calculate calc{};

private:
    Ui::MainWindow *ui;

private slots:
    void inputItems();
    void on_pushButton_AC_clicked();
    void on_pushButton_eq_clicked();
friend Calculate;
};
#endif // MAINWINDOW_H