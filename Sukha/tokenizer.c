#include "includes/token.h"

Token createtoken(TokenType type, int value) {
	Token t;
	t.type = type;

	if (type == TKN_INT) {
		t.v_int = value;
	}

	return t;
}




