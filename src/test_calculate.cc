#include <gtest/gtest.h>

#include <iostream>

#include "calculate.h"

class TestCalculate : public ::testing::Test {
 public:
  Checks check;
  Calculate calc;
};

TEST_F(TestCalculate, inputValidationTest) {
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  EXPECT_EQ(check.input_check("12543"), 1);
  EXPECT_EQ(check.input_check("125^+43"), 0);
  EXPECT_EQ(check.input_check("12..5^43"), 0);
  EXPECT_EQ(check.input_check("12.543"), 1);
  EXPECT_EQ(check.input_check("12.543^"), 0);
  EXPECT_EQ(check.input_check("((2-1))"), 1);
  EXPECT_EQ(check.input_check("((2-1))1"), 0);
  EXPECT_EQ(check.input_check("((2-1)-)"), 0);
  EXPECT_EQ(check.input_check("((2-1))+1"), 1);
  EXPECT_EQ(check.input_check("12.543+((2-1))"), 1);
  EXPECT_EQ(check.input_check("12.543((2-1))"), 0);
  EXPECT_EQ(check.input_check("12.543+!(@(2-1)+12)"), 1);
  EXPECT_EQ(check.input_check("12.543+!(@(2-1)+12-)"), 0);
  EXPECT_EQ(check.input_check("12.543+!(2+@(2-1)+12)543+!(2+@(2-1))"), 0);
  EXPECT_EQ(check.input_check("12.543+!(2+@(2-1)+12)+543+!(2+@(2-1))"), 1);
  EXPECT_EQ(
      check.input_check("@(4)+9.235+2^3^!(#(10))-564-@(25)+28.6*35%99^2^3"), 1);
  EXPECT_EQ(
      check.input_check("5+(1+2)*4*(1)*@(2*7.5-2)+!(@(2*5))-#(2^_(5-1))+$(55)"),
      1);
  EXPECT_EQ(
      check.input_check("1+2+3+(3+5)*2+3/(1-4)^3*(3^((2+1)+1))/(((1)))+2"), 1);
  // EXPECT_EQ(
  //     check.input_check("5+(1+2)*4*(1)*@(.2*5-2)+!(@(2*5))-#(2^_(5-1))+$(*55)"),
  //     0);
  EXPECT_EQ(check.input_check("(-2*5-2)"), 1);
  EXPECT_EQ(check.input_check("+2*5-2"), 1);
  EXPECT_EQ(check.input_check(".2*5-2"), 0);
  EXPECT_EQ(check.input_check("@(2*5-2)"), 1);
}

TEST_F(TestCalculate, ParsingTest) {
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  calc.pars_and_calc("2*(3+1)*2");
  EXPECT_EQ(calc.check_pars(), "231+*2*");
  calc.clear();
  calc.pars_and_calc("2*((3+1)-1)*2");
  EXPECT_EQ(calc.check_pars(), "231+1-*2*");
  calc.clear();
  calc.pars_and_calc("2*(((3+1)-1)*2)");
  EXPECT_EQ(calc.check_pars(), "231+1-2**");
  calc.clear();
  calc.pars_and_calc("(3+5)*2+3/(1-4)");
  EXPECT_EQ(calc.check_pars(), "35+2*314-/+");
  calc.print();
  //   EXPECT_DOUBLE_EQ(calc.calcAll("2+1-3+9"), 9);
  //   calc.clear();
  //   EXPECT_DOUBLE_EQ(calc.calcAll("2*1+3"), 5);
  //   calc.clear();
  //   EXPECT_DOUBLE_EQ(calc.calcAll("2*1+3/1"), 5);
  //   calc.clear();
  //   EXPECT_DOUBLE_EQ(calc.calcAll("2+1+3/2"), 4.5);
  //   calc.clear();
  //   EXPECT_DOUBLE_EQ(calc.calcAll("2+1-3+9*12/3+31*241"), 7507);
  //   calc.clear();
  // //  EXPECT_DOUBLE_EQ(calc.calcAll("2+1-3+2*2*(3+1)*2"), 32);
  // //  calc.clear();
  //   EXPECT_DOUBLE_EQ(calc.calcAll("2+1-3+9*12"), 108);
  // calc.print();
  // EXPECT_EQ(calc.init_stack("1+2"), 3);
  // EXPECT_EQ(check.input_check("125^+43"), 0);
  // EXPECT_EQ(check.input_check("12..5^43"), 0);
  // EXPECT_EQ(check.input_check("12.543"), 1);
  // EXPECT_EQ(check.input_check("12.543^"), 0);
  // EXPECT_EQ(check.input_check("((2-1))"), 1);
  // EXPECT_EQ(check.input_check("((2-1))1"), 0);
  // EXPECT_EQ(check.input_check("((2-1)-)"), 0);
  // EXPECT_EQ(check.input_check("((2-1))+1"), 1);
  // EXPECT_EQ(check.input_check("12.543+((2-1))"), 1);
  // EXPECT_EQ(check.input_check("12.543((2-1))"), 0);
  // EXPECT_EQ(check.input_check("12.543+!(@(2-1)+12)"), 1);
  // EXPECT_EQ(check.input_check("12.543+!(@(2-1)+12-)"), 0);
  // EXPECT_EQ(check.input_check("12.543+!(2+@(2-1)+12)543+!(2+@(2-1))"), 0);
  // EXPECT_EQ(check.input_check("12.543+!(2+@(2-1)+12)+543+!(2+@(2-1))"), 1);
  // EXPECT_EQ(
  //     check.input_check("@(4)+9.235+2^3^!(#(10))-564-@(25)+28.6*35%99^2^3"),
  //     1);
  // EXPECT_EQ(
  //     check.input_check("5+(1+2)*4*(1)*@(2*7.5-2)+!(@(2*5))-#(2^_(5-1))+$(55)"),
  //     1);
  // EXPECT_EQ(
  //     check.input_check("1+2+3+(3+5)*2+3/(1-4)^3*(3^((2+1)+1))/(((1)))+2"),
  //     1);
  // // EXPECT_EQ(
  // //
  // check.input_check("5+(1+2)*4*(1)*@(.2*5-2)+!(@(2*5))-#(2^_(5-1))+$(*55)"),
  // //     0);
  // EXPECT_EQ(check.input_check("(-2*5-2)"), 1);
  // EXPECT_EQ(check.input_check("+2*5-2"), 1);
  // EXPECT_EQ(check.input_check(".2*5-2"), 0);
  // EXPECT_EQ(check.input_check("@(2*5-2)"), 1);
}