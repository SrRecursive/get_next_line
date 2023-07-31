/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:48:36 by ribana-b          #+#    #+#             */
/*   Updated: 2023/07/18 10:44:52 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	t_gnlu	*gnl;
	int i = 0;

	gnl = (t_gnlu *)malloc(sizeof(t_gnlu));
	while (read(fd, gnl -> buffer, BUFFER_SIZE) > 0)
	{
		printf("%c", gnl -> buffer[i]);
		i++;
	}
	return (gnl -> line);
}

int	main(void)
{
	int	fd = open("../text1", O_RDWR);
	printf("%s", get_next_line(fd));
}
