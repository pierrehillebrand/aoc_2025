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
	if (ac != 2)
		return (printf("pas de nom\n"));
	FILE	*input = fopen(av[1], "r");
	while (fgets(line, 10, input))
	{
		// printf("%s", line);
		if (line[0] == 'L')
			mult = -1;
		else
			mult = 1;
		number = atoi(line + 1) % 100;
		position = (position + number * mult) % 100;
		printf("%d\n", position);
		count += position == 0;
		// if (position < 0)
		// 	position = 100 + (position % 100);
		// printf("%d\n", position);
	}

	printf("\n%d\n", count);
	fclose(input);
}
