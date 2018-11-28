#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	floodfill(int total, char *buf, int width, int i, char c)
{
	if (buf[i] == 'X')
		buf[i] = c;
	if (i > width && buf[i - width] == 'X')
		floodfill(total, buf, width, i - width, c);
	if ((i + width < total - 1) && buf[i + width] == 'X')
		floodfill(total, buf, width, i + width, c);
	if (i && (i + 1 < total) && buf[i + 1] == 'X')
		floodfill(total, buf, width, i + 1, c);
	if (i && (i % width > 0) && buf[i - 1] == 'X')
		floodfill(total, buf, width, i - 1, c);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char buf[1000000];
	int fd = open(av[1], O_RDONLY);
	int b_read = read(fd, buf, 1000000);
	int width = 0;
	int height = 1;
	while (buf[width] != '\n')
		width++;
	width++;
	for (int i = 0; i < b_read - 1; i++)
	{ 
		if (buf[i] != '.' && buf[i] != 'X' && buf[i] != '\n')
		{
			write(1, "\n", 1);
			return 0;
		}
		if (buf[i] == '\n')
			height++;
	}
	if (b_read / width != height)
	{
		write(1, "\n", 1);
		return (0);
	}
	char c = '0';
	for (int i = 0; i < b_read; i++)
	{
		if (buf[i] == 'X')
		{
			floodfill(b_read, buf, width, i, c);
			c++;
		}
	}
	write(1, buf, b_read);
	return (0);
}
