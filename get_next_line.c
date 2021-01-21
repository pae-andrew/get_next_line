/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:34:06 by gcredibl          #+#    #+#             */
/*   Updated: 2020/12/07 18:09:58 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i++])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int	read_line(char **str, char **hist, int fd)
{
	int		bytes;
	int		i;
	char	buf[BUFFER_SIZE + 1];
	char	*del;

	i = -1;
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		del = *str;
		*str = ft_strjoin(*str, buf);
		if ((i = check_str(*str)) != -1)
		{
			*hist = *str;
			free(del);
			return (i);
		}
		if (del)
			free(del);
	}
	if (bytes < 0)
		return (-1);
	if (bytes == 0)
		return (-2);
	return (i);
}

int	return_line(char **line, char **str, int i, char **hist)
{
	size_t	j;
	char	*tmp;

	j = ft_strlen(*str);
	if (!(*line = ft_strdup(*str, i)))
		return (-1);
	(*line)[i] = '\0';
	tmp = *str;
	if (!(*str = ft_strdup((*str) + i + 1, j - i + 1)))
		return (-1);
	(*str)[j - i + 1] = '\0';
	*hist = *str;
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char	*str;
	char	*buff[4096];
	int		i;

	str = NULL;
	if (!line || read(fd, str, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	str = buff[fd] ? buff[fd] : str;
	if ((i = check_str(str)) == -1)
		i = read_line(&str, line, fd);
	if (i == -2)
	{
		if (str)
		{
			*line = ft_strdup(str, 0);
			free(str);
		}
		else
			*line = ft_strdup("", 1);
		buff[fd] = NULL;
		return (0);
	}
	if (i < 0)
		return (-1);
	return (return_line(line, &str, i, &(buff[fd])));
}
