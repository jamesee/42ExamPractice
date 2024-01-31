/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 05:51:12 by james             #+#    #+#             */
/*   Updated: 2024/01/31 06:31:05 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}

bool	ft_is_sep(char c)
{
	return (c == 0x09 || c == 0x20 || c == '\0');
}

int	ft_word_count(char *str)
{
	int		count;
	char	prev;

	prev = '\0';
	count = 0;
	while (*str)
	{
		if (ft_is_sep(prev) && !ft_is_sep(*str))
			count++;
		prev = *str;
		str++;
	}
	return (count);
}

char	*ft_word(char *str)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (str[len] && !ft_is_sep(str[len]))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (*str && !ft_is_sep(*str))
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

char	**ft_backtrack_free(char **strings, int i)
{
	while (i--)
		free(strings[i]);
	free(strings);
	return (NULL);
}

char	**ft_split(char *str)
{
	char	**strings;
	char	prev;
	int		i;

	strings = (char **)malloc(sizeof(char *) * (ft_word_count(str) + 1));
	if (strings == NULL)
		return (NULL);
	prev = '\0';
	i = 0;
	while (*str)
	{
		if (ft_is_sep(prev) && !ft_is_sep(*str))
		{
			strings[i++] = ft_word(str);
			if (strings[i - 1] == NULL)
				return (ft_backtrack_free(strings, i));
		}
		prev = *str;
		str++;
	}
	strings[i] = NULL;
	return (strings);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;

	if (argc >= 2)
	{
		split = ft_split(argv[1]);

		i = 0;
		while (split[++i])
		{
			write(1, split[i], ft_strlen(split[i]));
			write(1, " ", 1);
		}
		write(1, split[0], ft_strlen(split[0]));
		ft_backtrack_free(split, i);
	}
	write(1, "\n", 1);
	return (0);
}
