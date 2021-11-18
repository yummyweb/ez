#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
	ECHO,
	CC
} Cmd;

void generate(Cmd cmd, char* result, char* cmdArg, char* output) {
	switch (cmd) {
		case ECHO: {
			strcat(result, "echo ");
			strcat(result, cmdArg);
			break;
		}
		case CC: {
			strcat(result, "cc ");
			strcat(result, cmdArg);
			strcat(result, " -o ");
			strcat(result, output);
			strcat(result, "\n");
			break;
		}
	}
}
