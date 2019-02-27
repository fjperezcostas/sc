#ifndef CONSTS_HPP
#define CONSTS_HPP

namespace sc
{
  const char LN   = 'l';
  const char LOG  = 'L';
  const char SIGN = '~';
  const char SQR  = 'r';

  typedef enum {
    NUMBER,
    UNARY_OPERATOR,
    BINARY_OPERATOR,
    OPENING_BRACKET,
    CLOSING_BRACKET,
    OTHER
  } TokenType;
}

#endif // CONSTS_HPP
