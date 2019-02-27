#ifndef INFINITE_NUMBER_EXCEPTION_HPP
#define INFINITE_NUMBER_EXCEPTION_HPP

#include <exception>

namespace sc
{
  namespace exceptions
  {
    class InfiniteNumberException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "The value obtained is infinite";
      }
    };
  }
}

#endif // INFINITE_NUMBER_EXCEPTION_HPP