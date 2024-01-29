/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:37:32 by jee               #+#    #+#             */
/*   Updated: 2024/01/29 13:34:37 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*str)
		str++;
	return (str - p);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;


	len = ft_strlen(str);
	i = -1;
	while (++i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	return (str);
}

//--------------------------[test]
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	
	printf("strrev\t= [%s]\n", ft_strrev(argv[1]));

	return (0);
}
