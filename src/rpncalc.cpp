#include <cmath>
#include <cstdlib>
#include <stack>
#include "../include/exceptions/infinite-number-exception.hpp"
#include "../include/exceptions/nan-exception.hpp"
#include "../include/exceptions/stack-error-exception.hpp"
#include "../include/exceptions/syntax-error-exception.hpp"
#include "../include/consts.hpp"
#include "../include/rpncalc.hpp"
#include "../include/token.hpp"

namespace sc
{
  namespace rpncalc
  {
    double eval(string expr)
    {
      string num;
      stack<double> _stack;
      double aux = 0.0;

      for (unsigned int i = 0; i < expr.length(); i++) {
        switch (token::getType(expr[i])) {
          case NUMBER:
            num = "";
            while (token::getType(expr[i]) == NUMBER) {
              num += expr[i++];
            }
            _stack.push(atof(num.c_str()));
            break;
          case UNARY_OPERATOR:
            if (_stack.empty()) {
              throw exceptions::StackErrorException();
            }
            switch (expr[i]) {
              case SIGN:
                aux = _stack.top() * -1.0;
                _stack.pop();
                _stack.push(aux);
                break;
              case SQR:
                aux = sqrt(_stack.top());
                _stack.pop();
                _stack.push(aux);
                break;
              case LN:
                aux = log(_stack.top());
                _stack.pop();
                _stack.push(aux);
                break;
              case LOG:
                aux = log10(_stack.top());
                _stack.pop();
                _stack.push(aux);
                break;
            }
            break;
          case BINARY_OPERATOR:
            if (_stack.size() < 2) {
              throw exceptions::StackErrorException();
            }
            switch (expr[i]) {
              case '+':
                aux = _stack.top();
                _stack.pop();
                aux +=  _stack.top();
                _stack.pop();
                _stack.push(aux);
                break;
              case '-':
                aux = _stack.top();
                _stack.pop();
                aux = _stack.top() - aux;
                _stack.pop();
                _stack.push(aux);
                break;
              case '*':
                aux = _stack.top();
                _stack.pop();
                aux *= _stack.top();
                _stack.pop();
                _stack.push(aux);
                break;
              case '/':
                aux = _stack.top();
                _stack.pop();
                aux = _stack.top() / aux;
                _stack.pop();
                _stack.push(aux);
                break;
              case '%':
                aux = _stack.top();
                _stack.pop();
                aux = _stack.top() / 100.0 * aux;
                _stack.pop();
                _stack.push(aux);
                break;
              case '^':
                aux = _stack.top();
                _stack.pop();
                aux = pow(_stack.top(),aux);
                _stack.pop();
                _stack.push(aux);
                break;
           }
           break;
          case OTHER:
          default:
            throw exceptions::SyntaxErrorException();
        }
      }
      if (_stack.size() != 1) {
        throw exceptions::StackErrorException();
      }
      double result = _stack.top();
      if (isinf(result)) {
        throw exceptions::InfiniteNumberException();
      }
      if (isnan(result)) {
        throw exceptions::NanException();
      }
      return result;
    }
  }    
}
