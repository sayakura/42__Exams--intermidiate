/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 22:11:07 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/04 19:39:35 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	Assignment name  : is_anagram
	Expected files   : is_anagram.c
	Allowed functions: 
	--------------------------------------------------------------------------------
	ALERT: OPTIMIZED SOLUTION REQUIRED.
	An anagram is a sequence of characters formed by rearranging the letters of
	another sequence, such as 'cinema', formed from 'iceman'.
	Given two strings as parameters, create a function able to tell whether or
	not the first string is an anagram of the second.
	The function must be declared as follows:
	int is_anagram(char *a, char *b);
	Considerations:
	- Be careful: the naive solution won't work on our big input, you have to
	find an optimized solution which will run in O(sa + sb) time (where sa is
	the length of a and sb length of b).
	- Our tested string will always be a sequence of ascii characters between 32
	and 126 inclusive.
	- The bigger test we will do is on 2 sequences of 1.000.000 characteres each.
	It should run in less than 2 seconds.
	Example 1:
	a='abcdef'
	b='fabcde'
	In this case, these two strings are anagrams, your function should return 1.
	Example 2: 
	a='.123?.'
	b='?321..'
	In this case, these two strings are anagrams, your function should return 1.
	Example 3:
	a='abca'
	b='bcab'
	In this case, these two strings are not anagrams, your function should return 0.
*/
/* you can also use a int as a container instead of array, but this one is like a 
mini hashtable, make more senses I guess.*/
int is_anagram(char *a, char *b)
{
	unsigned i = 0;
	int  times[127] = {0};
	while (a[i] != '\0' && b[i] != '\0')
	{
		times[((int)a[i])]++;
		times[((int)b[i])]--;
		i++;
	}
	if (b[i] != '\0' || a[i] != '\0')
		return (0);
	i = 0;
	while (i < 127)
		if (times[i++] != 0)
			return (0);
	return (1);
}

int	is_anagram(char *a, char *b)
{
	char	hm[126] = {};

	for (int i = 0; a[i] && b[i]; i++)
	{
		hm[(int)a[i]]++;
		hm[(int)b[i]]--;
	}
	for (int i = 0; i < 126; i++)
		if (hm[i])
			return (0);
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram(".123?.", "?321.."));
	printf("%d\n", is_anagram("abca", "bcab"));
	return (0);
}
*/
