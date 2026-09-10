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
	    int	i = 0;
        int highest = 0;
        int highest_position;
        while (line[i] && isdigit(line[i + 1]))
        {
            if (line[i] - 48 > highest)
            {
                highest = line[i] - 48;
                highest_position = i;
            }
            i++;
        }
        i = highest_position + 1;
        int second = 0;
        while (line[i])
        {
            if (line[i] - 48 > second)
                second = line[i] - 48;
            i++;
        }
        printf("%d\n", highest * 10 + second);
        total += highest * 10 + second;
    }
	fclose(input);
	printf("%ld\n", total);
}