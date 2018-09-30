/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 23:49:45 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/29 00:07:36 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 	Assignment name  : count_alpha
	Expected files   : count_alpha.c
	Allowed functions: write, printf
	--------------------------------------------------------------------------------

	Write a program called count_alpha that takes a string and displays the number
	of occurences of its alphabetical characters. Other characters are not counted.
	The order is the order of occurence in the string. The display must be ended by
	a newline.

	The format is in the examples.

	If the number of arguments is not 1, display only a newline.

	Examples :
	$> ./count_alpha abbcc
	1a, 2b, 2c
	$> ./count_alpha "abbcc"
	1a, 2b, 2c
	$> ./count_alpha "abbcc" "dddeef" | cat -e
	$
	$> ./count_alpha "My Hyze 47y 7." | cat -e
	1m, 3y, 1h, 1z, 1e$
	$> ./count_alpha "" | cat -e
	$
*/
#include <stdio.h>

int		is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if ( c >= 'A' && c <= 'Z')
		return (2);
	else
		return (0);
}

void	push_back(char key, char *let, unsigned *cnt)
{
	unsigned i = 0;
	while (i < 27)
	{
		if (let[i] == key)
		{
			cnt[i]++;
			break ;
		}
		if (let[i] == 0)
		{
			let[i] = key;
			cnt[i] = 1;
			break ;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	char 		let[26] = {0};
	unsigned 	cnt[26] = {0};
	unsigned 	i = 0;
	unsigned	print = 0;
	while (av[1][i])
	{
		if (is_alpha(av[1][i]) == 1)
			push_back(av[1][i], let, cnt);
		else if (is_alpha(av[1][i]) == 2)
			push_back(av[1][i] + 32, let, cnt);
		i++;
	}
	i = 0;
	while (let[i] != 0)
	{
		if (print != 0)
			printf(", ");
		print = 1;
		printf("%d%c", cnt[i], let[i]);
		i++;
	}
	printf("\n");
}
