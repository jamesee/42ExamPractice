/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:16:20 by jee               #+#    #+#             */
/*   Updated: 2024/01/29 14:35:59 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}

// Make sure the dest pointer is not moved
// use i to increment
char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = (char *) malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);

	i = 0;
	while (*src)
		*(dest + i++) = *src++;
	*(dest + i) = '\0';
	return (dest);
}

//-------------------------------[test]
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*lib;
	char	*ft;

	if (argc != 2)
		return (1);

	lib = strdup(argv[1]);
	ft = ft_strdup(argv[1]);
	printf("strdup\t\t= [%s]\n", lib);
	printf("ft_strdup\t= [%s]\n", ft);

	free(lib);
	free(ft);
	return (0);
}

