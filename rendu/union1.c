/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:34:55 by jee               #+#    #+#             */
/*   Updated: 2024/01/29 05:17:15 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

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

void	ft_union(char *s1, char *s2)
{
	char	buf[BUFFER_SIZE];
	int		i;
	
	i = 0;
	while (*s1)
		*(buf + i++) = *s1++;
	while (*s2)
		*(buf + i++) = *s2++;
	*(buf + i) = '\0';
	i = -1;
	while (buf[++i])
		if (!ft_is_double(buf, buf[i],i))
			write(1, &buf[i], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}


