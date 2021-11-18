#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/ez.c"

void generateBuild() {
	FILE* fp;
	fp = fopen("build.sh", "w+");
	char* result = (char*) malloc(sizeof(char) * 1);
	generate(ECHO, result, "===== Building ====\n", NULL);
	generate(CC, result, "main.c", "ez");
	generate(ECHO, result, "Built successfully!\n", NULL);
	fputs(result, fp);
	fclose(fp);
	free(result);
	printf("Successfully generated build!\n");
}

int main(int argc, const char** argv) {
	printf("===================\n");
	printf("Generating build.sh\n");
	printf("===================\n");
	
	generateBuild();
	return 0;
}
