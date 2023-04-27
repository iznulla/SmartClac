#include <gtest/gtest.h>

#include <iostream>

#include "calculate.h"

class TestCalculate : public ::testing::Test {
 public:
  Checks check;
  Parser parsing_polish;
  Calculate calc;
};

TEST_F(TestCalculate, inputValidationTest) {
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  EXPECT_EQ(check.inputCheck("12543"), 1);
  EXPECT_EQ(check.inputCheck("125^+43"), 0);
  EXPECT_EQ(check.inputCheck("12.5^43"), 1);
  EXPECT_EQ(check.inputCheck("12.543"), 1);
  EXPECT_EQ(check.inputCheck("12.543^"), 0);
  EXPECT_EQ(check.inputCheck("((2-1))"), 1);
  EXPECT_EQ(check.inputCheck("((2-1))1"), 0);
  EXPECT_EQ(check.inputCheck("((2-1)-)"), 0);
  EXPECT_EQ(check.inputCheck("((2-1))+1"), 1);
  EXPECT_EQ(check.inputCheck("12.543+((2-1))"), 1);
  EXPECT_EQ(check.inputCheck("12.543((2-1))"), 0);
  EXPECT_EQ(check.inputCheck("12.543+!(@(2-1)+12)"), 1);
  EXPECT_EQ(check.inputCheck("12.543+!(@(2-1)+12-)"), 0);
  EXPECT_EQ(check.inputCheck("12.543+!(2+@(2-1)+12)543+!(2+@(2-1))"), 0);
  EXPECT_EQ(check.inputCheck("12.543+!(2+@(2-1)+12)+543+!(2+@(2-1))"), 1);
  EXPECT_EQ(
      check.inputCheck("@(4)+9.235+2^3^!(#(10))-564-@(25)+28.6*35%99^2^3"), 1);
  EXPECT_EQ(
      check.inputCheck("5+(1+2)*4*(-1)*@(2*7.5-2)+!(@(2*5))-#(2^_(5-1))+$(55)"),
      1);
  EXPECT_EQ(
      check.inputCheck("1+2+3+(-3+5)*2+3/(1-4)^3*(3^((2+1)+1))/(((1)))+2"), 1);
  EXPECT_EQ(
      check.inputCheck("5+(1+2)*4*(1)*@(2*5-2)+!(@(2*5))-#(2^_(5-1))+$(*55)"),
      1);
  EXPECT_EQ(check.inputCheck("(-2*5-2)"), 1);
  EXPECT_EQ(check.inputCheck("+2*5-2"), 1);
  EXPECT_EQ(check.inputCheck("2*5-2"), 1);
  EXPECT_EQ(check.inputCheck("@(2*5-2)"), 1);
}

