/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:34:42 by james             #+#    #+#             */
/*   Updated: 2024/01/29 18:42:28 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p++ = 0;
	}
}
#define TRUE	1
#define FALSE	0

static int	ft_is_separator(char c)
{
	return (c == 0x20 || c == 0x09 || c == 0x0a);
}

// sep_flag = TRUE if previous char is a separator
static int	ft_words_count(char const *str)
{
	int	sep_flag;
	int	count;

	count = 0;
	sep_flag = TRUE;
	while (*str)
	{
		if (sep_flag && !ft_is_separator(*str))
		{
			sep_flag = FALSE;
			count += 1;
		}
		if (!sep_flag && ft_is_separator(*str))
		{
			sep_flag = TRUE;
		}
		str++;
	}
	return (count);
}

static char	*ft_word(char const *str)
{
	int		i;
	int		wordlen;
	char	*word;

	wordlen = 0;
	while (*(str + wordlen) && !ft_is_separator(*(str + wordlen)))
		wordlen++;
	word = (char *) malloc(sizeof(char) * (wordlen + 1));
	if (word == NULL)
		return (NULL);
	ft_bzero(word, sizeof(char) * wordlen + 1);
	i = 0;
	while (*str && !ft_is_separator(*str))
		*(word + i++) = *str++;
	*(word + i) = '\0';
	return (word);
}

static char	**ft_backtrack_free(char **strings, int i)
{
	while (i--)
		free(strings[i]);
	free(strings);
	return (NULL);
}

char	**ft_split(char const *str)
{
	char	**strings;
	int		sep_flag;
	int		i;

	strings = (char **) malloc(sizeof(char *) * (ft_words_count(str) + 1));
	if (strings == NULL)
		return (NULL);
	ft_bzero(strings, sizeof(char *) * (ft_words_count(str) + 1));
	i = 0;
	sep_flag = TRUE;
	while (*str)
	{
		if (sep_flag && !ft_is_separator(*str))
		{
			sep_flag = FALSE;
			strings[i++] = ft_word(str);
			if (strings[i - 1] == NULL)
				return (ft_backtrack_free(strings, i));
		}
		if (!sep_flag && ft_is_separator(*str))
			sep_flag = TRUE;
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
