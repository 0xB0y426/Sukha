#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
	TKN_RET,
	TKN_SUM,
	TKN_SUB,
	TKN_MUL,
	TKN_DIV,
	TKN_INT,
	TKN_PUSTACK,
	TKN_RSTACK
}TokenType;

typedef struct {
	TokenType type;
	int v_int;
    	int value;
}Token;

Token createtoken(TokenType type, int value);

#endif
