/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:35:20 by james             #+#    #+#             */
/*   Updated: 2024/01/30 16:41:46 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}		
}

//------------------------------[test]
//
#include <stdio.h>

#define BUFFERSIZE	5
int	main(void)
{
	int	i;
	int	tab[BUFFERSIZE] = {10, 3, 5, 1, 8 };

	sort_int_tab(tab, BUFFERSIZE);
	i = -1;
	while (++i < BUFFERSIZE)
		printf("%d\n", tab[i]);

	return (0);
}
