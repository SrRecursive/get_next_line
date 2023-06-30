/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@42student.malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 05:01:15 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/28 03:28:02 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *line;
    static char *buffer = NULL;

    line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    while (read(fd, line, BUFFER_SIZE))
    {

    }
    return (line);
}

// This is for testing

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("text", O_RDWR);
    for (int i = 0; i < 10; i++)
    {
        printf("%s", get_next_line(fd));
    }
}
