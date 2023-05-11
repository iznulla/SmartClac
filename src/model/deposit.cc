#include "deposit.h"


void s21::DepositCalcing::initData (double sum_v, double months_v, double rate_v, double tax_v) {
        sum = sum_v;
        months = months_v;
        rate = rate_v;
        tax = tax_v;
    }

    double s21::DepositCalcing::percent(int choos) {

        if (choos) {
            return (sum * pow((1 + (rate / 100) / 12), months)) - sum;
        } else {
            return (sum * rate * months * AVERAGE_DAYS_IN_MONTH / 365) / 100;
        }
    }

    std::pair<double, double> s21::DepositCalcing::taxSum(int choos) {
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
    void s21::DepositCalcing::debitCalcResult(int choos_capyt, int choos_period) {

        auto tax_and_percent = taxSum(choos_capyt);
        tax_sum = tax_and_percent.first;
        percents = tax_and_percent.second;
        if (choos_period) {
            total = sum;
        } else {
            total = sum + percents - tax_sum;
        }
    }

