/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:26:14 by james             #+#    #+#             */
/*   Updated: 2024/01/29 20:38:13 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

//void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
//{
//	t_list	*current;
//
//	if (begin_list == NULL || *begin_list == NULL)
//		return ;
//
//	current = *begin_list;
//
//	if (cmp(current->data, data_ref) == 0)
//	{	
//		*begin_list = current->next;
//		free (current);
//		ft_list_remove_if(begin_list, data_ref, cmp);
//	}
//	else
//		ft_list_remove_if(&current->next, data_ref, cmp);
//}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*previous;

	if (begin_list == NULL || *begin_list == NULL)
		return ;

	previous = NULL;
	current = *begin_list;

	while (current->next)
	{
		previous = current;
		if (cmp(current->data, data_ref) == 0)
		{
			current = current->next;
			free (previous);
		}
		else
			current = current->next;
	}
}
