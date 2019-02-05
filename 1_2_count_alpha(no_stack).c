/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 20:20:31 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/04 20:43:45 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define cvt(c) (int)_tolower(av[1][c])

int		_isLetter(int c)
{
	return (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z');
}

char	_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	char hm[127];

	for (int i = 0; av[1][i]; i++)
		hm[(int)_tolower(av[1][i])]++;
	int printed = 0;
	for (int i = 0; av[1][i]; i++)
	{
		if (_isLetter(av[1][i]) && hm[cvt(i)])
		{
			if (!printed)
				printed = 1;
			else
				printf(", ");
			printf("%d%c", hm[cvt(i)], cvt(i));
			hm[cvt(i)] = 0;
		}
	}
	printf("\n");
	return (0);
}
