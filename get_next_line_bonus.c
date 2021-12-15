/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:43:05 by abaioumy          #+#    #+#             */
/*   Updated: 2021/12/15 19:45:21 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_pointers(char **ptr1, char **ptr2)
{
	if (*ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 == NULL)
		return ;
	if (*ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
}

char	*subfunc(char *s, char *substr, int start, int len)
{
	int	i;

	i = 0;
	while (s[start] && len)
	{
		substr[i++] = s[start++];
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;
	int		len1;

	i = 0;
	len1 = ft_strlen(s);
	substr = NULL;
	if (!s || !*s)
		return (0);
	if ((int)start > len1)
		return (ft_strdup(""));
	if (len1 == (int)len)
		substr = (char *)malloc(sizeof(char) * len - start + 1);
	else if (len1 + start >= len)
		substr = (char *)malloc(sizeof(char) * len + 1);
	else if (len1 + start < len)
		substr = (char *)malloc(sizeof(char) * len1 + 1);
	if (!substr)
		return (NULL);
	return (subfunc(s, substr, start, len));
}

char	*find_line(char **str)
{
	int		counter;
	char	*line;
	char	*temp;

	counter = 0;
	if (**str == '\0')
		return (NULL);
	while ((*str)[counter] && (*str)[counter] != '\n')
		counter++;
	line = ft_substr(*str, 0, counter + 1);
	if ((*str)[counter])
		temp = ft_substr(*str, counter + 1, 1000);
	else
		temp = ft_strdup("");
	free (*str);
	*str = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*str;
	static char	*saved[OPEN_MAX];
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = 1;
	while (i > 0 && !check_nl(saved[fd]))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free_pointers(&str, &saved[fd]);
			return (NULL);
		}
		str[i] = '\0';
		saved[fd] = ft_strjoin(&saved[fd], str);
	}
	line = find_line(&saved[fd]);
	free_pointers(&str, NULL);
	if (*saved[fd] == 0)
		free_pointers(&saved[fd], NULL);
	return (line);
}
