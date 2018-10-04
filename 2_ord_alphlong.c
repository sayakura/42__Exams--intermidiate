/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ord_alphlong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:09:55 by kpeng             #+#    #+#             */
/*   Updated: 2018/10/04 02:10:04 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*------------------------------------------------------------------------------
Assignment name  : ord_alphlong
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string as a parameter and prints its words sorted
in order of their length first and then in alphabetical order on each line:
when we say alphabetical order we ignore the case of letters.
For example aA and Aa are the same but the  original order must remain
(lower and upper case are the same in alphabetical order). If there are
duplicates, they must remain.
If number of parameters is different from 1, the program prints 
\n.
There will be only spaces, tabs and alphanumeric caracters in strings.
You'll print only one space between each word. Nothing before the first and 
after the last word of each line.
Examples:
$>./ord_alphlong
$
$>./ord_alphlong "De son baton il frappa la pierre et l eau jaillit" | cat -e
l$
De et il la$
eau son$
baton$
frappa pierre$
jaillit$
$>./ord_alphlong "A a b B cc ca cd" | cat -e
A a b B$
ca cc cd$
$>./ord_alphlong "Pour l Imperium de l humanite" | cat -e
l l$
de$
Pour$
humanite Imperium$
$>
------------------------------------------------------------------------------*/
#include <stdlib.h>
#include <unistd.h>

#define isspace(c) (c == ' ' || c == '\t' || c == '\n') ? 1 : 0

#define isupper(c) (c >= 'A' && c <= 'Z') ? 1 : 0

typedef struct s_word
{
	char 		*str;
	int 		len;
}				t_word;

void	pc(char c)
{
	write(1, &c, 1);
}

void 	ps(char *str)
{
	unsigned i = 0;
	while (str[i])
		pc(str[i++]);
}

int 	wc(char *str)
{
	int		 wc = 0;
	unsigned i = 0;
	while (str[i])
	{
		while (isspace(str[i]))
			i++;
		if (str[i] && !isspace(str[i]))
		{
			wc++;
			while (str[i] && !isspace(str[i]))
				i++;
		}
	}
	return (wc);
}

t_word 	*next_wd(char *str)
{
	t_word *word = (t_word *)malloc(sizeof(t_word));
	word->len = 0;
	while (str[word->len] && !isspace(str[word->len]))
		word->len++;
	word->str = malloc(sizeof(char) * word->len + 1);
	word->str[word->len] = '\0';
	word->len = 0;
	while (str[word->len] && !isspace(str[word->len]))
		word->str[word->len++] = str[word->len];
	return (word);
}

int		cmp(char *s1, char *s2)
{
	unsigned	i = 0;
	char 		c1, c2;

	do{
		c1 = s1[i];
		c2 = s2[i];
		if (isupper(s1[i]))
			c1 += 32;
		if (isupper(s2[i]))
			c2 += 32;
		if (!c1 && !c2)
			return (0);
		i++;
	}while (c1 == c2);
	return (c1 - c2);
}

void	sort(t_word **table, int size)
{
	unsigned	i = 0;
	t_word 		*temp;

	while (i < size - 1)
	{
		if (table[i]->len > table[i + 1]->len)
		{
			temp	      = table[i + 1];
			table[i + 1]  = table[i];
			table[i]	  = temp;
			i = 0;
		}
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		if (table[i]->len == table[i + 1]->len
			&& cmp(table[i]->str, table[i + 1]->str) > 0)
		{
			temp	  	 = table[i + 1];
			table[i + 1] = table[i];
			table[i]	 = temp;
			i = 0;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int len = 0, i = 0, temp = 0, size = 0;
	t_word **table;
	if (ac != 2)
	{
		pc('\n');
		return (0);
	}
	else
	{
		if (!av[1][0])
		{
			pc('\n');
			return (0);
		}
		size = wc(av[1]);
		table = malloc(sizeof(t_word *) * size);
		len = 0;
		while (av[1][i])
		{
			while (av[1][i] && isspace(av[1][i]))
				i++;
			if (av[1][i] == '\0')
				break ;
			table[len]= next_wd(av[1] + i);
			len++;
			while (av[1][i] && !isspace(av[1][i]))
				i++;
		}
		i = 0;
		sort(table, size);
		while (i < size)
		{
			if (i != 0 && len == table[i]->len)
				pc(' ');
			len = table[i]->len;
			ps(table[i]->str);
			free(table[i]);
			i++;
			if (i < size && len != table[i]->len)
				pc('\n');
		}
		pc('\n');
		free(table);
	}
	return (0);
}