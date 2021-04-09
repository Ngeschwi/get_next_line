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

char	*ft_strdup(const char *str1)
{
	int		i;
	char	*str2;

	str2 = malloc(sizeof(char) * (ft_strlen(str1) + 1));
	if (!str2)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	if (((unsigned char *)dst) < ((unsigned char *)src))
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	return (dst);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *str, char *buff)
{
	int		len_str;
	int		len_buff;
	int		i;
	char	*dst;

	if (!str)
		return (ft_strdup(buff));
	len_str = ft_strlen(str) - 1;
	len_buff = ft_strlen(buff) - 1;
	dst = malloc(sizeof(char) * (len_str + len_buff + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i++])
		dst[i] = str[i];
	free(str);
	str = NULL;
	i = 0;
	while (buff[i++])
		dst[len_str + i] = buff[i];
	dst[len_str + i] = '\0';
	return (dst);
}
