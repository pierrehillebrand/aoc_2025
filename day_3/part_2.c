#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <strings.h>
#include <ctype.h>

int	main(int ac, char *av[])
{
	char	line[1000];
	int		j;
	long	total = 0;
	int		count = 0;
	bzero(line, 1000);
	line[4] = 0;
	if (ac != 2)
		return (printf("pas de nom\n"));
	FILE	*input = fopen(av[1], "r");
    while (fgets(line, 1000, input))
    {
        long number = 0;
        int len = 0;
        while (line[len] && isdigit(line[len]))
            len++;
        int highest_position = -1;
        for (int loop = 11; loop >= 0; loop--)
        {
	        int	i = highest_position + 1;
            long highest = 0;
            while (i < len - loop)
            {
                if (line[i] - 48 > highest)
                {
                    highest = line[i] - 48;
                    highest_position = i;
                }
                i++;
            }
            number = number * 10 + highest;
        }
        printf("%ld\n", number);
        total += number;
    }
	fclose(input);
	printf("%ld\n", total);
}