/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:51 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/28 15:51:35 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
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
//	while (line = get_next_line(fd))
//	{
//		printf("%d: %s", x, line);
//		free(line);
//		x++;
//	}
	while (x < 31)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%d: %s", x, line);
		free(line);
		x++;
	}
	close(fd);
	return (0);
}
