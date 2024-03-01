/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 03:44:57 by james             #+#    #+#             */
/*   Updated: 2024/03/01 06:23:00 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_fdreader(int fd, char *store);
char	*ft_extractline(char *store);
char	*ft_updatestore(char *store);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
void	ft_memcpy(char *dest, char *src, size_t n);
char	*ft_storebuffer(char *s1, char *s2);

/*
char	*ft_fdreader(int fd, char *store);
char	*ft_extractline(char *store);
char	*ft_updatestore(char *store);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
void	ft_memcpy(char *dest, char *src, size_t n);
char	*ft_storebuffer(char *s1, char *s2);
*/

#endif
