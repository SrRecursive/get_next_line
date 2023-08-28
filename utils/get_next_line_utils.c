/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 06:48:44 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/28 10:06:04 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen(char *str)
{
	int	counter;

	if (str == NULL)
	{
		return (0);
	}
	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		counter;
	int		counter2;

	counter = 0;
	counter2 = 0;
	newstr = (char *)malloc((ft_strlen(s1) + BUFFER_SIZE + 1) * sizeof(char));
	if (newstr == NULL)
	{
		return (NULL);
	}
	while (counter < ft_strlen(s1))
	{
		newstr[counter] = s1[counter];
		counter++;
	}
	while (counter2 < BUFFER_SIZE)
	{
		newstr[counter] = s2[counter2];
		counter++;
		counter2++;
	}
	newstr[counter] = '\0';
	return (newstr);
}

int	check_newline(char	*s1)
{
	int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (s1[index] == '\n')
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

char	*get_line(char *s2, int bytes)
{
	char	*s1;

	s1 = (char *)malloc((bytes + 1) * sizeof(char));
	if (s1 == NULL)
	{
		return (NULL);
	}
	s1[bytes] = '\0';
	while (bytes--)
	{
		s1[bytes] = s2[bytes];
	}
	return (s1);
}

char	*fix_temp(char *s1, int nl_index)
{
	char	*newstr;
	int		counter;

	counter = 0;
	newstr = (char *)malloc((ft_strlen(s1) - nl_index + 1) * sizeof(char));
	if (newstr == NULL)
	{
		return (NULL);
	}
	while (counter < ft_strlen(s1) - nl_index)
	{
		newstr[counter] = s1[nl_index + 1 + counter];
		counter++;
	}
	newstr[counter] = '\0';
	free(s1);
	return (newstr);
}
