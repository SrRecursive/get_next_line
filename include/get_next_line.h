/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 06:47:33 by ribana-b          #+#    #+#             */
/*   Updated: 2023/08/28 13:20:04 by ribana-b         ###   ########.fr       */
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

/* <--Functions Section--> */

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *s1);
char	*get_line(char *s2, int bytes);
char	*fix_temp(char *s1, int nl_index);
char	*get_current_line(char *buffer, int fd);
char	*get_next_line(int fd);

#endif
