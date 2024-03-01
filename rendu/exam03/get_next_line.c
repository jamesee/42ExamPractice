/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:55:46 by james             #+#    #+#             */
/*   Updated: 2024/03/01 04:05:17 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	10
#endif

char	*ft_storebuffer(char *store, char *buffer)
{
	char	*new;
	size_t	len;
	int		i;
	char	*p;

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
	p = store;
	i = 0;
	while (*p)
		new[i++] = *p++;
	free(store);
	while (*buffer)
		new[i++] = *buffer++;
	new[i] = '\0';
	return (new);
}
char	*ft_updatestore(char *store)
{
	char	*start;

	start = ft_strchr(store, '\n');
	if (!start)
	{
		free (store);
		return (NULL);
	}
	ft_memcpy(store, start + 1, ft_strlen(start));
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
/*
char	*ft_extractline(char *store)
{
	char	*line;
	size_t	len;
	int		i;

	if (!store || *store == '\0')
		return (NULL);
	len = 0;
	i = 0;
	while (store[i] && store[i] != '\n')
		++i;
	len = i;
	if (store[i] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, store, len);
	line[len] = '\0';
	return (line);
}
*/

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
	store = ft_updatestore(store);
	return (line);
}
