#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void ft_putnbr(void *data)
{
	int *i;

	i = data;
	printf("%d", *i);
}


int main()
{
	t_list *list;
	int i;
	int *data;

	i = 0;
	list = NULL;
	while (i < 10)
	{
		data = malloc(sizeof(int));
		*data = i;
		ft_list_push_front(&list, data);
		i++;
	}
	ft_list_foreach(list, &ft_putnbr);
	return (0);
}