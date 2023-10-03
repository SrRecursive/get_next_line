/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:51:10 by ribana-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:52:13 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	counter;

	if (str == NULL)
		return (0);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	ft_strchr(char *str, int character)
{
	int	index;

	if (str == NULL)
		return (-2);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == character)
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_strjoin(char *str, char *str2)
{
	char	*newstr;
	int		counter;
	int		counter2;

	counter = ft_strlen(str);
	counter2 = ft_strlen(str2);
	newstr = (char *)malloc((counter + counter2 + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	newstr[counter + counter2] = '\0';
	while (counter2-- > 0)
		newstr[counter + counter2] = str2[counter2];
	while (counter-- > 0)
		newstr[counter] = str[counter];
	free(str);
	return (newstr);
}
