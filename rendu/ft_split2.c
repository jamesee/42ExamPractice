/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:34:42 by james             #+#    #+#             */
/*   Updated: 2024/01/30 21:58:20 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

static bool	ft_is_sep(char c)
{
	return (c == 0x20 || c == 0x09 || c == 0x0a || c == '\0');
}

static int	ft_word_count(char *str)
{
	char	prev;
	int		count;

	prev = '\0';
	count = 0;
	while(*str)
	{
		//start of word
		if (ft_is_sep(prev) && !ft_is_sep(*str))
			count++;
		prev = *str;
		str++;
	}
	return (count);
}

static char	*ft_word(char *str)
{
	int		i;
	int		wordlen;
	char	*word;

	// count word len, make sure dont move str pointer
	wordlen = 0;
	while (str[wordlen] && !ft_is_sep(str[wordlen]))
		wordlen++;
	word = (char *) malloc(sizeof(char) * wordlen + 1);
	if (word == NULL)
		return (NULL);
	// copy word, make sure dont move word pointer
	i = 0;
	while (*str && !ft_is_sep(*str))
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

static char **ft_backtrack_free(char **strings, int i)
{
	while (i--)
		free(strings[i]);
	free(strings);
	return (NULL);
}

char	**ft_split(char *str)
{
	char	prev;
	char	**strings;
	int		i;

	strings = (char **)malloc(sizeof(char*) * (ft_word_count(str) + 1));
	if (strings == NULL)
		return (NULL);
	i = 0;
	prev = '\0';
	while (*str)
	{
		//start of word
		if (ft_is_sep(prev) && !ft_is_sep(*str))
		{
			strings[i++] = ft_word(str);
			if (strings[i-1] == NULL)
				return (ft_backtrack_free(strings, i));
		}
		prev = *str;
		str++;
	}
	strings[i] = NULL;
	return (strings);
}

//---------------------------------[test]

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	char 	**split;

	if (argc != 2)
		return (1);

	split = ft_split(argv[1]);

	i = -1;
	while (split[++i])
		printf("%s\n", split[i]);

	while (i--)
		free (split[i]);
	free (split);
	return (0);
}
