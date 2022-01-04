/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:26 by ajearuth          #+#    #+#             */
/*   Updated: 2021/06/23 10:54:39 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		ft_strlen(char *str);
char	*ft_strndup(char *str, int n);
char	*ft_strnjoin(char *s1, char *s2, int n);
int		ft_find_end(const char *str, char c);
int		get_next_line(int fd, char **line);
char	*ft_next_buffer(char *new_buffer, char *buffer);

#endif