TEST_F(TestCalculate, checks) {
  calc.calculate("1+2+3+(-3+5)*2+3/(1-4)^3*(3^((2+1)+1))/(((1)))+2");
  calc.print();
}
// TEST_F(TestCalculate, ParsingTest) {
//   // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
//   //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
//   parsing_polish.pars_to_polish("2*(3+1)*2");
//   EXPECT_EQ(parsing_polish.check_pars(), "231+*2*");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("2*((3+1)-1)*2");
//   EXPECT_EQ(parsing_polish.check_pars(), "231+1-*2*");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("2*(((3+1)-1)*2)");
//   EXPECT_EQ(parsing_polish.check_pars(), "231+1-2**");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("(3+5)*2+3/(1-4)");
//   EXPECT_EQ(parsing_polish.check_pars(), "35+2*314-/+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("12.543+(2+(2-1)+12)+543+(2+(2-1))");
//   EXPECT_EQ(parsing_polish.check_pars(), "12.543221-+12++543+221-++");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "1+2+3+(3+5)*2+3/(1-4)-3*(3+((2+1)+1))/(((1)))+2");
//   EXPECT_EQ(parsing_polish.check_pars(),
//   "12+3+35+2*+314-/+3321+1++*1/-2+"); parsing_polish.clear();
//   parsing_polish.pars_to_polish("2+3/(1-4)-3");
//   EXPECT_EQ(parsing_polish.check_pars(), "2314-/+3-");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("2+(((-3+5)))");
//   EXPECT_EQ(parsing_polish.check_pars(), "203-5++");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("2+((-(-3+5)))");
//   EXPECT_EQ(parsing_polish.check_pars(), "2003-5+-+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("2+(+3)+5");
//   EXPECT_EQ(parsing_polish.check_pars(), "23++5+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "1+2+3+(3+5)*(-2)+3/(-1-4)-3*(-3+((2+1)+1))/(((-1)))+2");
//   EXPECT_EQ(parsing_polish.check_pars(),
//             "12+3+35+02-*+301-4-/+303-21+1++*01-/-2+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "1+2+3+(3+5)*2+3/(1-4)^3*(3^((2+1)+1))/(((1)))+2");
//   EXPECT_EQ(parsing_polish.check_pars(),
//   "12+3+35+2*+314-3^/321+1+^*1/+2+"); parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "1+2+3+(3+5)^2+3^(1-4)*3^(3*((2+1)+1))/(((1)))+2^1");
//   EXPECT_EQ(parsing_polish.check_pars(),
//   "12+3+35+2^+314-^3321+1+*^*1/+21^+"); parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "1+2+3+(3+5)+2^3^1-4*3+(3*((2+1)+1))/(((1)))+2^1");
//   EXPECT_EQ(parsing_polish.check_pars(),
//   "12+3+35++231^^+43*-321+1+*1/+21^+"); parsing_polish.clear();
//   parsing_polish.pars_to_polish("2^3^1-4*2^1");
//   EXPECT_EQ(parsing_polish.check_pars(), "231^^421^*-");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("@(4)+9+2^3");
//   EXPECT_EQ(parsing_polish.check_pars(), "4@9+23^+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "5+(1+2)*4*(1)*!(2*5-2)+u(u(2*5))-u(2^u(5-1))+u(5)");
//   EXPECT_EQ(parsing_polish.check_pars(),
//   "512+4*1*25*2-!*+25*uu+251-u^u-5u+"); parsing_polish.clear();
//   parsing_polish.pars_to_polish("@(2*5-2)");
//   EXPECT_EQ(parsing_polish.check_pars(), "25*2-@");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "u(4)+9.235+2^3^u(u(10))-564-u(25)+28.6*35%99^2^3");
//   EXPECT_EQ(parsing_polish.check_pars(),
//             "4u9.235+2310uu^^+564-25u-28.635*9923^^%+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish(
//       "-u(4)+9.235+2^3^u(u(10))-564-u(25)+28.6*35%99^2^3");
//   EXPECT_EQ(parsing_polish.check_pars(),
//             "04u-9.235+2310uu^^+564-25u-28.635*9923^^%+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("12.543+!(2+@(2-1)+12)+543+!(2+@(2-1))");
//   EXPECT_EQ(parsing_polish.check_pars(), "12.543221-@+12+!+543+221-@+!+");
//   parsing_polish.clear();
//   parsing_polish.pars_to_polish("1+!(2+@(2-1)+12)+5+!(2+@(2-1))");
//   parsing_polish.print();

//   EXPECT_EQ(parsing_polish.check_pars(), "221-@+4+!5+221-@+!+");
//   parsing_polish.print();
//   EXPECT_DOUBLE_EQ(calc.calcAll("2+1-3+9"), 9)
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
// EXPECT_EQ(check.inputCheck("125^+43"), 0);
// EXPECT_EQ(check.inputCheck("12..5^43"), 0);
// EXPECT_EQ(check.inputCheck("12.543"), 1);
// EXPECT_EQ(check.inputCheck("12.543^"), 0);
// EXPECT_EQ(check.inputCheck("((2-1))"), 1);
// EXPECT_EQ(check.inputCheck("((2-1))1"), 0);
// EXPECT_EQ(check.inputCheck("((2-1)-)"), 0);
// EXPECT_EQ(check.inputCheck("((2-1))+1"), 1);
// EXPECT_EQ(check.inputCheck("12.543+((2-1))"), 1);
// EXPECT_EQ(check.inputCheck("12.543((2-1))"), 0);
// EXPECT_EQ(check.inputCheck("12.543+!(@(2-1)+12)"), 1);
// EXPECT_EQ(check.inputCheck("12.543+!(@(2-1)+12-)"), 0);
// EXPECT_EQ(check.inputCheck("12.543+!(2+@(2-1)+12)543+!(2+@(2-1))"), 0);
// EXPECT_EQ(check.inputCheck("12.543+!(2+@(2-1)+12)+543+!(2+@(2-1))"), 1);
// EXPECT_EQ(
//     check.inputCheck("@(4)+9.235+2^3^!(#(10))-564-@(25)+28.6*35%99^2^3"),
//     1);
// EXPECT_EQ(
//     check.inputCheck("5+(1+2)*4*(1)*@(2*7.5-2)+!(@(2*5))-#(2^_(5-1))+$(55)"),
//     1);
// EXPECT_EQ(
//     check.inputCheck("1+2+3+(3+5)*2+3/(1-4)^3*(3^((2+1)+1))/(((1)))+2"),
//     1);
// // EXPECT_EQ(
// //
// check.inputCheck("5+(1+2)*4*(1)*@(.2*5-2)+!(@(2*5))-#(2^_(5-1))+$(*55)"),
// //     0);
// EXPECT_EQ(check.inputCheck("(-2*5-2)"), 1);
// EXPECT_EQ(check.inputCheck("+2*5-2"), 1);
// EXPECT_EQ(check.inputCheck(".2*5-2"), 0);
// EXPECT_EQ(check.inputCheck("@(2*5-2)"), 1);
// }