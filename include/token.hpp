#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "consts.hpp"

namespace sc
{
  namespace token
  {
    TokenType getType(char);
    int getPriority(char);
  }
}

#endif // TOKEN_HPP
