#include <stdio.h>

int	main(void)
{
	char	str[] = "/* ************************************************************************** */\n/*                                                                            */\n/*                                                        :::      ::::::::   */\n/*   get_next_line_utils.c                              :+:      :+:    :+:   */\n/*                                                    +:+ +:+         +:+     */\n/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */\n/*                                                +#+#+#+#+#+   +#+           */\n/*   Created: 2023/08/28 06:48:44 by ribana-b          #+#    #+#             */\n/*   Updated: 2023/08/28 12:41:55 by ribana-b         ###   ########.fr       */\n/*                                                                            */\n/* ************************************************************************** */\n#include '../include/get_next_line.h'\n\nint	ft_strlen(char *str)\n{\t\nint	counter;\n\n\tcounter = 0;\n\tif (str == NULL)\n\t\treturn (counter);\n\twhile (str[counter] != '\0')\n\t\tcounter++;\n\treturn (counter);\n";
	int	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	printf("%d", counter);
	return (0);
}
