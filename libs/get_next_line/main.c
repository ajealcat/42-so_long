/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:14:22 by ajearuth          #+#    #+#             */
/*   Updated: 2021/06/23 10:34:58 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		fd;
	int		i;
	int		ret;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	i = 1;

	ret = 1;
	// faut pas faire de do while c'est interdit attention c'est juste pour le main
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		printf("Ligne %2d |% d|%s|\n", i, ret, line);
		free(line);
		++i;
	}
	close(fd);
	return (0);
}
