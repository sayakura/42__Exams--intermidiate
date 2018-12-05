#include <unistd.h>

int len(char *str) // ft_strlen
{
	int len = 0;
	while(str[len] != '\0')
		len++;
	return (len);
}
// function that takes two string and find if a substring of the second is also presented in the other one.
int     ft_strstr(char *str1, char *str2, int start, int end) // the substring is defined as the characters between start and end of str2.
{
    for (int i = 0, beg = start; str1[i]; i++, start = beg)
    {
        for (;str1[i] == str2[start] && start < end; i++, start++) // simple str compare.
            ;
        if (start == end)
            return (1);
        else
            i -= start - beg; // moves i back to where it at before if not matched.
    }
    return (0);
}
int		main(int ac, char **av)
{
	if (ac >= 2)
	{
		int	min_len = 2147483647;
		int min_i = 1; 
		for (int i = 1; i < ac; i++)
		{
			int clen = len(av[i]); // len of the current string
			if (clen < min_len) // find the av that has the shortest length
			{	
				min_len = clen; // save the len
				min_i = i; // save the index so we can refer it later
			}
		} // by using an offset, we can represent the largest substring bewteen j and j + offset of av[min_i] (the shortest av). it's initialized as min_len.
		for(int i = 0, match, offset = min_len; i < min_len ; i++, offset--) // we try offset = min_len first, see if all av contains av[min_i], if not, we shrink it 1 char less.
			for(int j = 0; j <= i; j++) 
			{
				match = 0;
				for (int avi = 1; avi < ac; avi++) // check if current substr can be found across all avs.
					if (avi != min_i && ft_strstr(av[avi], av[min_i], j, j + offset)) // we dont compare ourselves.
						match++;
				if(match == ac - 2) // minus the name of the program and the av[min_i] it self.
				{
					for (int i = j; i < j + offset; i++) // print the substr of av[min_i]
						write(1, &(av[min_i][i]), 1);
					write(1, "\n", 1);
					return (0);
				}
			}
	}
	write(1, "\n", 1);
	return (0);
}