/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:13:26 by jee               #+#    #+#             */
/*   Updated: 2024/01/28 22:22:32 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet);

unsigned char	swap_bits(unsigned char octet)
{
	return (unsigned char)((octet >> 4) | (octet << 4));
}

int	main(void)
{
	print_bits(65);
	write(1, "\n", 1);
	print_bits(swap_bits(65));
	write(1, "\n", 1);
	return (0);
}
