/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:26:15 by james             #+#    #+#             */
/*   Updated: 2024/01/29 17:31:07 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			return (0);
	}
	return (1);
}

//----------------------------- [test]
//

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (is_power_of_2(atoi(argv[1])))
		printf("Input is power of 2\n");
	else
		printf("Input is NOT power of 2\n");

	return (0);

}
