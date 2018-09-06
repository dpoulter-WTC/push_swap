/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:11:41 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/06 12:08:56 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_gnl2(char buf[BUFF_SIZE + 1], char **l, int *r, const int fd)
{
	int	i;
	int j;

	i = -1;
	while (*r > 0)
	{
		j = 0;
		while (j < *r)
		{
			(*l)[++i] = buf[j++];
			if ((*l)[i] == '\n')
			{
				ft_strcpy(&buf[0], &buf[j]);
				(*l)[i] = '\0';
				return (1);
			}
		}
		*r = read(fd, &buf[0], BUFF_SIZE);
		buf[*r] = 0;
	}
	if (i >= 0)
		return (1);
	else
		return (0);
}

int			ft_gnl(const int fd, char **line)
{
	static char		buf[1000][BUFF_SIZE + 1];
	int				ret;
	int				i;

	if (!line || fd < 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!(*line = ft_strnew(52001)))
		return (-1);
	ret = ft_strlen(&buf[fd][0]);
	if (!ret)
		ret = read(fd, &buf[fd][0], BUFF_SIZE);
	buf[fd][ret] = 0;
	i = ft_gnl2((char*)(buf[fd]), &*line, &ret, fd);
	if (ft_strlen(*line) > 0 || i == 1)
		return (1);
	free(*line);
	return (ret);
}
