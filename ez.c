#include <stdio.h>
#include <stdlib.h>
#include "include/ez.h"

int main(void) {
	char* result = (char*) malloc(sizeof(char) * 1);
	generate(ECHO, result, "===== Building ====\n", NULL);
	generate(CC, result, "ez.c", "ez");
	generate(ECHO, result, "Built successfully!\n", NULL);

	generateBuild(result, NULL);
	return 0;
}
