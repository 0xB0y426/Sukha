#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/emit.h"
#include "includes/parser.h"

int main(int argc, char **argv) {
  if(argc < 2) {
    printf("Usage: ./sukha code.skh\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  fp = fopen(argv[1], "rb");

  if (fp == NULL) {
    printf("File is Null!\n");
    exit(EXIT_FAILURE);
  }

  char line[256];
  while(fgets(line, sizeof(line), fp) != NULL) {
  	 Token t = lex(line);
	 parse(t);
  }
  
  fclose(fp);
  execpu();
}
