/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:22:11 by james             #+#    #+#             */
/*   Updated: 2024/01/29 05:50:49 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}

bool	ft_wdmatch(char *s1, char *s2)
{
	int	count;

	count = ft_strlen(s1);
	while (*s1)
	{
		while (*s2)
		{
			if (*s2 == *s1)
			{	
				count--;
				break ;
			}
			s2++;
		}
		s1++;
	}
	return (count == 0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	if (ft_wdmatch(argv[1], argv[2]))
		write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	return (0);
}
