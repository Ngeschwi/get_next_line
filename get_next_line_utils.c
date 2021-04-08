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

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *str1)
{
	int		i;
	char	*str2;

	if (!(str2 = (char*)malloc(ft_strlen(str1) * sizeof(char) + 1)))
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
	if (((unsigned char*)dst) < ((unsigned char*)src))
	{
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i--;
		}
	}
	return (dst);
}

char		*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
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

char		*ft_strjoin(char *str, char *buff)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!str)
		return (buff);
	if (!buff)
		return (NULL);
	len1 = ft_strlen(str);
	len2 = ft_strlen(buff);
	if (!(dst = (char*)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i++])
		dst[i] = str[i];
	free(str);
	str = NULL;
	i = 0;
	while (buff[i++])
		dst[len1 + i] = buff[i];
	dst[len1 + i] = '\0';
	return (dst);
}
