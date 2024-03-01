/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:32:18 by james             #+#    #+#             */
/*   Updated: 2023/09/24 10:32:59 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------------------------- [Test]
/*		pseudo code 	*/
//	1. 	continue to read from file and save into data-store 
//		until new-line is found
//	2.	extract line from data-store
//	3.	move remainder of data-buffer forward to fill the extracted line space
//	4.	return extracted line

#include "get_next_line.h"
#include <errno.h>
#include <stdio.h>

extern int errno;

int main()
{
	int		i;
	char	*gnl;

	int fd = open("test.txt", O_RDONLY | O_CREAT);
	printf("fd = %d\n", fd);

    if (fd == -1) 
	{
		printf("Error Number % d\n", errno);
		perror("Program");
	}

	i = 0;
	gnl = NULL;
	while ((gnl = get_next_line(fd)))
	{
		printf("-----------------------------------\n");
		printf("%s\n", gnl);
		if (gnl)
			free(gnl);
		i++;
	}

	if (close(fd) < 0) {
		perror("c1");
		exit(1);
	}
	printf("closed the fd.\n");

	return (0);
}
