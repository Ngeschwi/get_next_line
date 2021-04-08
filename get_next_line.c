/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:51:31 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/06 12:51:31 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_index(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\n')
		return (-1);
	return (i);
}

int		get_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

int get_next_line(int fd, char **line)
{
    char            buff[BUFSIZ + 1];
    static char     *str = NULL;
    int             index;
    int             nbr_read;

    if (BUFSIZ < 0 || !line || fd < 0 || read(fd, buff, 0) < 0)
        return (-1);
    if (str && (((index = find_index(str)) != -1)))
		return (get_line(str, line, index));
	while (((nbr_read = read(fd, buff, BUFSIZ)) > 0))
	{
		buff[nbr_read] = '\0';
		str = ft_strjoin(str, buff);
		if (((index = find_index(str)) != -1))
			return (get_line(str, line, index));
	}
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (nbr_read);
	}
	*line = ft_strdup("");
	return (nbr_read);
}

int main()
{
    return (0);
}
