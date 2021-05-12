/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:55:41 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/05/12 11:19:14 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_line(char **line, char **str, int index)
{
	char	*save_str;

	save_str = ft_strdup(*str);
	free(*str);
	*line = ft_substr(save_str, 0, index);
	if (save_str[index + 1] == '\0')
		*str = NULL;
	else
		*str = ft_substr(save_str, index + 1, ft_strlen(save_str));
	free(save_str);
	return (1);
}

static int	ft_check(char *str)
{
	int	i ;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (NO_NL);
}

static void	ft_define_and_call(char **line, char **str)
{
	*line = ft_strdup(*str);
	ft_free_if_define(str);
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*str = NULL;
	int				nbr_read;
	int				index;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (str)
	{
		index = ft_check(str);
		if (index != NO_NL)
			return (ft_get_line(line, &str, index));
	}
	nbr_read = read(fd, buff, BUFFER_SIZE);
	while (nbr_read > 0)
	{
		buff[nbr_read] = '\0';
		str = ft_strjoin(&str, buff);
		index = ft_check(str);
		if (index != NO_NL)
			return (ft_get_line(line, &str, index));
		nbr_read = read(fd, buff, BUFFER_SIZE);
	}
	ft_define_and_call(line, &str);
	return (0);
}

int	main(void)
{
	int		fd;
	char	*line = NULL;
	int		get;

	fd = open("files/alphabet", O_RDONLY);
	get = get_next_line(fd, &line);
	while (get > 0)
	{
		printf("|%s\n", line);
		free(line);
		get = get_next_line(fd, &line);
	}
	printf("|%s\n", line);
	free(line);
	return (1);
}
