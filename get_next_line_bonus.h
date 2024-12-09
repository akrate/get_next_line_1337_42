/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:58:39 by aoussama          #+#    #+#             */
/*   Updated: 2024/12/08 16:34:58 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strchr(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*get_left_line(char *str);
char	*get_right_line(char *str);

int		ft_strlen(char *str);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef MAX_FD
#  define MAX_FD 1023
# endif

#endif