/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:51 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/06 16:14:20 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test1", O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		return (0);
	}
	printf("line 1: %s", line);
	free(line);
	return (0);
}
