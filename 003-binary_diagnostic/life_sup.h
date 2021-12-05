#ifndef LIFE_SUP_H
#define LIFE_SUP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct linked_list
{
	char *str[1024];
	struct linked_list *next;
} nth_digit;

#endif /*LIFE_SUP_H*/
