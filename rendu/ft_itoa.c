/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:43:21 by james             #+#    #+#             */
/*   Updated: 2024/01/30 15:05:03 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbrlen(int n)
{
	int	len;
	
	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	nl;
	int			len;

	len = ft_nbrlen(n);
	ptr	= (char *) malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len--] = '\0';
	nl = (long int) n;
	if (nl < 0)
	{
		nl = -nl;
		ptr[0] = '-';
	}
	if (nl == 0)
		ptr[len--] = '0';
	while (nl)
	{
		ptr[len--] = (nl % 10) + '0';
		nl /= 10;
	}
	return (ptr);
}

//----------------------------[test]
//
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*s;

	if (argc != 2)
		return (1);

	s = ft_itoa(atoi(argv[1]));
	printf("%s", s);
	free(s);
	return (0);
}

