/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:17:08 by jee               #+#    #+#             */
/*   Updated: 2024/01/28 22:23:18 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet);

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	buffer[8];
	int				i;
	unsigned char	res;

	i = 8;
	while (i--)
		buffer[i] = (octet >> i & 1) + '0';
	res = 0;
	i = -1;
	while (++i < 8)
	{
		res *= 2; 
		res += buffer[i] - '0';
	}
	return (res);
}

int	main(void)
{
	print_bits(38);
	write(1, "\n", 1);
	print_bits(reverse_bits(38));	
	write(1, "\n", 1);
	return (0);
}
