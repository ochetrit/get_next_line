/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:29:33 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/13 16:33:02 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char			*last_temp(char *temp);
char			*get_next_line(int fd);
char			*end_of_file(char *temp);
char			*ft_strcpy(char *dest, char *src);
char			*ft_extend_temp(char *temp, char stock[BUFFER_SIZE], int n_oct);
char			*build_temp(int fd, int n_oct, char *temp);
unsigned int	ft_strlen(const char *str);
unsigned int	ft_strchr(const char *str, int character);

#endif
