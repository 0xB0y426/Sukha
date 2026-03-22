#ifndef PARSER_H
#define PARSER_H

#include "token.h"

Token lex(char *code);
Token parse(Token x);

#endif
