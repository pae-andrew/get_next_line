/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:34:11 by gcredibl          #+#    #+#             */
/*   Updated: 2020/12/07 17:58:38 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1, int i)
{
	size_t	len_str;
	char	*str;
	size_t	j;

	j = -1;
	if (i == 0)
		len_str = ft_strlen(s1);
	else
		len_str = i;
	if (!(str = malloc(sizeof(char) * (len_str + 1))))
		return (NULL);
	while (++j < len_str)
		str[j] = s1[j];
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len_s1 + len_s2 + 2))))
		return (NULL);
	while (++i < len_s1)
		str[i] = s1[i];
	while (j < len_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
