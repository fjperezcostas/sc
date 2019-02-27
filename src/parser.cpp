#include <stack>
#include "../include/exceptions/syntax-error-exception.hpp"
#include "../include/parser.hpp"
#include "../include/token.hpp"

namespace sc
{
  namespace parser
  {
    namespace
    {
      string uglify(string expr)
      {
        string key;
        string::size_type i;

        key = "sqr";
        for (i = 0; (i = expr.find(key,i)) != string::npos; i++) {
          expr.replace(i,key.size(),1,SQR);
        }
        key = "(-";
        for (i = 0; (i = expr.find(key,i)) != string::npos; i++) {
          expr.replace(i+1,1,1,SIGN);
        }
        key = "ln";
        for (i = 0; (i = expr.find(key,i)) != string::npos; i++) {
          expr.replace(i,key.size(),1,LN);
        }
        key = "log";
        for (i = 0; (i = expr.find(key,i)) != string::npos; i++) {
          expr.replace(i,key.size(),1,LOG);
        }
        return expr;
      }

      bool syntaxError(string expr)
      {
        bool dot = false;
        char brackets = 0;

        for (unsigned int i = 0; i < expr.length(); i++) {
          switch (token::getType(expr[i])) {
            case NUMBER:
              if (expr[i] == '.') {
                if (dot) {
                  return true;
                }
                dot = true;
              }
              if (token::getType(expr[i+1]) != NUMBER) {
                dot = false;
              }
              break;
            case BINARY_OPERATOR:
              if (i == 0 || (token::getType(expr[i-1]) != NUMBER && expr[i-1] != ')')) {
                return true;
              }
            case UNARY_OPERATOR:
              if (expr[i+1] != '(' && token::getType(expr[i+1]) != NUMBER && token::getType(expr[i+1]) != UNARY_OPERATOR) {
                return true;
              }
              break;
            case OPENING_BRACKET:
              brackets++;
              break;
            case CLOSING_BRACKET:
              if (brackets <= 0) {
                return true;
              }
              brackets--;
              break;
            default:
              return true;
          }
        }
        if (brackets != 0) {
          return true;
        }
        return false;
      }

      string infixToPostfix(string expr)
      {
        string postfix = "";
        stack<char> _stack;

        for (unsigned int i = 0; i < expr.length(); i++) {
          switch (token::getType(expr[i])) {
            case NUMBER:
              postfix += expr[i];
              if (token::getType(expr[i+1]) != NUMBER) {
                postfix += ' ';
              }
              break;;
            case UNARY_OPERATOR:
              while (!_stack.empty() && token::getPriority(expr[i]) < token::getPriority(_stack.top())) {
                postfix += _stack.top();
                _stack.pop();
              }
              _stack.push(expr[i]);
              break;
            case BINARY_OPERATOR:
              while (!_stack.empty() && token::getPriority(expr[i]) <= token::getPriority(_stack.top())) {
                postfix += _stack.top();
                _stack.pop();
              }
              _stack.push(expr[i]);
              break;
            case OPENING_BRACKET:
              _stack.push('(');
              break;
            case CLOSING_BRACKET:
              while (!_stack.empty() && _stack.top() != '(') {
                postfix += _stack.top();
                _stack.pop();
              }
              if (!_stack.empty()) {
                _stack.pop();
              }
              break;
            case OTHER:
              break;
          }
        }
        while (!_stack.empty()) {
          postfix += _stack.top();
          _stack.pop();
        }
        return postfix;
      }
    }

    string parse(string expr)
    {
      expr = uglify(expr);
      if (syntaxError(expr)) {
        throw exceptions::SyntaxErrorException();
      }
      expr = infixToPostfix(expr);
      return expr;
    }
  }
}