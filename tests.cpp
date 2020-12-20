
#include <cassert>
#include <cstring>
#include <iostream>

#include "tests.hpp"
#include "Calc.hpp"

void Tests::RunTests() {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  Test7();
  Test8();
  Test9();
  Test10();
}

void Tests::Test1() {
  Calc::Solver s;
  std::string expression = {"-1 + 5 - 3"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
    assert(result == 1);
    std::cout << "Test 1 Passed" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
void Tests::Test2() {
  Calc::Solver s;
  std::string expression = {"-10+  (8* 2.5) - ( 3 /1,5)"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
    assert(result == 8);
    std::cout << "Test 2 Passed" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
void Tests::Test3() {
  Calc::Solver s;
  std::string expression = {"1 + (2*(2.5+2.5+(3-2)))-(3/ 1.5)"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
    assert(result == 11);
    std::cout << "Test 3 Passed" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
void Tests::Test4() {
  Calc::Solver s;
  std::string expression = {"1.1+2,1+ abc"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
  } catch (const std::exception &e) {
    assert(std::strcmp(e.what(), "Invalid symbol in expression a") == 0);
    std::cout << "Test 4 Passed" << std::endl;
  }
}
void Tests::Test5() {
  Calc::Solver s;
  std::string
      expression = {"                                             1.0         +               2,0             "};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
    assert(result == 3);
    std::cout << "Test 5 Passed" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
void Tests::Test6() {
  Calc::Solver s;
  std::string expression = {"0 / 3"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
    assert(result == 0);
    std::cout << "Test 6 Passed" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
void Tests::Test7() {
  Calc::Solver s;
  std::string expression = {"(5813.123 / 0.1123)*90.1233123 + (45123.1239 - 812.5941* 2123.3123) / 11235.12"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
    assert(result == 4665014.29);
    std::cout << "Test 7 Passed" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
void Tests::Test8() {
  Calc::Solver s;
  std::string expression = {"(4114 + 1234)) / 1923 + 3"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
  } catch (const std::exception &e) {
    assert(std::strcmp(e.what(), "Invalid parentheses order") == 0);
    std::cout << "Test 8 Passed" << std::endl;
  }
}
void Tests::Test9() {
  Calc::Solver s;
  std::string expression = {"(4114 + 1234 + ) / 1923 + 3"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
  } catch (const std::exception &e) {
    assert(std::strcmp(e.what(), "Invalid postfix expression") == 0);
    std::cout << "Test 9 Passed" << std::endl;
  }
}
void Tests::Test10() {
  Calc::Solver s;
  std::string expression = {"(4114 + 1234 ^ 191 ) / 1923 + 3"};
  try {
    s.Parse(expression);
    double result = s.Evaluate();
  } catch (const std::exception &e) {
    assert(std::strcmp(e.what(), "Invalid symbol in expression ^") == 0);
    std::cout << "Test 10 Passed" << std::endl;
  }
}