/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:30:20 by james             #+#    #+#             */
/*   Updated: 2024/01/31 10:13:54 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

bool	ft_is_sep(char c)
{
	return (c == 0x20 || c == 0x09);
}

int	ft_print_word(char *str, int index, bool frontspace)
{
	int		count;

	count = -1;
	while (*str)
	{
		++count;
		while (*str && ft_is_sep(*str))
			str++;
		if (count == index && frontspace)
			write(1, " ", 1);
		while (*str && !ft_is_sep(*str))
		{
			if (count == index)
				write(1, str, 1);
			str++;
		}
		while (*str && ft_is_sep(*str))
			str++;
	}
	return (count++);
}

void	ft_rostring(char *str)
{
	int	i;
	int	count;

	count = ft_print_word(str, -1, false);

	ft_print_word(str, 1, false);
	i = 1;
	while (++i < count)
		ft_print_word(str, i, true);
	ft_print_word(str, 0, true);

}

void	ft_rev_wstr(char *str)
{
	int	i;

	i = ft_print_word(str, -1, false);
	
	ft_print_word(str, i--, false);
	while (i--)
		ft_print_word(str, i, true);

}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}

	ft_rostring(argv[1]);
	write(1, "\n", 1);
	ft_rev_wstr(argv[1]);

	return (0);
}

