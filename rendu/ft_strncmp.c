/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:48:22 by jee               #+#    #+#             */
/*   Updated: 2024/01/29 15:02:51 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// need to take care of situation 
// where n > strlen(s1)
// or n > strlen(s2)
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while (*s1 == *s2 && (*s1 || *s2) && n--)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

//--------------------------------[test]
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	printf("strncmp\t\t= %d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("ft_strncmp\t= %d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));

	return (0);
}


