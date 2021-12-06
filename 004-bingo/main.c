#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	FILE *fp = fopen("test_data1", "r");
	char *lines = NULL, *linez = NULL, *token = NULL, *toten = NULL;
	size_t len = 0, leng = 0;
	ssize_t reading;
	int num_call[256], i = 0, j, k, m, calls = 0, flag, win_num[256], sum[256], callcount[256], n = 0;
	int bingo[5][5], logic_board[5][5], min = 0;

	if (fp == NULL) /* save calls */
		exit(EXIT_FAILURE);
	if ((reading = getline(&lines, &len, fp)) != -1)
	{
		token = strtok(lines, ",");
		while (token)
			num_call[i] = atoi(token), calls++, token = strtok(NULL, ","), i++;
	}
	fclose(fp), i = 0;
	if (lines)
		free(lines);
	fp = fopen("test_data2", "r"), k = 0; /* check winner */
	while ((reading = getline(&linez, &leng, fp)) != -1)
	{
		if ((i + 1) % 6 != 0)
		{
			toten = strtok(linez, " ");
			for (j = 0; j < 5; j++)
			{
				bingo[k][j] = atoi(toten), logic_board[k][j] = 0;
				if (j < 4)
					toten = strtok(NULL, " ");
			}
			printf("%d,%d", k, i%6);
			k++;
		}
		else
		{
			for (m = 0; m < calls; m++)
			{
				flag = 0;
				for (k = 0; k < 5; k++)
				{
					for (j = 0; j < 5; j++)
					{
						if (num_call[m] == bingo[k][j])
						{
							logic_board[k][j] = 1, flag = 1;
							break;
						}
					}
					if (flag == 1)
						break;
				}
				if (flag == 1 && (logic_board[k][0]+logic_board[k][1]+logic_board[k][2]+logic_board[k][3]+logic_board[k][4] == 5
				    || logic_board[0][j]+logic_board[1][j]+logic_board[2][j]+logic_board[3][j]+logic_board[4][j] == 5))
					win_num[n] = num_call[m], flag = 2;
				if (flag == 2)
				{
					sum[n] = 0;
					for (k = 0; k < 5; k++)
					{
						for (j = 0; j < 5; j++)
						{
							if (logic_board[k][j] == 0)
								sum[n] += 1;
						}
					}
					callcount[n] = m;
				}
			}
			k = 0, n++;
		}
		i++;
	}
	min = callcount[0], j = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d, ", sum[i]);
		if (min > callcount[i])
			min = callcount[i], j = i;
	}
	fflush(stdout), printf("at this round: [%d]\nborad #%d has a win number: %d\nsum: %d\nscore: %d\n", min, j+1, win_num[j], sum[j], win_num[j] * sum[j]);
	fclose(fp), token = NULL, toten = NULL;
	if (linez)
		free(linez);
	return (0);
}
