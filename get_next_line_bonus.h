/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:44:41 by abaioumy          #+#    #+#             */
/*   Updated: 2021/12/15 19:05:39 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_strjoin(char **s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
int		check_nl(char *saved);
char	*get_next_line(int fd);
void	free_pointers(char **ptr1, char **ptr2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif