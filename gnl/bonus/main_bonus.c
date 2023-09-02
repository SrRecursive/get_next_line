/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:56:47 by ribana-b          #+#    #+#             */
/*   Updated: 2023/09/02 11:16:03 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		fd2;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	fd2 = open(argv[2], O_RDONLY);
	if (fd2 < 0)
	{
		return (1);
	}
	int	x = 0;
	int	y = 0;
	while (line = get_next_line(fd))
	{
		printf("%d: %s", x, line);
		free(line);
		x++;
		if (x % 2 == 0)
		{
			line = get_next_line(fd2);
			printf("%d: %s", y, line);
			free(line);
			y++;
		}
	}
	while (line = get_next_line(fd2))
	{
		printf("%d: %s", y, line);
		free(line);
		y++;
	}
//	while (x < 123)
//	{
//		line = get_next_line(fd);
//		printf("%d: %s", x, line);
//		free(line);
//		x++;
//	}
	close(fd);
	close(fd2);
	return (0);
}
