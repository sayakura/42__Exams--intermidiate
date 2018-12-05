
/*
COUNT_ISLAND
Assignment name  : count_island
Expected files   : *.c, *.h
Allowed functions: open, close, read, write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a file that contains lines of equal length. Those
lines contain characters that are either '.' or 'X'. All those lines put
together form rectangles of '.' containing "islands" of 'X'.
The maximum size of a line is 1024 characters, including the terminating
newline.
A column if formed of the set of characters in the file that are separated from
the start of their respective lines by the same number of characters.
Two characters are said to be touching if they are contiguous and on the same
line, or on contiguous lines and on the same column.
An "island" of 'X' means a set of 'X' touching each other.
The program must walk though the file and display it after replacing all the
'X' by a number corresponding to the position their island appears in the file,
starting at the beginning of the file.
There can be only one result.
If the file is empty, or there is an error (Incoherent input, for example), or
no parameters are passed, the program must display a newline.
The file contains at most 10 islands.
You will find examples in the subject directory.
Examples:
$>cat toto
.................XXXXXXXX..........................................
....................XXXXXXXXX.......XXXXXXXX.......................
.................XXXXXXXX..............XXX...XXXXX.................
.....................XXXXXX.....X...XXXXXXXXXXX....................
................................X..................................
......XXXXXXXXXXXXX.............X..................................
..................X.............XXXXXXXXX..........................
..................X.........XXXXXXXXXXXX...........................
..................X................................................
XX.............................................................XXXX
XX..................XXXXXXXXXXXXX.................................X
...................................................................
.................................................................X.
.....................XXXXX.......................................XX
$>
$>./count_island toto
.................00000000..........................................
....................000000000.......11111111.......................
.................00000000..............111...11111.................
.....................000000.....2...11111111111....................
................................2..................................
......3333333333333.............2..................................
..................3.............222222222..........................
..................3.........222222222222...........................
..................3................................................
44.............................................................5555
44..................6666666666666.................................5
...................................................................
.................................................................7.
.....................88888.......................................77
$>
$>cat qui_est_la
...................................................................
...X........X.....XXXXX......XXXXXXX...XXXXXXXXXX..XXXXXXXXXX......
...XX......XX....XX...XX....XX.....XX.....XXXX.....XXXXXXXXXX......
...XXXX..XXXX...XX.....XX...XX.....XX......XX......XX..............
...XX.XXXX.XX...XX.....XX...XX.....XX......XX......XX..............
...XX...X..XX...XX.....XX...XXXXXXXX.......XX......XXXXX...........
...XX......XX...XXXXXXXXX...XXXX...........XX......XXXXX...........
...XX......XX..XX.......XX..XX.XX..........XX......XX..............
...XX......XX..XX.......XX..XX...X.........XX......XX..............
...XX......XX..XX.......XX..XX....X......XXXXXX....XXXXXXXXXX......
...XX......XX.XX.........XX.XX.....XX..XXXXXXXXXX..XXXXXXXXXX..X...
...................................................................
$>
$>./count_island qui_est_la
...................................................................
...0........0.....11111......2222222...3333333333..4444444444......
...00......00....11...11....22.....22.....3333.....4444444444......
...0000..0000...11.....11...22.....22......33......44..............
...00.0000.00...11.....11...22.....22......33......44..............
...00...0..00...11.....11...22222222.......33......44444...........
...00......00...111111111...2222...........33......44444...........
...00......00..11.......11..22.22..........33......44..............
...00......00..11.......11..22...5.........33......44..............
...00......00..11.......11..22....6......333333....4444444444......
...00......00.11.........11.22.....77..3333333333..4444444444..8...
...................................................................
$>
$>cat -e rien
$>./count_island rien | cat -e
$
$>
*/


#include <unistd.h>
#include <fcntl.h>

void	flood_fill(char *map, int i, char c, int width, int total_b)
{
	map[i] = c;
	if (i > width && map[i - width] == 'X')
		flood_fill(map, i - width, c, width, total_b);
	if (i + width < total_b - 1 && map[i + width] == 'X')
		flood_fill(map, i + width, c, width, total_b);
	if (i - 1 >= 0 && map[i - 1] == 'X')
		flood_fill(map, i - 1, c, width, total_b);
	if (i + 1 < total_b - 1 && map[i + 1] == 'X')
		flood_fill(map, i + 1, c, width, total_b);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char map[102400] = {0};
	int fd = open(av[1], O_RDONLY);
	int total_b = read(fd, map, 102400);

	if (total_b <= 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	int width = 1;
	int i = 0;
	while (map[i] != '\n')
	{
	 	i++;
		width++;
	}
	int height = 0;
	for (int i = 0; i < total_b; i++)
	{
		if (map[i] != 'X' && map[i] != '.' && map[i] != '\n' && map[i] != '\0')
		{
			write(1, "\n", 1);
        	return (0);
		}
		if (map[i] == '\n')
			height++;
	}

	if (height * width != total_b)
	{
		write(1, "\n", 1);
		return (0);
	}
	char replacer = '0';
	for (int i = 0; i < total_b; i++)
	{
		
		if (map[i] == 'X') 
		{
			flood_fill(map, i, replacer, width, total_b);
			replacer++;
		}
	}
	if (replacer > ':')
	{
		write(1, "\n", 1);
        return (0);
	}
	write(1, map, total_b);
}
