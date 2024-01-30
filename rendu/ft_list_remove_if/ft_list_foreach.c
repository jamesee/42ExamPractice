/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:06:30 by james             #+#    #+#             */
/*   Updated: 2024/01/29 21:30:11 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		(*f)(current->data);
		current = current->next;
	}
}

//-------------------------------[test]
//
#include <stdio.h>

void	print_list(void *s)
{
	printf("%s\n", (char *) s);
}

int	main(void)
{
	int i;
	t_list	*list[4];
	char	*str[] = {
					"string aa",
					"string bb",
					"string cc",
					"string dd"
					};
	i = 4;
	while (i--)
	{
		list[i] = (t_list *) malloc(sizeof(t_list));
		list[i]->data = str[i];
		if (i == 3)
			list[i]->next = NULL;
		else
			list[i]->next = list[i+1];
	}	

	ft_list_foreach(list[0], print_list);

	i = 4;
	while (i--)
		free(list[i]);

	return (0);
}




