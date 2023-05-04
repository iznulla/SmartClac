#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QDialog>

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreditWindow *ui;
    double sum_line, precent_line, month_line;
};

#endif // CREDITWINDOW_H
