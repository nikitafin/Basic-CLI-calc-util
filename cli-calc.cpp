#include <iostream>
#include <string>

#include "Calc.hpp"
#include "tests.hpp"

int main() {
  Tests tests;
  tests.RunTests();

  std::string expression;
  Calc::Solver solver;

  try {
    std::getline(std::cin, expression);
    solver.Parse(expression);
    double result = solver.Evaluate();
    std::cout << result << std::endl;

  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}