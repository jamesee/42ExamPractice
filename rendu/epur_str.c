/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:30:20 by james             #+#    #+#             */
/*   Updated: 2024/01/31 08:56:48 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	ft_is_sep(char c)
{
	return (c == 0x20 || c == 0x09);
}

void	ft_epur_str(char *str)
{
	bool	first;

	first = true;
	while (*str)
	{
		while (*str && ft_is_sep(*str))
			str++;
		if (!first)
			write(1, " ", 1);
		while (*str && !ft_is_sep(*str))
		{
			first = false;
			write(1, str, 1);
			str++;
		}
		while (*str && ft_is_sep(*str))
			str++;
	}
}


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}


	ft_epur_str(argv[1]);

	return (0);
}

