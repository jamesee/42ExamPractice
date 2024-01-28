/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:40:19 by jee               #+#    #+#             */
/*   Updated: 2024/01/28 21:15:06 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	bits[8];
	int				i;

	i = 8;
	while (i--)
		bits[7 - i] = (octet >> i & 1) + '0';
	write(1, &bits, 8);
}
//
//int	main(void)
//{
//	print_bits(2);
//	write(1, "\n", 1);
//	print_bits(128);
//	return (0);
//}
