#ifndef DEBIT_H
#define DEBIT_H

#include <QDialog>

constexpr double AVERAGE_DAYS_IN_MONTH = 30.416666666666667851;
constexpr double NDFL = 13.00/100.00;

namespace Ui {
class Debit;
}

class Debit : public QDialog
{
    Q_OBJECT

public:
    explicit Debit(QWidget *parent = nullptr);
    ~Debit();

private slots:
    void on_pushButton_calculate_clicked();

    double on_pushButton_del_clicked();

    void on_pushButton_add_clicked();

    double on_pushButton_del_2_clicked();

    void on_pushButton_add_2_clicked();


private:
    Ui::Debit *ui;
};

#endif // DEBIT_H
