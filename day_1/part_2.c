#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <strings.h>

int	main(int ac, char *av[])
{
	char	line[10];
	bzero(line, 10);
	line[4] = 0;
	int	mult;
	int	number;
	int	position = 50;
	int	count = 0;
	int previous;
	if (ac != 2)
		return (printf("pas de nom\n"));
	FILE	*input = fopen(av[1], "r");
	printf("start\n");
	while (fgets(line, 10, input))
	{
		// printf("%s", line);
		if (line[0] == 'L')
			mult = -1;
		else
			mult = 1;
		number = atoi(line + 1);
		previous = position;
		position = (position + number * mult);
		printf("position avant modif: %d\n", position);
		if (position == 0)
		{
			count++;
			printf("+1\n");
		}
		if (position < -99 || position > 99)
		{
			printf("+%d\n", abs(position / 100) + (position < 0 && position % 100 == 0));
			count += abs(position / 100) + (position < 0 && position % 100 == 0);
		}
		position %= 100;
		if (position < 0)
		{
			if (previous != 0)
			{
				count += 1;
				printf("+1\n");
			}
			position = 100 + position;
		}
		printf("%d\n", position);
		// count += position == 0;
		bzero(line, 10);
		// if (position < 0)
		// 	position = 100 + (position % 100);
		// printf("%d\n", position);
	}

	printf("\n%d\n", count);
	fclose(input);
}
