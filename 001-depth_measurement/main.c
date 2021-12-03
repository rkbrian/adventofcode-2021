#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	FILE *fp = fopen("test_data", "r");
	char *lines = NULL;
	size_t len = 0;
	ssize_t reading;
	int flag = 0, data_cur, data_next, i = 0;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		if (flag == 0)
			data_cur = atoi(lines), flag = 1;
		else
		{
			data_next = atoi(lines);
			if (data_next > data_cur)
				i++;
			data_cur = data_next;
		}
	}
	printf("%d\n", i);
	fclose(fp);
	if (lines)
		free(lines);
	return (0);
}
