#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <strings.h>

int	main(int ac, char *av[])
{
	char	line[1000];
	char	**list;
	char	start_char[12];
	char	end_char[12];
	long	start;
	long	end;
	int		i = 0;
	int		j;
	long	total = 0;
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
		bzero(start_char, 12);
		bzero(end_char, 12);
		while (line[i + j] != '-')
		{
			start_char[j] = line[i + j];
			j++;
		}
		i += j + 1;
		j = 0;
		while (line[i + j] && line[i + j] != ',')
		{
			end_char[j] = line[i + j];
			j++;
		}
		start = atol(start_char);
		end = atol(end_char);
		while (start <=end)
		{
			int digit = 0;
			long	temp = start;
			while (temp > 0)
			{
				digit += 1;
				temp /= 10;
			}
			temp = start;
			start += 1;
			if (digit % 2)
				continue;
			int divider = 1;
			for (int i = 0; i < digit / 2; i++)
				divider *= 10;
			if (temp / divider == temp % divider)
			{
				total += temp;
				printf("%ld\n", temp);
			}
		}
		i += j + 1;
		// printf("%s-%s\n", start_char, end_char);
	}
	fclose(input);
	printf("%ld\n", total);
}