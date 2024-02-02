/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:38:09 by james             #+#    #+#             */
/*   Updated: 2024/01/31 15:04:19 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long num)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	if (num < 10)
		ft_putchar(num + '0');
}

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	printf("%ld\n", atol(argv[1]));
	ft_putnbr(atol(argv[1]));
	return (0);
}
