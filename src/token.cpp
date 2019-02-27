#include <string>
#include "../include/token.hpp"

using namespace std;

namespace sc
{
  namespace token
  {
    TokenType getType(char c) {
      string unary = { SIGN, SQR, LN, LOG };
      string binary = "+-*/^%";

      if ((c >= '0' && c <= '9') || c == '.') {
        return NUMBER;
      }
      if (unary.find(c) != string::npos) {
        return UNARY_OPERATOR;
      }
      if (binary.find(c) != string::npos) {
        return BINARY_OPERATOR;
      }
      if (c == '(') {
        return OPENING_BRACKET;
      }
      if (c == ')') {
        return CLOSING_BRACKET;
      }
      return OTHER;
    }

    int getPriority(char c) {
      if (getType(c) == UNARY_OPERATOR || c == '^' || c == '%') {
        return 3;
      }
      if (c == '*' || c == '/') {
        return 2;
      }
      if (c == '+' || c == '-') {
        return 1;
      }
      return 0;
    }
  }
}
