/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:57 by james             #+#    #+#             */
/*   Updated: 2024/01/30 19:02:14 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool	ft_is_prime(int n)
{
	int i;

	i = 1;
	while (++i < n/2)
		if (n % i == 0)
			return (false);
	return (true);
}

void fprime(int	n)
{
	int		factor;
	bool	first;

	factor = 2;
	first = true;
	if (n == 1)
		printf("1");
	while (factor <= n)
	{
		if (n % factor == 0 && ft_is_prime(factor))
		{
			n /= factor;
			if (!first)
				printf("*");
			printf("%d", factor);
			first = false;
		}
		else
			factor++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}

