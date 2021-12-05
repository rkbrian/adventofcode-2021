#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "linly.h"

void mygaming(board_list *head, int *num_call, int calls)
{
        board_list *current = NULL;
        int i = 0, j, k, list_i = 0, flag, win_num = 0, sum, x, y;

        current = head;
        while (i < calls)
        {
                while (current)
                {
                        flag = 0;
                        for (j = 0; j < 5; j++)
                        {
                                for (k = 0; k < 5; k++)
                                {
                                        if (current->array[j][k] == num_call[i])
                                        {
                                                current->marks[j][k] = 1, flag = 1, win_num = current->array[j][k];
                                                break;
                                        }
                                }
                                if (flag == 1)
                                        break;
                        }
			printf("%d\n", win_num);
                        flag = 0, sum = 0;
			if (j < 5 && k < 5)
                        {
                                if (current->marks[j][0]+current->marks[j][1]+current->marks[j][2]+current->marks[j][3]+current->marks[j][4] == 5 || current->marks[0][k]+current->marks[1][\
					    k]+current->marks[2][k]+current->marks[3][k]+current->marks[4][k] == 5)
                                {
                                        printf("winner board: %d\n", list_i);
                                        for (x = 0; x < 5; x++)
                                        {
                                                for (y = 0; y < 5; y++)
                                                {
                                                        if (current->marks[x][y] == 0)
                                                                sum += current->array[x][y];
                                                }
                                        }
                                        printf("winner score: %d\n", sum * win_num), flag = 2;
                                        break;
                                }
                        }
                        if (flag == 2)
                                break;
                        list_i++;
                }
                if (flag == 2)
                        break;
        }
}

int main(void)
{
	FILE *fp = fopen("test_data1", "r");
	char *lines = NULL, *token;
	size_t len = 0;
	ssize_t reading;
	int num_call[256], i = 0, j, k = 0, calls = 0;
	board_list *head, *current = NULL;

	if (fp == NULL) /* save calls */
		exit(EXIT_FAILURE);
	if ((reading = getline(&lines, &len, fp)) != -1)
	{
		token = strtok(lines, ",");
		while (token)
			num_call[i] = atoi(token), calls++, token = strtok(NULL, ","), i++;
	}
	fclose(fp), i = 0, token = NULL;
	if (lines)
		free(lines);
	fp = fopen("test_data2", "r"); /* save boards */
	head = malloc(sizeof(board_list *)), current = head;
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		if (i == 0)
			token = strtok(lines, " ");
		if ((i + 1) % 6 != 0)
		{
			for (j = 0; j < 5; j++)
				current->array[k][j] = atoi(token), current->marks[k][j] = 0;
			k++;
		}
		else
			k = 0, current = current->next, current = malloc(sizeof(board_list *));
		if (i != 0)
			token = strtok(NULL, " ");
		i++;
	}
	printf("debugger\n");
	fclose(fp), token = NULL;
	if (lines)
		free(lines);
	mygaming(head, num_call, calls);
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
	return (0);
}