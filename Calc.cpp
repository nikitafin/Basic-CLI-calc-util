#include "Calc.hpp"

Calc::Solver::Solver() = default;

void Calc::Solver::Parse(const std::string &expression) {
  if (!Utils::ValidateParentheses(expression)) {
    throw std::logic_error("Invalid parentheses order");
  }

  auto infix = Utils::GetInfix(expression);
  postfix = Utils::ConvertInfixToPostfix(infix);

  if (!Utils::ValidatePostfix(postfix)) {
    throw std::logic_error("Invalid postfix expression");
  }
}

double Calc::Solver::Evaluate() {

  std::stack<double> operands;

  for (const auto &token: postfix) {
    if (OperationsPrecedence.count(token)) {
      double right = operands.top();
      operands.pop();
      double left = operands.top();
      operands.pop();
      if (token == "+") {
        operands.push(left + right);
      } else if (token == "-") {
        operands.push(left - right);
      } else if (token == "*") {
        operands.push(left * right);
      } else {
        if (right == 0) {
          throw std::domain_error("Division by zerro");
        }
        operands.push(left / right);
      }
    } else {
      operands.push(stod(token));
    }
  }
  return std::round(operands.top() * 100) / 100;
}
