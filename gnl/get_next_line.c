#include "get_next_line.h"

char	*get_current_line(char *buffer, int fd)
{
	static char	*temp = NULL;
	char		*line;
	int			bytesread;
	int			nl_index;

	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(temp, buffer, bytesread);
		nl_index = check_newline(temp);
		if (nl_index >= 0)
			break ;
	}
	nl_index = check_newline(temp);
	if (nl_index >= 0)
	{
		line = get_line(temp, nl_index);
		temp = fix_temp(temp, nl_index);
		return (line);
	}
	else
	{
		free(temp);
		temp = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = get_current_line(buffer, fd);
	free(buffer);
	if (line == NULL)
		return (NULL);
	return (line);
}
