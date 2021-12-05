#ifndef LINLY_H
#define LINLY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct linked_list
{
	int array[5][5];
	int marks[5][5];
	struct linked_list *next;
} board_list;

#endif /*LINLY_H*/
