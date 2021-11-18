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
			if (output == NULL) {
				output = cmdArg;
			}

			strcat(result, output);
			strcat(result, "\n");
			break;
		}
	}
}

void generateBuild(char* result, char* out) {
	if (out == NULL) {
		out = "build.sh";
	}

	FILE* fp;
	fp = fopen(out, "w+");
	fputs(result, fp);
	fclose(fp);
	free(result);
	printf("Successfully generated build!\n");
}
