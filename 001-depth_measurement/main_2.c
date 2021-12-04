#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARR_SIZE 3

void shift_arr(int *array, int new_num)
{
	int i;

	for (i = 0; i < MAX_ARR_SIZE; i++)
	{
		if (i < MAX_ARR_SIZE - 1)
			array[i] = array[i + 1];
		else
			array[i] = new_num;
	}
}

int sum_three(int *array)
{
	int i, ret = 0;

	for (i = 0; i < MAX_ARR_SIZE; i++)
		ret += array[i];
	return (ret);
}

void init_array(int *array)
{
	int i;

        for (i = 0; i < MAX_ARR_SIZE; i++)
		array[i] = 0;
}

int main(void)
{
	FILE *fp = fopen("test_data", "r");
	char *lines = NULL;
	size_t len = 0;
	ssize_t reading;
	int flag = 0, sum_cur = 0, sum_next = 0, i = 0;
	int array[MAX_ARR_SIZE];

	init_array(array);
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		if (flag < 3)
		{
			array[flag] = atoi(lines);
			if (flag == 2)
				sum_cur = sum_three(array);
			flag++;
		}
		else
		{
			shift_arr(array, atoi(lines)), sum_next = sum_three(array);
			if (sum_next > sum_cur)
				i++;
			sum_cur = sum_next;
		}
	}
	printf("%d\n", i);
	fclose(fp);
	if (lines)
		free(lines);
	return (0);
}
