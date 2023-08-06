/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 05:01:01 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/06 17:02:27 by ribana-b         ###   ########.fr       */
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

/* <--Functions Section--> */

char	*ft_calloc(int nbytes, int size);
char	*ft_strlcpy(char *line, char *buffer, int position);
char	*get_next_line(int fd);
int		check_newline(char *buffer);
int		ft_strlen(char *str);

#endif
