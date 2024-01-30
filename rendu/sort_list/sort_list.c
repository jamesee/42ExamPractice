/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:42:20 by james             #+#    #+#             */
/*   Updated: 2024/01/30 00:34:13 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

//t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
//{
//	int		swap;
//	t_list	*tmp;
//
//	tmp = lst;
//	while (lst->next)
//	{
//		if (((*cmp)(lst->data, lst->next->data)) == 0)
//		{
//			swap = (int) lst->data;
//			lst->data = lst->next->data;
//			lst->next->data = swap;
//			lst = tmp;
//		}
//		else
//			lst = lst->next;
//	}
//	lst = tmp;
//	return (lst);
//
//}
//

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		temp;
	t_list	*current;

	current = lst;
	while (current->next)
	{
		if (((*cmp)(current->data, current->next->data)) == 0)
		{
			temp = current->data;
			current->data = current->next->data;
			current->next->data = temp;
			current = lst;
		}
		else
			current = current->next;
	}
	return (lst);

}

//---------------------------------[test]
#include <stdio.h>

int		croissant(int a, int b)
{
	if (a <= b) 
		return (1);
	return (0);
}

void	ft_print_list(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

#define BUFFERSIZE	5

int main(void)
{
	int		i;
	t_list	*lst[BUFFERSIZE];
	int		integer[BUFFERSIZE] = { 20, 5, 10, 3, 1};
	
	i = BUFFERSIZE;
	while (i--)
	{
		lst[i] = (t_list*) malloc(sizeof(t_list));
		lst[i]->data = integer[i];
		if (i == BUFFERSIZE - 1)
			lst[i]->next = NULL;
		else
			lst[i]->next = lst[i + 1];
	}

	ft_print_list(lst[0]);
	printf("\n------------------\n");
	lst[0] = sort_list(lst[0], croissant);

	ft_print_list(lst[0]);

	return (0);
}

