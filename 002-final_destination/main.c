#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	FILE *fp = fopen("test_data", "r");
	char *lines = NULL, *token;
	size_t len = 0;
	ssize_t reading;
	int hori = 0, verti = 0;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		token = strtok(lines, " "), token = strtok(NULL, " ");
		if (lines[0] == 'f')
			hori += atoi(token);
		else if (lines[0] == 'd')
			verti += atoi(token);
		else if (lines[0] == 'u')
			verti -= atoi(token);
	}
	printf("X: %d\nY: %d\nProduct: %d\n", hori, verti, hori * verti);
	fclose(fp);
	if (lines)
		free(lines);
	return (0);
}
