/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:55:46 by james             #+#    #+#             */
/*   Updated: 2024/03/01 06:46:39 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	10
#endif

size_t	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}


void	ft_memcpy(char *dest, char *src, size_t n)
{
	if (dest == src || !n)
		return ;

	while (n--)
		*dest++ = *src++;
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

char	*ft_storebuffer(char *store, char *buffer)
{
	char	*new;
	size_t	len;

	len = ft_strlen(store) + ft_strlen(buffer);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
	{
		if (buffer)
			free(buffer);
		if (store)
			free(store);
		return (NULL);
	}
	ft_memcpy(new, store, ft_strlen(store));
	ft_memcpy(new + ft_strlen(store), buffer, ft_strlen(buffer));
	new[len] = '\0';
	free(store);
	return (new);
}

char	*ft_updatestore(char *store)
{
	char	*start;

	if (store == NULL)
		return (NULL);
	start = ft_strchr(store, '\n');
	if (!start)
	{
		free (store);
		return (NULL);
	}
	ft_memcpy(store, start + 1, ft_strlen(start + 1));
	store[ft_strlen(start + 1)] = '\0';
	return (store);
}

char	*ft_extractline(char *store)
{
	char	*line;
	size_t	len;

	if (!store || *store == '\0')
		return (NULL);
	len = 0;
	while (store[len] && store[len] != '\n')
		len++;
	if (store[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, store, len);
	line[len] = '\0';
	return (line);
}

char	*ft_fdreader(int fd, char *store)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(store, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (store)
				free(store);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		store = ft_storebuffer(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store = NULL;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &line, 0) < 0)
	{
		if (store)
			free(store);
		store = NULL;
		return (NULL);
	}

	if (!store)
	{
		store = (char *) malloc(1);
		*store = '\0'; 
	}
	store = ft_fdreader(fd, store);
	if (store == NULL)
		return (NULL);
	line = ft_extractline(store);
	if (line == NULL)
	{
		if (store)
			free(store);
		store = NULL;
		return (NULL);
	}
	store = ft_updatestore(store);
	return (line);
}
