/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:48:10 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/06 17:01:11 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_calloc(int nbytes, int size)
{
	char	*str;

	str = (char *)malloc(nbytes * size);
	if (str == NULL)
	{
		return (NULL);
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	counter;

	if (str == NULL)
	{
		return (0);
	}
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strlcpy(char *line, char *buffer, int position)
{
	char	*str;
	int		counter;
	int		len;

	if (buffer == NULL || line == NULL)
	{
		return (NULL);
	}
	len = ft_strlen(line);
	str = ft_calloc((len + position + 1), sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	counter = 0;
	while (counter < (len + position))
	{
		if (counter < len)
		{
			str[counter] = line[counter];
		}
		else
		{
			str[counter] = buffer[counter - len];
		}
		counter++;
	}
	return (line);
}
