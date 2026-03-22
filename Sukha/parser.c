#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/emit.h"
#include "includes/token.h"
#include "includes/parser.h"
#include "utils/instructions.h"

Token lex(char *line) {
	if(strncmp(line, "ret", 3) == 0) {
		return createtoken(TKN_RET, 0);
	}

	if(strncmp(line, "pustack", 7) == 0) {
		int stackvalue;
		if (sscanf(line + 7, " %d", &stackvalue) != 1) {
			fprintf(stderr, "ERROR: Invalid value in pustack.\n");
			exit(1);
		}
		return createtoken(TKN_PUSTACK, stackvalue);
	}

	if(strncmp(line, "rstack", 6) == 0) {
		int stackvalue2;
		if (sscanf(line + 6, " %d", &stackvalue2) != 1) {
			fprintf(stderr, "ERROR: Invalid value in rstack\n");
			exit(1);
		}
		return createtoken(TKN_RSTACK, stackvalue2);
	}

	fprintf(stderr, "ERROR: Unknown instructions.\n");
	exit(EXIT_FAILURE);
}

Token parse(Token x) {
	switch(x.type) {
		case TKN_RET:
			emit8(RET);
			break;

		case TKN_PUSTACK:
			emit8(PUSTACK);
			emit32(x.value);
			break;

		case TKN_RSTACK:
			emit8(RSTACK);
			break;	

		default:
         		fprintf(stderr, "ERROR: Invalid command, syntax or error to compile in CPU.\n");
			exit(EXIT_FAILURE);
	}

	return x;
}
