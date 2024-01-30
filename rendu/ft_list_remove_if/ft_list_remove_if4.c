/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:38:35 by james             #+#    #+#             */
/*   Updated: 2024/01/29 21:03:39 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>


void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (begin_list == NULL || *begin_list == NULL)
		return ;

	current = *begin_list;
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free (current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&current->next, data_ref, cmp);

}

//----------------------------------[test]
//
#include <stdio.h>
#include <string.h>

void	print_list(t_list *begin_list)
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		printf("%s\n", (char *) current->data);
		current = current->next;
	}
}

int	main(void)
{
	t_list	*aa, *bb, *cc, *dd;

	char	str_aa[] = "string aa";
	char	str_bb[] = "string bb";
	char	str_cc[] = "string cc";
	char	str_dd[] = "string dd";

	aa = malloc (sizeof(t_list));
	bb = malloc (sizeof(t_list));
	cc = malloc (sizeof(t_list));
	dd = malloc (sizeof(t_list));

	aa->data = str_aa;
	aa->next = bb;

	bb->data = str_bb;
	bb->next = cc;

	cc->data = str_cc;
	cc->next = dd;

	dd->data = str_dd;
	dd->next = NULL;

	print_list(aa);

	printf("----------\n");
	
	ft_list_remove_if(&aa, str_aa, strcmp);
	print_list(aa);

	return (0);
}
