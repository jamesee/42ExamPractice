/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:46:39 by james             #+#    #+#             */
/*   Updated: 2024/01/30 17:47:18 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;	

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

int main(int ac, char **av){
	if (ac == 3)
		printf("%d", lcm(atoi(av[1]), atoi(av[2])));
	return (0);
}
