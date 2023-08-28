/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:51 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/28 06:39:30 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

t_storage	*format_line(t_storage *storage)
{
	t_storage	*new;
	int 		length;
	int			i;

	new = (t_storage *)malloc(sizeof(t_storage));
	if (new == NULL)
	{
		return (NULL);
	}
	i = 0;
	new->next = NULL;
	length = storage->linelen - storage->afternl;
	new->line = (char *)malloc((length + 1) * sizeof(char));
	if (new->line == NULL)
	{
		return (NULL);
	}
	new->line[length] = '\0';
	while (i < length)
	{
		new->line[i] = storage->line[i + storage->afternl + 1];
		storage->line[i + storage->afternl] = '\0';
		i++;
	}
	storage->next = new;
	return (storage);
}

int	check_newline(t_storage *storage)
{
	int	counter;

	counter = 0;
	while (storage->line[counter] != '\n')
	{
		counter++;
	}
	storage->afternl = counter;
	while (storage->line[counter] != '\0')
	{
		counter++;
	}
	storage->linelen = counter;
	return (counter);
}

t_storage	*get_current_line(t_storage *storage, int fd)
{
	char	*buffer;
	int		bytesread;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0)
	{
		storage->line = buff_to_line(buffer, storage, bytesread);
		if (storage->line == NULL)
		{
			free(buffer);
			return (NULL);
		}
		if (check_newline(storage) != -1)
		{
			storage = format_line(storage);
			free(buffer);
			return (storage);
		}
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	t_storage	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	storage = (t_storage *)malloc(sizeof(t_storage));
	if (storage == NULL)
	{
		return (NULL);
	}
	storage->line = NULL;
	storage->next = NULL;
	storage = get_current_line(storage, fd);
	line = storage->line;
	if (line == NULL)
	{
		full_free(&storage);
		return (NULL);
	}
	t_storage	**temp;
	temp = &storage;
	storage = storage->next;
	full_free(temp);
	return (line);
}
