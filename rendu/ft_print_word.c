/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <jee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:30:20 by james             #+#    #+#             */
/*   Updated: 2024/02/01 23:25:01 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

bool	ft_is_sep(char c)
{
	return (c == 0x20 || c == 0x09);
}

int	ft_print_word(char *str, int index, size_t numfrontspace)
{
	int		count;

	count = -1;
	while (*str)
	{
		++count;

		// to trim the front separator of word
		while (*str && ft_is_sep(*str))
			str++;
		
		// to print the space in front of the output word
		while (count == index && numfrontspace--)
			write(1, " ", 1);
		
		while (*str && !ft_is_sep(*str))
		{
			// to print the word based on specified index
			if (count == index)
				write(1, str, 1);
			str++;
		}

		// to trim the back separator of word
		// more to handle the space after the last word
		while (*str && ft_is_sep(*str))
			str++;
	}
	return (++count);
}

void	ft_rostring(char *str, size_t num_of_space)
{
	int	i;
	int	count;

	// pass a negative index to prevent any output
	// for getting the total number of words in string
	count = ft_print_word(str, -1, 0);

	// word[1] without space infront 
	ft_print_word(str, 1, 0);
	
	i = 1;
	while (++i < count)
		ft_print_word(str, i, num_of_space);

	//print word[0] with num_of_space infront
	ft_print_word(str, 0, num_of_space);
}

void	ft_rev_wstr(char *str, size_t num_of_space)
{
	int	i;
	
	// get the total number of words in string
	i = ft_print_word(str, -1, 0);
	
	// print the words in reverse order
	ft_print_word(str, --i, 0);
	while (i--)
		ft_print_word(str, i, num_of_space);
}

void	ft_epur_str(char *str, size_t num_of_space)
{
	int i;
	int	count;

	// get the total number of words in string
	count = ft_print_word(str, -1, 0);
	
	// print the words in reverse order
	ft_print_word(str, 0, 0);
	i = 0;
	while (++i < count)
		ft_print_word(str, i, num_of_space);
}

void	ft_expand_str(char *str, size_t num_of_space)
{
	int i;
	int	count;

	// get the total number of words in string
	count = ft_print_word(str, -1, 0);
	
	// print the words in reverse order
	ft_print_word(str, 0, 0);
	i = 0;
	while (++i < count)
		ft_print_word(str, i, num_of_space);
}

//-------------------------------[test]

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}

	printf("\n\n=========================[epur_str]\n");
	ft_epur_str(argv[1], 1);
	printf("\n\n=========================[expand_str]\n");
	ft_expand_str(argv[1], 3);
	printf("\n\n=========================[rostring]\n");
	ft_rostring(argv[1], 1);
	printf("\n\n=========================[rev_wstr]\n");
	ft_rev_wstr(argv[1], 1);

	return (0);
}

