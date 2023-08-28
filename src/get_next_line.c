/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 06:46:27 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/28 12:16:33 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_current_line(char *buffer, int fd)
{
	char		*line;
	static char	*temp = NULL;
	int			bytesread;
	int			nl_index;

	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(temp, buffer);
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
		free(temp);
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
