/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:57:24 by aoussama          #+#    #+#             */
/*   Updated: 2024/12/09 14:14:55 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_accimulate(int fd, char *remainder)
{
	int		read_size;
	char	*str_read;

	if (fd < 0)
		return (NULL);
	str_read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str_read)
		return (NULL);
	read_size = read(fd, str_read, BUFFER_SIZE);
	while (read_size > 0)
	{
		str_read[read_size] = '\0';
		remainder = ft_strjoin(remainder, str_read);
		if (ft_strchr(remainder) != -1)
			break ;
		read_size = read(fd, str_read, BUFFER_SIZE);
	}
	if (read_size == -1)
	{
		free(str_read);
		free(remainder);
		return (NULL);
	}
	free(str_read);
	return (remainder);
}

static char	*extract_next_line(char **remainder)
{
	char	*line;

	if (!*remainder || ft_strlen(*remainder) == 0)
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	line = get_left_line(*remainder);
	*remainder = get_right_line(*remainder);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];

	if (MAX_FD >= 1024)
		return (NULL);
	remainder[fd] = read_and_accimulate(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	return (extract_next_line(&remainder[fd]));
}
