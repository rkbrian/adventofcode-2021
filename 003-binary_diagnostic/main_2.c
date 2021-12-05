#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "life_sup.h"

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

void init_board(int *logic_board, int mystrlen)
{
	int i;

	for (i = 0; i < mystrlen; i++)
		logic_board[i] = 0;
}

void count_most(nth_digit *node, int *logic_board, int mystrlen, int search_val)
{
	int i, count_z = 0, count_one = 0;
	char most_n;

	for (i = 0; i < mystrlen; i++)
	{
		if (node->str[i] == '0' && logic_board[i] == search_val)
			count_z[i]++;
		else if (node->str[i] == '1' && logic_board[i] == search_val)
			count_one[i]++;
	}
	if (count_z > count_one)
		most_n = '0';
	else if (count_z < count_one)
		most_n = '1';
	else
		most_n = '1';
	for (i = 0; i < mystrlen; i++)
	{
		if (node->str[i] == most_n)
			logic_board[i]++;
	}
}

void count_least(nth_digit *node, int *logic_board, int mystrlen, int search_val)
{
        int i, count_z = 0, count_one = 0;
        char least_n;

        for (i = 0; i < mystrlen; i++)
        {
                if (node->str[i] == '0' && logic_board[i] == search_val)
                        count_z[i]++;
                else if (node->str[i] == '1' && logic_board[i] == search_val)
                        count_one[i]++;
        }
        if (count_z < count_one)
                least_n = '0';
        else if (count_z > count_one)
                least_n = '1';
        else
                least_n = '0';
        for (i = 0; i < mystrlen; i++)
        {
                if (node->str[i] == least_n)
                        logic_board[i]--;
        }
}

int main(void)
{
	FILE *fp = fopen("test_data", "r");
	char *lines = NULL;
	size_t len = 0;
	ssize_t reading;
	int oxy[40], co2[40], logic_board[1024], logi_ox = 0, logi_co = 0;
	int digilen = 0, i, j = 0, oxy_n = 0, co2_n = 0;
	nth_digit *nth, *head = NULL, *current = NULL;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		if (digilen == 0)
		{
			digilen = _strlen(lines);
			nth = malloc(sizeof(nth_digit *)), head = nth, i = 1;
			while (i < digilen)
				nth = nth->next, nth = malloc(sizeof(nth_digit *)), i++;
		}
		current = head, i = 0;
		while (current)
			current->str[j] = lines[i], current = current->next, i++;
		j++;
	}
	printf("Gamma rate, Epsilon rate\n");
	current = head, j++;
	while (current)
	{
		count_most(current, logic_board, j, logi_ox);
		count_least(current, logic_board, j, logi_co);
		logi_ox++, logi_co--, current = current->next;
	}
	logi_ox--, logi_co++;
	printf("oxy rate: %d\nCO2 rate: %d\nproduct: %d\n", oxy_n, co2_n, oxy_n * co2_n);
	fclose(fp);
	if (lines)
		free(lines);
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
	return (0);
}
