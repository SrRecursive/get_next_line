/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:56:28 by ribana-b          #+#    #+#             */
/*   Updated: 2023/09/02 11:12:53 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_current_line(char *buffer, int fd)
{
	static char	*temp[1024];
	char		*line;
	int			bytesread;
	int			nl_index;

	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		temp[fd] = ft_strjoin(temp[fd], buffer, bytesread);
		nl_index = check_newline(temp[fd]);
		if (nl_index >= 0)
			break ;
	}
	nl_index = check_newline(temp[fd]);
	if (nl_index >= 0)
	{
		line = get_line(temp[fd], nl_index);
		temp[fd] = fix_temp(temp[fd], nl_index);
		return (line);
	}
	else
		free(temp[fd]);
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
