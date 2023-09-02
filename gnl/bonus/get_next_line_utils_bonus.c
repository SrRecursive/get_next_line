/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:56:43 by ribana-b          #+#    #+#             */
/*   Updated: 2023/09/02 11:05:11 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (counter);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2, int bytesread)
{
	char	*newstr;
	int		counter;
	int		counter2;

	counter = 0;
	counter2 = 0;
	newstr = (char *)malloc((ft_strlen(s1) + bytesread + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (counter < ft_strlen(s1))
	{
		newstr[counter] = s1[counter];
		counter++;
	}
	if (s1 != NULL)
		free(s1);
	while (counter2 < bytesread)
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
	if (s1 == NULL)
		return (-1);
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

	s1 = (char *)malloc((bytes + 2) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	s1[bytes + 1] = '\0';
	while (bytes >= 0)
	{
		s1[bytes] = s2[bytes];
		bytes--;
	}
	return (s1);
}

char	*fix_temp(char *s1, int nl_index)
{
	char	*newstr;
	int		counter;

	counter = 0;
	if (s1 == NULL)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s1[nl_index + 1 + counter] != '\0')
	{
		newstr[counter] = s1[nl_index + 1 + counter];
		counter++;
	}
	newstr[counter] = '\0';
	free(s1);
	return (newstr);
}
