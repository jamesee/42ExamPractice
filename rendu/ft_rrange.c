/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by james             #+#    #+#             */
/*   Updated: 2024/01/30 19:24:10 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int x)
{
	if (x > 0)
		return (x);
	return (-x);
}

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*tab;
	int	step;
	int	i;

	len = ft_abs(end - start);
	tab = (int *) malloc(sizeof(int) * (len + 1));
	if (tab == NULL)
		return (NULL);
	if (start > end)
		step = 1;
	else
		step = -1;
	i = -1;
	while (++i < len + 1)
	{
		tab[i] = end;
		end += step;
	}
	return (tab);
}

//---------------------------[test]
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (1);

	int start = atoi(argv[1]);
	int end = atoi(argv[2]);

	int *arr = ft_rrange(start, end);

	int i = 0;
	while (i < 1 + ft_abs(end - start))
	{
		printf("%d", arr[i]);
        if (i < 1 + ft_abs(end - start) - 1)
            printf(", ");
		++i;
	}
	printf("\n");
	free (arr);
	return (0);
}
