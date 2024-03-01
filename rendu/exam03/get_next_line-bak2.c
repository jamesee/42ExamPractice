/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@42mail.sutd.edu.sg>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:15:46 by james             #+#    #+#             */
/*   Updated: 2024/03/01 04:00:46 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_storebuffer(char *store, char *buffer)
{
	char	*new_store;
	char	*p;
	size_t	len;
	int		i;

	len = ft_strlen(store) + ft_strlen(buffer);
	new_store = malloc(sizeof(char) + (len + 1));
	i = 0;
	p = store;
	while (*p)
		*(new_store + i++) = *p++;
	free(store);
	store = NULL;
	while (*buffer)
		*(new_store + i++) = *buffer++;
	new_store[i] = '\0';
	return (new_store);
}

char	*ft_fdreader(int fd, char *store)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(store, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(store);
			store = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		store = ft_storebuffer(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*ft_extractline(char *store)
{
	char	*line;
	size_t	len;
	int		i;

	if (store[0] == '\0')
		return (NULL);
	i = 0;
	while (store[i] != '\0' && store[i] != '\n')
		++i;
	len = i + (store[i] == '\n');
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, store, len);
	line[len] = '\0';
	return (line);
}

char	*ft_updatestore(char *store)
{
	char	*start;

	start = ft_strchr(store, '\n');
	if (!start)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	ft_memcpy(store, start + 1, ft_strlen(start));
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!store)
	{
		store = (char *)malloc(1);
		store[0] = '\0';
	}
	store = ft_fdreader(fd, store);
	if (store == NULL)
		return (NULL);
	line = ft_extractline(store);
	store = ft_updatestore(store);
	return (line);
}
