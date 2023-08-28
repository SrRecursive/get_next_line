/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:49:58 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/28 06:38:58 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

void	full_free(t_storage **storage)
{
	if ((*storage)->line != NULL)
	{
		free((*storage)->line);
	}
	free(*storage);
}

char	*buff_to_line(char *buffer, t_storage *storage, int bytes)
{
	char	*newstr;
	int		newstrlen;

	storage->linelen = 0;
	if (storage->line != NULL)
	{
		storage->linelen = ft_strlen(storage->line);
	}
	newstrlen = storage->linelen + bytes;
	newstr = (char *)malloc((newstrlen + 1) * sizeof(char));
	if (newstr == NULL)
	{
		return (NULL);
	}
	newstr[newstrlen--] = '\0';
	while (bytes--)
	{
		newstr[newstrlen--] = buffer[bytes];
	}
	while (storage->linelen--)
	{
		newstr[newstrlen--] = storage->line[storage->linelen];
	}
	return (newstr);
}
