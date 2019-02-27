#ifndef NAN_EXCEPTION_HPP
#define NAN_EXCEPTION_HPP

#include <exception>

namespace sc
{
  namespace exceptions
  {
    class NanException : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "The value obtained is not a number";
      }
    };
  }
}

#endif // NAN_EXCEPTION_HPP
