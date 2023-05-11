#include <gtest/gtest.h>

// #include <iosetream>

#include "../calculate.h"

class TestCalculate : public ::testing::Test {
public:
  s21::Checks check;
  s21::Calculate calc;
};

TEST_F(TestCalculate, inputValidationTest) {
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  EXPECT_EQ(check.inputCheck("12543"), 1);
  EXPECT_EQ(check.inputCheck("@(-5)"), 1);
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

TEST_F(TestCalculate, Calculating) {
  EXPECT_EQ(calc.calculate("5+5"), 10);
  EXPECT_EQ(calc.calculate("5*(-3)"), -15);
  EXPECT_NEAR(calc.calculate("5/3"), 1.6666667, 0.0000001);

  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  EXPECT_NEAR(calc.calculate("2*(3+1)*2"), 16, 0.0000001);
  EXPECT_NEAR(calc.calculate("2*(((3+1)-1))*2"), 12, 0.0000001);
  EXPECT_NEAR(calc.calculate("(3+5)*2+3/(1-4)"), 15, 0.0000001);
  EXPECT_NEAR(calc.calculate("12.543+(2+(2-1)+12)+543+(2+(2-1))"), 573.543,
              0.0000001);
  EXPECT_NEAR(calc.calculate("1+2+3+(3+5)*2+3/(1-4)-3*(3+((2+1)+1))/(((1)))+2"),
              2, 0.0000001);
  EXPECT_NEAR(calc.calculate("2+((-(-3+5)))"), 0, 0.0000001);
  EXPECT_NEAR(calc.calculate("1+2+3+(3+5)*2+3/(1-4)^3*(3^((2+1)+1))/(((1)))+2"),
              15, 0.0000001);
  EXPECT_NEAR(
      calc.calculate("1+2+3+(3+5)^2+3^(1-4)*3^(3*((2+1)+1))/(((1)))+2^1"),
      19755, 0.0000001);
  EXPECT_NEAR(calc.calculate("2^3^1-4*2^1"), 0, 0.0000001);
  EXPECT_NEAR(calc.calculate("@(4)+9+2^3"), 16.2431975, 0.0000001);
  EXPECT_NEAR(
      calc.calculate("5+(1+2)*4*(1)*!(2*5-2)+u(u(2*5))-u(2^u(5-1))+u(5)"),
      4.7365639, 0.0000001);
  EXPECT_NEAR(calc.calculate("@(2*5-2)"), 0.9893582, 0.0000001);
  EXPECT_NEAR(
      calc.calculate("v(4)+9.235+2^3^@(!(10))-564-u(25)+28.6*35%99^2^3"),
      445.7000340, 0.0000001);
  EXPECT_NEAR(calc.calculate("-4+9.235+2^3^u(#(10))-564-v(25)+28.6*35%99^2^3"),
              442.2423793, 0.0000001);
  EXPECT_NEAR(calc.calculate("12.543+!(2+@(2-1)+12)+543+!(2+@(2-1))"),
              553.9401958, 0.0000001);
  EXPECT_NEAR(calc.calculate("2+1-3+9*12/3+31*241"), 7507, 0.0000001);
  //   //   EXPECT_NEAR(calc.calculate("5^@(1)^2"), 3.1255185, 0.0000001);
  //   //   cout << calc.calculate("5^@(1)^2") << endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
