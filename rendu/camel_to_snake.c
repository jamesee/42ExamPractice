/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 06:14:27 by james             #+#    #+#             */
/*   Updated: 2024/01/29 06:25:30 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	ft_isuppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void	ft_camel2snake(char *str)
{
	while (*str)
	{
		if (ft_isuppercase(*str))
		{
			write(1, "_", 1);
			*str += 32;
		}
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	
	ft_camel2snake(argv[1]);

	return (0);
}

