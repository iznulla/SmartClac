#include <iostream>
#include <math.h>

constexpr double AVERAGE_DAYS_IN_MONTH = 30.416666666666667851;
constexpr double NDFL = 13.00/100.00;

struct DepositCalcing{
    double total{};
    double percents{};
    double tax_sum{};
    double sum{};
    double months{};
    double rate{};
    double tax{};

    double percent(int choos) {
        if (choos) {
            return (sum * pow((1 + (rate / 100) / 12), months)) - sum;
        } else {
            return (sum * rate * months * AVERAGE_DAYS_IN_MONTH / 365) / 100;
        }
    }

    std::pair<double, double> taxSum(int choos) {
        double percents_res = percent(choos);
        double part_for_tax = percents_res - tax;
        double tax_sum_res{};
        if (part_for_tax > 0 && tax) {
            tax_sum_res = part_for_tax * NDFL;
        } else {
            tax_sum_res = 0;
        }
       return std::pair(tax_sum_res, percents_res);
    }
    void debitInitCalc(int choos){
        tax = tax * 1000000 / 100;
        auto tax_and_percent = taxSum(choos);
        tax_sum = tax_and_percent.first;
        percents = tax_and_percent.second;
        if (choos) {
            total = sum;
        } else {
            total = sum + percents - tax_sum;
        }
    }
};
