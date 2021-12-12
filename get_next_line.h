/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:18:09 by abaioumy          #+#    #+#             */
/*   Updated: 2021/12/12 20:58:31 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char    *ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_bzero(void *str, size_t n);
int     check_nl(char *saved);

#endif