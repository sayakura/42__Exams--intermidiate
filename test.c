
#include <unistd.h>
#include <stdlib.h>

int slen (char*in)
{
	int len = 0;
	while(in[len] != '\0')
		len++;
	return len;
}

int findstr(char *here, char *tofind)
{
	int i = -1;

	while(here[++i] != '\0')
	{
		int j = -1;
		int k = i;
		while (here[k++] == tofind[++j])
		{
			if (tofind[j+1] == '\0')
				return 1;
		}
	}
	return 0;
}

char * scopy(char *in, int start, int end)
{
	char * out = (char*) malloc(sizeof(char) * (end - start + 2));
	int i = 0;
	while(start <= end)
		out[i++] = in[start++];
	out[i] = '\0';
	return out;
}
#include <stdio.h>
int main (int ac, char **av)
{
	if (ac < 2)
		return(write(1, "\n", 1));
	char* minStr = "";
	int min = 2147483647;
	for (int i = 1; i < ac; i++)
    {
        int len = slen(av[i]);
		if	(len < min)
		{
			min = len;
			minStr = av[i];
		}
    }
	char * totry;
	int trylen = min;
	for(int i = 0; i <= min; i++)
	{
		for(int j = 0; j < i; j++)
		{
			totry = scopy(minStr, j, j + trylen);
			printf("%s %d %d\n", totry, j, j + trylen);
			int found = 0;
			for (int t = 1; t < ac; t++)
				found += findstr(av[t], totry);
			if(found == ac - 1)
			{
				write(1, totry, slen(totry));
				return(write(1, "\n", 1));
			}
		}
		trylen--;
	}
	return (write(1, "\n", 1));
}
