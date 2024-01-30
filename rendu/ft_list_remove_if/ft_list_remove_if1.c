/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:18:22 by james             #+#    #+#             */
/*   Updated: 2024/01/29 19:20:26 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		if (data_ref && (*cmp)(current->data, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = next;
			else
				prev->next = next;
			free(current->data);
			free(current);
		}
		else
			prev = current;
		current = next;
	}
}
