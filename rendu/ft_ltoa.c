/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:57:58 by james             #+#    #+#             */
/*   Updated: 2024/02/01 00:55:24 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// LLONG_MAX is 19 digits + minus sign
#define BUFFERSIZE	20
#define BASE		"0123456789"	

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}

void	ft_lltoa(long long int n)
{
	// +1 for null terminator
	char	buf[BUFFERSIZE + 1];
	char	*base;
	int		sign;
	size_t	len;
	size_t	i;

	base = BASE;
	len = ft_strlen(base);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	i = (size_t) BUFFERSIZE;
	buf[i] = '\0';
	if (n == 0)
		buf[--i] = base[(int)n];
	while (n && --i)
	{
		buf[i] = base[(int)(n % len)];
		n /= len;
	}
	if (sign == -1)
		buf[--i] = '-';
	printf("\ni = %zu\n", i);
	write(1, buf + i, BUFFERSIZE - i);
}



int	main(int argc, char **argv)
{
	long	n;

	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) > 20)
		return (1);
	n = atoll(argv[1]);
	if (n <= LLONG_MAX && n >= LLONG_MIN)
		ft_lltoa(n);
	return (0);
}


