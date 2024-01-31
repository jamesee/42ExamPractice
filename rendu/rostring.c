/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:34:42 by james             #+#    #+#             */
/*   Updated: 2024/01/30 17:03:37 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		str++;
	return (str - ptr);
}

static bool	ft_is_sep(char c)
{
	return (c == 0x20 || c == 0x09 || c == '\0');
}

// sep_flag = true when previous char is sep
static int	ft_word_count(char *str)
{
	bool	sep_flag;
	int		count;

	sep_flag = true;
	count = 0;
	while(*str)
	{
		//start of word
		if (sep_flag && !ft_is_sep(*str))
		{
			sep_flag = false;
			count++;
		}
		//end of word
		if (!sep_flag && ft_is_sep(*str))
			sep_flag = true;
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
	char	**strings;
	bool	sep_flag;
	int		i;

	strings = (char **)malloc(sizeof(char*) * (ft_word_count(str) + 1));
	if (strings == NULL)
		return (NULL);
	i = 0;
	sep_flag = true;
	while (*str)
	{
		//start of word
		if (sep_flag && !ft_is_sep(*str))
		{	
			sep_flag = false;
			strings[i++] = ft_word(str);
			if (strings[i-1] == NULL)
				return (ft_backtrack_free(strings, i));
		}
		//end of word
		if (!sep_flag && ft_is_sep(*str))
			sep_flag = true;
		str++;
	}
	strings[i] = NULL;
	return (strings);
}

//---------------------------------[test]


int	main(int argc, char **argv)
{
	int		i;
	char 	**split;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	split = ft_split(argv[1]);

	i = 0;
	while (split[++i])
	{
		write(1, split[i], ft_strlen(split[i]));
		write(1, " ", 1);
	}
	write(1, split[0], ft_strlen(split[0]));
	write(1, "\n", 1);


	while (i--)
		free (split[i]);
	free (split);
	return (0);
}
