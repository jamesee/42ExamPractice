/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:38:40 by jee               #+#    #+#             */
/*   Updated: 2024/01/29 18:20:54 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define	BUFFER_SIZE	256

bool	ft_is_double(char *s, char c, int index)
{
	while (index--)
		if (c == s[index])
			return (true);
	return (false);
}

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}

void	ft_no_duplicates(char *s1, char *s2)
{
	char	buf[BUFFER_SIZE];
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (ft_is_double(s1, s1[i], i) == false)
			buf[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!ft_is_double(s2, s2[i],i))
			buf[j++] = s2[i];
		i++;	
	}
	i = 0;
	while (buf[i])
	{
		if (!ft_is_double(buf, buf[i],i))
		{
			write(1, &buf[i], 1);
		}
		i++;	
	}
}


int	main(int argc, char **argv)
{
	if (argc == 3)
	{

		ft_no_duplicates(argv[1], argv[2]);
	}
	else
		write(1, "\n", 1);
	return (0);
}


