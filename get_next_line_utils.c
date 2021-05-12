/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:17:27 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/06 15:17:27 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_if_define(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dst;

	if (str == NULL)
	{
		dst = malloc(sizeof(char) * 1);
		dst[0] = '\0';
		return (dst);
	}
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, int start, int end)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (end < start)
		return (NULL);
	if (end == 0 && start == 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	end--;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (start + i <= end && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char **str, char *buff)
{
	int		len_str;
	int		len_buff;
	int		i;
	char	*dst;

	i = -1;
	if (*str == NULL)
		return (ft_strdup(buff));
	len_str = ft_strlen(*str);
	len_buff = ft_strlen(buff);
	dst = malloc(sizeof(char) * (len_str + len_buff + 1));
	if (!dst)
		return (NULL);
	while (++i < len_str)
		dst[i] = (*str)[i];
	i = 0;
	while (i < len_buff)
	{
		dst[i + len_str] = buff[i];
		i++;
	}
	dst[i + len_str] = '\0';
	ft_free_if_define(str);
	return (dst);
}
