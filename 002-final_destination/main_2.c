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
	int hori = 0, verti = 0, aim = 0;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		token = strtok(lines, " "), token = strtok(NULL, " ");
		if (lines[0] == 'f')
		{
			hori += atoi(token), verti += aim * atoi(token);
			if (verti < 0)
				verti = 0;
		}
		else if (lines[0] == 'd')
			aim += atoi(token);
		else if (lines[0] == 'u')
		{
			aim -= atoi(token);
			if (aim < 0)
				aim = 0;
		}
	}
	printf("X: %d\nY: %d\nProduct: %d\n", hori, verti, hori * verti);
	fclose(fp);
	if (lines)
		free(lines);
	return (0);
}
