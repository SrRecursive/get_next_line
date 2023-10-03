/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:42:59 by ribana-b          #+#    #+#             */
/*   Updated: 2023/10/03 13:52:38 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *str, char *str2);
int		ft_strlen(const char *str);
int		ft_strchr(char *str, int character);
char	*read_file(char *temp, int fd);
char	*read_temp(char *temp);
char	*read_temp_again(char *temp);
char	*get_next_line(int fd);

#endif
