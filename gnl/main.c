#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	int	x = 0;
	while (line = get_next_line(fd))
	{
		printf("%d: %s", x, line);
		free(line);
		x++;
	}
//	while (x < 123)
//	{
//		line = get_next_line(fd);
//		printf("%d: %s", x, line);
//		free(line);
//		x++;
//	}
	close(fd);
	return (0);
}
