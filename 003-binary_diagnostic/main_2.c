#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int power_rangers(int zords)
{
	int i = 1;

	if (zords == 0)
		return (1);
	while (zords)
		i *= 2, zords--;
	return (i);
}

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] == '0' || str[i] == '1'; i++)
	{
	}
	return (i);

}

void init_counts(int *count_one, int *count_z, int digilen)
{
	int i;

	for (i = 0; i < digilen; i++)
		count_one[i] = 0, count_z[i] = 0;
}

void count_nums(int *count_one, int *count_z, char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '0')
			count_z[i]++;
		else
			count_one[i]++;
	}
}

int main(void)
{
	FILE *fp = fopen("test_data", "r");
	char *lines = NULL;
	size_t len = 0;
	ssize_t reading;
	int majority[40], minority[40], oxy[40], co2[40];
	int digilen = 0, i, oxy_n = 0, co2_n = 0;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		if (digilen == 0)
			digilen = _strlen(lines), init_counts(count_one, count_z, digilen);
		count_nums(count_one, count_z, lines);
	}
	printf("Gamma rate, Epsilon rate\n");
	for (i = 0; i < digilen; i++)
	{
		if (count_one[i] > count_z[i])
			gr[i] = 1, er[i] = 0;
		else if (count_one[i] < count_z[i])
			gr[i] = 0, er[i] = 1;
		printf("[%2d] ---- %d, %d\n", i, gr[i], er[i]);
		gr_n += gr[i] * power_rangers(digilen - 1 - i);
		er_n += er[i] * power_rangers(digilen - 1 - i);
	}
	printf("gamma rate: %d\nepsilon rate: %d\nproduct: %d\n", gr_n, er_n, gr_n * er_n);
	fclose(fp);
	if (lines)
		free(lines);
	return (0);
}
