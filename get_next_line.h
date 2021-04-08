/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:14:05 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/06 15:14:05 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int         get_next_line(int fd, char **line);
size_t      ft_strlen(const char *s);
char        *ft_strdup(const char *s1);
void        *ft_memmove(void *dst, const void *src, size_t len);
char        *ft_substr(char const *s, int start, int len);
char        *ft_strjoin(char *s1, char *s2);

#endif