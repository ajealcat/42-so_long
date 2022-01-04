/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:49:32 by ajearuth          #+#    #+#             */
/*   Updated: 2021/06/23 11:16:29 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_dupline(char **line, char *buffer)
{
	char	*tmp_line;

	tmp_line = ft_strnjoin(*line, buffer, ft_strlen(buffer));
	if (tmp_line == NULL)
		return (-1);
	free(*line);
	*line = ft_strndup(tmp_line, -1);
	free(tmp_line);
	if (line == NULL)
		return (-1);
	return (1);
}

static int	ft_ret(char **line, char *buffer, int ret_buffer)
{
	int	i;
	int	index;

	if (ret_buffer == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (ft_find_end(buffer, '\n') == -1)
	{
		ft_dupline(line, buffer);
		buffer[0] = '\0';
		return (0);
	}
	else
	{
		ft_dupline(line, buffer);
		i = -1;
		index = ft_find_end(buffer, '\n');
		while (buffer[index + ++i + 1])
			buffer[i] = buffer[index + i + 1];
		buffer[i] = '\0';
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	int			ret_buffer;

	*line = NULL;
	if (BUFFER_SIZE <= 0 || !line || read(fd, buffer[fd], 0) == -1)
		return (-1);
	if (ft_strlen(buffer[fd]) == 0)
	{
		ret_buffer = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][ret_buffer] = '\0';
		*line = NULL;
	}
	else
		ret_buffer = BUFFER_SIZE;
	while (ret_buffer == BUFFER_SIZE && ft_find_end(buffer[fd], '\n') == -1)
	{
		ft_dupline(line, buffer[fd]);
		ret_buffer = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][ret_buffer] = '\0';
	}
	return (ft_ret(line, buffer[fd], ret_buffer));
}
