/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:19:45 by exam              #+#    #+#             */
/*   Updated: 2018/11/27 09:23:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int    count_of_2(int n)
{
	int cnt = 0;
	if ( n <= 1)
		return (0);
	for (int i = 2; i <= n; i++)
	{
		int temp = i;
		while (temp)
		{
			if (temp % 10 == 2)
				cnt++;
			temp /= 10;
		}
	}
	return cnt;
}
/*
#include <stdio.h>
int		main(void)
{
	printf("%d\n", count_of_2(4));
	return (0);
}*/
