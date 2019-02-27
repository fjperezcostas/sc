#ifndef SYNTAX_ERROR_EXCEPTION_HPP
#define SYNTAX_ERROR_EXCEPTION_HPP

#include <exception>

namespace sc
{
  namespace exceptions
  {
    class SyntaxErrorException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "Syntax error in the given expression";
      }
    };
  }
}

#endif // SYNTAX_ERROR_EXCEPTION_HPP
