/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:02:56 by jee               #+#    #+#             */
/*   Updated: 2024/01/30 20:24:34 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	ft_isspace(unsigned char c)
{
	return ((c > 0x09 && c < 0x0d) || c == 0x20);
}

bool	ft_isplusminus(unsigned char c)
{
	return ( c == '+' || c == '-');
}

char	ft_to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	return (c);
}

int	ft_isdigit(unsigned char c, char *base)
{
	int	count;

	count = -1;
	while (*base)
	{
		++count;
		if (ft_to_lower(*base) = c)
			break ;
	}
	if (c > ft_strlen(base))
		return (-1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	while (*str && ft_isspace((unsigned char) *str))
		str++;
	if (*str && ft_isplusminus((unsigned char) *str))
	{	
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str && ft_isdigit((unsigned char) *str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}

//------------------------------[test]
#include <stdio.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	
	printf("atoi\t= [%d]\n", ft_atoi(argv[1]));
	printf("ft_atoi\t= [%d]\n", ft_atoi(argv[1]));

	return (0);
}
