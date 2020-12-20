#pragma once

#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>

namespace Calc {

  const std::unordered_map<std::string, int> OperationsPrecedence{
      {"*", 2},
      {"/", 2},
      {"+", 1},
      {"-", 1},
      {"(", 0},
      {")", 0}
  };

  class Utils {
  public:
    static bool CheckIfNumberPart(const char &c);
    static bool CheckIfOperatorOrParenthesis(const char &token);

    static bool ValidatePostfix(const std::vector<std::string> &postfix);
    static bool ValidateParentheses(const std::string &expression);
    static std::vector<std::string> GetInfix(std::string expression);
    static std::vector<std::string> ConvertInfixToPostfix(const std::vector<std::string> &infix);
  };

  class Solver {
  public:
    Solver();
    void Parse(const std::string &expression);
    double Evaluate();
  private:
    std::vector<std::string> postfix;
  };
}