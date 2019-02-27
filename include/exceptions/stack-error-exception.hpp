#ifndef STACK_ERROR_EXCEPTION_HPP
#define STACK_ERROR_EXCEPTION_HPP

#include <exception>

namespace sc
{
  namespace exceptions
  {
    class StackErrorException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "An error has been found in the calculator's stack";
      }
    };
  }
}

#endif // STACK_ERROR_EXCEPTION_HPP
