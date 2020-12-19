#include "Calc.h"

bool Calc::Utils::ValidateParentheses(const std::string &expression) {
  std::stack<char> parentheses;

  for (const char &c : expression) {
    if (c == '(') {
      parentheses.push('(');
    } else if (c == ')') {
      if (parentheses.empty()) {
        return false;
      } else {
        parentheses.pop();
      }
    }
  }

  return parentheses.empty();
}

bool Calc::Utils::ValidatePostfix(const std::vector<std::string> &postfix) {
  if (postfix.size() == 1 and OperationsPrecedence.count(postfix[0])) {
    return true;
  }
  if (postfix.size() < 3) {
    return false;
  }
  if (!OperationsPrecedence.count(postfix.back())) {
    return false;
  }

  int counter = 0;
  for (const auto &token : postfix) {
    if (OperationsPrecedence.count(token)) {
      --counter;
    } else {
      ++counter;
    }
  }

  return counter == 1;
}

bool Calc::Utils::CheckIfNumberPart(const char &token) {
  return token == '.' or std::isdigit(token);
}

bool Calc::Utils::CheckIfOperatorOrParenthesis(const char &token) {
  return token == '(' or token == ')' or token == '+' or token == '-' or token == '*' or token == '/';
}

std::vector<std::string> Calc::Utils::GetInfix(std::string expression) {
  std::replace(expression.begin(), expression.end(), ',', '.');
  expression.erase(std::remove(expression.begin(), expression.end(), ' '), expression.end());

  std::string number;
  std::vector<std::string> temp;
  for (const auto &c : expression) {
    if (CheckIfNumberPart(c)) {
      number.push_back(c);
    } else if (CheckIfOperatorOrParenthesis(c)) {
      if (!number.empty()) {
        temp.push_back(number);
        number.clear();

      }
      temp.push_back({c});

    } else {
      std::string err{"Invalid symbol in expression "};
      err += c;
      throw std::domain_error(err);
    }
  }

  if (!number.empty()) {
    temp.push_back(number);
  }

  return temp;
}

std::vector<std::string> Calc::Utils::ConvertInfixToPostfix(const std::vector<std::string> &infix) {
  std::stack<std::string> stack;
  std::vector<std::string> result;

  for (const auto &token : infix) {
    if (token == "(") {
      stack.push(token);
    } else if (OperationsPrecedence.count(token) == 0) {
      result.push_back(token);
    } else if (token == ")") {
      while (stack.top() != "(") {
        result.push_back(stack.top());
        stack.pop();
      }
    } else {
      if (OperationsPrecedence.count(token)) {
        while (OperationsPrecedence.at(stack.top()) >= OperationsPrecedence.at(token)) {
          result.push_back(stack.top());
          stack.pop();
        }
      } else {
        throw std::logic_error("Invalid token: " + token);
      }
      stack.push(token);
    }
  }

  while (!stack.empty()) {
    if (OperationsPrecedence.count(stack.top()) and stack.top() != "(") {
      result.push_back(stack.top());
    }
    stack.pop();
  }

  return result;
}

