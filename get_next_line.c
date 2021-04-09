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

int	find_index(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		return (-1);
	return (i);
}

int	get_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

int	condition(char **line, char *str, int nbr_read)
{
	*line = ft_strdup(str);
	free(str);
	str = NULL;
	return (nbr_read);
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*str = NULL;
	int				nbr_read;

	if (BUFFER_SIZE < 0 || !line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	nbr_read = read(fd, buff, BUFFER_SIZE);
	while (nbr_read > 0)
	{
		buff[nbr_read] = '\0';
		str = ft_strjoin(str, buff);
		if (find_index(str) != -1)
			return (get_line(str, line, find_index(str)));
		nbr_read = read(fd, buff, BUFFER_SIZE);
	}
	buff[nbr_read] = '\0';
		str = ft_strjoin(str, buff);
	if (str)
		if (find_index(str) != 1)
			return (get_line(str, line, find_index(str)));
	if (str)
		return (condition(line, str, nbr_read));
	*line = ft_strdup("");
	return (nbr_read);
}

int main()
{
	int fd;
	char *line = NULL;
	int i = 0;

	fd = open("files/empty_lines", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("|%s\n", line);
	}
}