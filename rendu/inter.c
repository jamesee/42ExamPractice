/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 06:41:13 by james             #+#    #+#             */
/*   Updated: 2024/01/29 07:05:50 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	ft_is_double(char *s, char c, int index)
{
	while (index--)
		if (s[index] == c)
			return (true);
	return (false);
}

void	ft_inter(char *s1, char *s2)
{
	char	buf[256];
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (s1[++i])
		if (ft_is_double(s1, s1[i], i) == false)
			buf[j++] = s1[i];
	j = -1;
	while (buf[++j])
	{
		i = -1;
		while (s2[++i])
			if (buf[j] == s2[i])
			{
				write(1, &s2[i], 1);
				break ;
			}
	}
}


int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
