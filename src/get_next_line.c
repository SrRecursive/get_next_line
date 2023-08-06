/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:48:36 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/06 17:01:20 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	check_newline(char *buffer)
{
	int	position;

	if (buffer == NULL)
	{
		return (-1);
	}
	position = 0;
	while (buffer[position] != '\0' && buffer[position] != '\n')
	{
		position++;
	}
	return (position);
}

char	*get_line(int fd)
{
	char	*line;
	char	*buffer;
	int		bytesread;
	int		position;

	buffer = ft_calloc(BUFFER_SIZE + 1, (int)sizeof(char));
	if (buffer == NULL)
	{
		return (NULL);
	}
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0)
	{
		position = check_newline(buffer);
		if (position >= 0)
		{
			line = ft_strlcpy(line, buffer, position);
			if (line == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}	
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	line = get_line(fd);
	if (line == NULL)
	{
		return (line);
	}
	return (line);
}
