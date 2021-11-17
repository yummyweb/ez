#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
	ECHO,
	CC
} Cmd;

void generate(Cmd cmd, char* result, char* cmdArg) {
	switch (cmd) {
		case ECHO: {
			strcat(result, "echo ");
			strcat(result, cmdArg);
			break;
		}
		case CC: {
			strcat(result, "cc ");
			strcat(result, cmdArg);
			break;
		}
	}
}

void generateBuild() {
	FILE* fp;
	fp = fopen("build.sh", "w+");
	char* result = (char*) malloc(sizeof(char) * 1);
	generate(ECHO, result, "===== Building ====\n");
	generate(CC, result, "main.c\n");
	generate(ECHO, result, "Built successfully!\n");
	fputs(result, fp);
	fclose(fp);
	printf("Successfully generated build!\n");
}

int main(int argc, const char** argv) {
	printf("===================\n");
	printf("Generating build.sh\n");
	printf("===================\n");
	
	generateBuild();
	return 0;
}
