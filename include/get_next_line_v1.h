/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 05:01:01 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/28 06:39:18 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* <--Defines Section--> */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* <--Libraries Section--> */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* <--Structs Section--> */
typedef struct s_storage
{
	char				*line;
	int					linelen;
	int					afternl;
	struct s_storage	*next;
}						t_storage;

/* <--Functions Section--> */

int			ft_strlen(char *str);
char		*buff_to_line(char *buffer, t_storage *storage, int bytes);
t_storage	*format_line(t_storage *storage);
t_storage	*get_current_line(t_storage *storage, int fd);
void		full_free(t_storage **storage);
char		*get_next_line(int fd);

#endif
