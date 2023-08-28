/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:48:36 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/22 15:51:53 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*save_next_line(char *buffer, int bufferlength, int counter)
{
	char	*newbuffer;
	int		counter2;

	counter2 = 0;
	newbuffer = (char *)malloc(bufferlength * (sizeof(char)));
	if (newbuffer == NULL)
	{
		return (NULL);
	}
	while (bufferlength--)
	{
		newbuffer[counter2] = buffer[counter + counter2];
		counter2++;
	}
	free(newbuffer);
	return (buffer);
}

char	*ft_strcpy(char *line, char *buffer, int index, int bytesread)
{
	int	counter;
	int	counter2;

	counter = 0;
	counter2 = 0;
	while (counter < bytesread)
	{
		index++;
		if (buffer[counter] == '\n')
		{
			break ;
		}
		counter++;
	}
	line = (char *)malloc((index + counter + 1) * sizeof(char));
	if (line == NULL)
	{
		return (NULL);
	}
	line[index + counter] = '\0';
	while (counter2 < counter)
	{
		line[index + counter2] = buffer[counter2];
		counter2++;
	}
	buffer = save_next_line(buffer, bytesread - counter - 1, counter + 1);
	return (line);
}

char	*get_current_line(int fd)
{
	char		*line;
	static char	*buffer;
	int			bytesread;
	static int	index = 0;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
	{
		return (NULL);
	}
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0)
	{
		line = ft_strcpy(line, buffer, index, bytesread);
		if (line == NULL)
		{
			return (NULL);
		}
		bytesread = read(fd, buffer, BUFFER_SIZE);
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
	line = get_current_line(fd);
	if (line == NULL)
	{
		return (NULL);
	}
	return (line);
}
