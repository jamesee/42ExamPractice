/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@42mail.sutd.edu.sg>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:10:18 by james             #+#    #+#             */
/*   Updated: 2024/03/01 04:02:21 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dest == src || !n)
		return (dest);
	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strchr(const char *src, int c)
{
	while (*src)
	{
		if (*src == (char) c)
			return ((char *)src);
		src++;
	}
	if ((char) c == *src)
		return ((char *)src);
	return (NULL);
}
