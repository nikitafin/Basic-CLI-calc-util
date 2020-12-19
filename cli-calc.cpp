#include <iostream>
#include <string>

#include "Calc.h"

int main() {

  std::string expression{"(1.1 + 2,2 + 3 ) * (1 + 2)"};

  Calc::Solver solver;

  try {
    //std::cin >> expression;
    solver.Parse(expression);
    double result = solver.Evaluate();
    std::cout << result << std::endl;

  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}