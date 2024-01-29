/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 06:14:27 by james             #+#    #+#             */
/*   Updated: 2024/01/29 06:31:28 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_snake2camel(char *str)
{
	while (*str)
	{
		if (*str == '_')
		{
			str++;
			*str -= 32;
		}
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	
	ft_snake2camel(argv[1]);

	return (0);
}

