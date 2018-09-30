#include <unistd.h>
#include <stdlib.h>
#define SIZE 256
#define pc(c) write(1, &c, 1);

void	ps(char *str)
{
	int i = 0;
	while (str[i])
		pc(str[i++]);
}

int ft_strlen(char *str)
{
 	int len = 0;
 	while (str[len])
 		len++;
 	return (len);   
}

int 	cmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (unsigned char)s1[i] - (unsigned char)s2[i];
}

char 	**str_permu(char str[], int n)  
{
	char **per;
	int len = (n * (n + 1)) / 2; 
	int col, row = 0;

	per = (char **)malloc(sizeof(char *) * len + 1);
	per[len - 1] = NULL; 
	for (int len = 1; len <= n; len++)
	{
		for (int i = 0; i <= n - len; i++)
		{
            int j = i + len - 1;
            per[row]= (char *)malloc(i + 2);
	      	per[row][i + 1] = '\0';
	      	col = 0;
			for (int k = i; k <= j; k++)
				per[row][col++] = str[k];
			row++;
		}
	}
    return (per);
} 
/* yes, it's freaking O(n)*/
int 	match(char *pat, char *str)
{
	int lp = ft_strlen(pat);
    int ls = ft_strlen(str);
    char p[SIZE] = {0}, s[SIZE] = {0};

    for (int i = 0; i < lp; i++)
    {
    	p[i] = pat[i];
    	s[i] = str[i];
    }
    for (int i = lp; i <= ls; i++)
    {
    	if (cmp(p, s + i - lp) == 0)
    		return (1);
    	s[i] = str[i];
    }
    return (0);
}

int main(int ac, char **av) {
	if (ac < 2)
	{
		ps("\n");
		return (0);
	}
	else if (ac == 2)
	{
		ps(av[1]);
		ps("\n");
		return (0);
	}
	else
	{
	    char **pat;
	    int len = ft_strlen(av[1]);
	    int av_i = 1;
	    char *arr_match;
 
	   	pat = str_permu(av[1], len);
	   	len = (len * (len + 1)) / 2;
	    arr_match = (char *)malloc(len);
	    for (int i = 0; i < len; i++)
	    	arr_match[i] = 1;
	   	while (av_i < ac)
	   	{
	   		for (int i = 0; i < len; i++)
	   			if (!match(pat[i], av[av_i]))
	   				arr_match[i] = 0;
	   		av_i++;
	   	}
	   	for (int i = len - 1; i >= 0; i--)
	   	{
	   		if (arr_match[i])
	   		{
	   			int p_len = ft_strlen(pat[i]);
	   			for (int j = i; j >= 0 && ft_strlen(pat[j]) == p_len; j--)
	   				if (j < i && arr_match[j])
	   					i = j;
	   			ps(pat[i]);
	   			ps("\n");
	   			break ;
	   		}
	   	}
	   	free(arr_match);
	   	free(pat);
	}
	return (0);
}
