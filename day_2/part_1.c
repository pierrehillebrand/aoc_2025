#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <strings.h>

int	main(int ac, char *av[])
{
	char	line[1000];
	char	**list;
	char	start[12];
	char	end[12];
	int		i = 0;
	int		j;
	int		count = 0;
	bzero(line, 1000);
	line[4] = 0;
	if (ac != 2)
		return (printf("pas de nom\n"));
	FILE	*input = fopen(av[1], "r");
	fgets(line, 1000, input);
	while (line[i])
	{
		j = 0;
		bzero(start, 12);
		bzero(end, 12);
		while (line[i + j] != '-')
		{
			start[j] = line[i + j];
			j++;
		}
		i += j + 1;
		j = 0;
		while (line[i + j] && line[i + j] != ',')
		{
			end[j] = line[i + j];
			j++;
		}
		i += j + 1;
		printf("%s-%s\n", start, end);
		printf("%ld-%ld\n", atol(start), atol(end));
	}
}