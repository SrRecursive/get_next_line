/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:30:27 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/06 12:02:41 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *temp, int fd)
{
	char	*buffer;
	int		bytesread;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(temp);
		return (NULL);
	}
	bytesread = 1;
	while (bytesread > 0 && ft_strchr_gnl(temp, '\n') < 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*read_temp(char *temp)
{
	char	*line;
	int		index;

	if (temp[0] == '\0')
		return (NULL);
	index = 0;
	while (temp[index] != '\n' && temp[index] != '\0')
		index++;
	line = (char *)malloc((index + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	index = 0;
	while (temp[index] != '\n' && temp[index] != '\0')
	{
		line[index] = temp[index];
		index++;
	}
	line[index] = temp[index];
	line[index + 1] = '\0';
	return (line);
}

char	*read_temp_again(char *temp)
{
	char	*newtemp;
	int		index;
	int		counter;

	if (temp == NULL)
		return (NULL);
	index = 0;
	while (temp[index] != '\n' && temp[index] != '\0')
		index++;
	if (temp[index] == '\n')
		index++;
	counter = 0;
	while (temp[index + counter] != '\0')
		counter++;
	newtemp = (char *)malloc((counter + 1) * sizeof(char));
	if (newtemp == NULL)
		return (NULL);
	counter = -1;
	while (temp[index + ++counter] != '\0')
		newtemp[counter] = temp[index + counter];
	newtemp[counter] = '\0';
	free(temp);
	return (newtemp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (temp == NULL)
	{
		temp = (char *)malloc(1 * sizeof(char));
		if (temp == NULL)
			return (NULL);
		temp[0] = '\0';
	}
	temp = read_file(temp, fd);
	if (temp == NULL)
		return (NULL);
	line = read_temp(temp);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
	}
	temp = read_temp_again(temp);
	return (line);
}
