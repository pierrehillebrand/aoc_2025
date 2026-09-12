#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <strings.h>
#include <ctype.h>

int	main(int ac, char *av[])
{
    char     map[137][137];
	long	total = 0;
    int     lines = 0;
	if (ac != 2)
		return (printf("pas de nom\n"));
	FILE	*input = fopen(av[1], "r");
    int len;
    while (fgets(map[lines], 1000, input))
    {
        len = 0;
        while (map[lines][len] && (map[lines][len] == '.' || map[lines][len] == '@'))
            len++;
        map[lines][len] = 0;
        printf("%d: %s\n", len, map[lines]);
        lines++;
    }
	fclose(input);
    for (int line = 0; line < lines; line++)
    {
        for (int row = 0; row < len; row++)
        {
            int number_of_spaces = 8;
            if (map[line][row] == '.')
                continue;
            if (line > 0)
            {
                if (map[line - 1][row] == '@')
                    number_of_spaces--;
                if (row > 0 && map[line - 1][row - 1] == '@')
                    number_of_spaces--;
                if (row < len - 1 && map[line - 1][row + 1] == '@')
                    number_of_spaces--;
            }
            if (line < lines - 1)
            {
                if (map[line + 1][row] == '@')
                    number_of_spaces--;
                if (row > 0 && map[line + 1][row - 1] == '@')
                    number_of_spaces--;
                if (row < len - 1 && map[line + 1][row + 1] == '@')
                    number_of_spaces--;
            }
            if (row > 0 && map[line][row - 1] == '@')
                number_of_spaces--;
            if (row < len - 1 && map[line][row + 1] == '@')
                number_of_spaces--;
            if (number_of_spaces > 4)
            {
                // map[line][row] = 'x';
                total += 1;
            }
        }
        printf("%s\n", map[line]);
    }
	printf("\n%ld\n", total);
}