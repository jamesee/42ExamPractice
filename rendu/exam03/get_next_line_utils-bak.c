/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 03:43:00 by james             #+#    #+#             */
/*   Updated: 2024/03/01 03:45:52 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*str)
		str++;
	return (p - str);
}

void	ft_memcpy(char *dest, char *src, size_t n)
{
	if (dest == src || !n)
		return ;
	while (n--)
		*dest++ = *src++;
}

char	*ft_strchr(char *src, int c)
{
	while (*src)
	{
		if (*src == (char) c)
			return (src);
		src++;
	}
	if (*src == (char) c)
		return (src);
	return (NULL);
}
